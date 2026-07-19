#include <windows.h>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include <algorithm>

typedef int  (__cdecl *SortFn)(int*, int);
typedef int  (__cdecl *LimitedFn)(int*, int, unsigned int);
typedef void (__cdecl *SetupFn)(unsigned int);

struct Api {
    HMODULE dll = nullptr;
    SortFn algoA = nullptr;
    LimitedFn algoB = nullptr;
    SortFn algoC = nullptr;
    SortFn algoD = nullptr;
    SetupFn setup = nullptr;
};

bool LoadApi(const std::wstring& dllPath, Api& api) {
    api.dll = LoadLibraryW(dllPath.c_str());
    if (!api.dll) return false;

    api.algoA = reinterpret_cast<SortFn>(GetProcAddress(api.dll, "AlgoA"));
    api.algoB = reinterpret_cast<LimitedFn>(GetProcAddress(api.dll, "AlgoB"));
    api.algoC = reinterpret_cast<SortFn>(GetProcAddress(api.dll, "AlgoC"));
    api.algoD = reinterpret_cast<SortFn>(GetProcAddress(api.dll, "AlgoD"));
    api.setup = reinterpret_cast<SetupFn>(GetProcAddress(api.dll, "Setup"));

    return api.algoA && api.algoB && api.algoC && api.algoD && api.setup;
}

std::vector<int> MakeRandomData(int n, int seed) {
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(1, 1000000);
    std::vector<int> data(n);
    for (int& x : data) x = dist(rng);
    return data;
}

std::vector<int> MakeSortedData(int n) {
    std::vector<int> data(n);
    for (int i = 0; i < n; ++i) data[i] = i;
    return data;
}

std::vector<int> MakeReverseData(int n) {
    std::vector<int> data(n);
    for (int i = 0; i < n; ++i) data[i] = n - i;
    return data;
}

std::vector<int> MakeNearlySortedData(int n, int seed = 99) {
    std::vector<int> data = MakeSortedData(n);
    std::mt19937 rng(seed);
    int swaps = std::max(1, n / 100);
    std::uniform_int_distribution<int> pick(0, n - 2);
    for (int i = 0; i < swaps; ++i) {
        int idx = pick(rng);
        std::swap(data[idx], data[idx + 1]);
    }
    return data;
}

std::vector<int> MakeDuplicatesData(int n, int seed = 7) {
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(1, 10);
    std::vector<int> data(n);
    for (int& x : data) x = dist(rng);
    return data;
}

double MeasureMs(const std::vector<int>& source, SortFn fn) {
    std::vector<int> data = source;
    auto start = std::chrono::high_resolution_clock::now();
    int rc = fn(data.data(), static_cast<int>(data.size()));
    auto end = std::chrono::high_resolution_clock::now();
    if (rc != 0) throw std::runtime_error("routine returned non-zero status");
    return std::chrono::duration<double, std::milli>(end - start).count();
}

double MeasureLimitedMs(const std::vector<int>& source, LimitedFn fn, unsigned int limit, bool& success) {
    std::vector<int> data = source;
    auto start = std::chrono::high_resolution_clock::now();
    int rc = fn(data.data(), static_cast<int>(data.size()), limit);
    auto end = std::chrono::high_resolution_clock::now();
    success = (rc == 0);
    return std::chrono::duration<double, std::milli>(end - start).count();
}

double AverageMs(const std::vector<int>& source, SortFn fn, int repeats = 5) {
    double total = 0.0;
    for (int i = 0; i < repeats; ++i) {
        try {
            total += MeasureMs(source, fn);
        } catch (const std::exception& e) {
            std::cerr << "Warning: " << e.what() << "\n";
            return -1.0;
        }
    }
    return total / repeats;
}

int main() {
    Api api;
    if (!LoadApi(L"blackbox.dll", api)) {
        std::cerr << "Failed to load blackbox.dll\n";
        return 1;
    }

    std::ofstream csv("benchmark_result.csv");
    csv << "dataset,n,algo,time_ms,success\n";

    std::cout << "\nAlgoB demo (very small N only)\n";
    for (int nb : {4, 15, 20, 50, 80}) {
        for (const std::string& pat : {"random", "sorted", "reverse", "nearly_sorted", "many_duplicates"}) {
            std::vector<int> tiny;
            if      (pat == "random")          tiny = MakeRandomData(nb, 777);
            else if (pat == "sorted")          tiny = MakeSortedData(nb);
            else if (pat == "reverse")         tiny = MakeReverseData(nb);
            else if (pat == "nearly_sorted")   tiny = MakeNearlySortedData(nb);
            else if (pat == "many_duplicates") tiny = MakeDuplicatesData(nb);

            api.setup(123456789u);
            bool success = false;
            double tB = MeasureLimitedMs(tiny, api.algoB, 500000u, success);
            std::cout << pat << "  N=" << nb << "  B=" << tB << " ms  success=" << (success ? "true" : "false") << "\n";
            csv << pat << "," << nb << ",B," << tB << ',' << (success ? 1 : 0) << "\n";
            csv.flush();
        }
    }

    std::cout << std::fixed << std::setprecision(3);
    std::vector<int> sizes = {100, 300, 600, 1500, 3000, 5000, 15000, 25000};
    const int REPEATS = 5;

    for (int n : sizes) {
        std::vector<std::pair<std::string, std::vector<int>>> datasets = {
            {"random",          MakeRandomData      (n, 1000 + n)},
            {"sorted",          MakeSortedData      (n)},
            {"reverse",         MakeReverseData     (n)},
            {"nearly_sorted",   MakeNearlySortedData(n)},
            {"many_duplicates", MakeDuplicatesData  (n)},
        };

        for (const auto& item : datasets) {
            const std::string& name = item.first;
            const auto& data = item.second;

            double tA = AverageMs(data, api.algoA, REPEATS);
            double tC = AverageMs(data, api.algoC, REPEATS);
            double tD = AverageMs(data, api.algoD, REPEATS);

            std::cout << name << "  N=" << n
                      << "  A=" << tA
                      << " ms  C=" << tC
                      << " ms  D=" << tD << " ms\n";

            csv << name << ',' << n << ",A," << tA << ",1\n";
            csv << name << ',' << n << ",C," << tC << ",1\n";
            csv << name << ',' << n << ",D," << tD << ",1\n";
            csv.flush();
        }
    }

    csv.close();
    FreeLibrary(api.dll);
    return 0;
}