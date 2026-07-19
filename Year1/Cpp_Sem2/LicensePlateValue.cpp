#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class LicensePlate {
private:
    string plateStr;
    string lettersPart;
    string digitsPart;

public:
    LicensePlate(const string& plate) {
        plateStr = plate;
        lettersPart = plate.substr(0, 3);
        digitsPart = plate.substr(4, 4);
    }

    int calculateLettersValue() {
        int total = 0;
        for (int i = 0; i < 3; ++i) {
            char c = lettersPart[2 - i];
            int value = c - 'A';
            total += value * pow(26, i);
        }
        return total;
    }

    int calculateDigitsValue() {
        return stoi(digitsPart);
    }

    bool isNice() {
        int lettersVal = calculateLettersValue();
        int digitsVal = calculateDigitsValue();
        return abs(lettersVal - digitsVal) <= 100;
    }
};

int main() {
    int N;
    cin >> N;
    cin.ignore(); 
    for (int i = 0; i < N; ++i) {
        string plateStr;
        getline(cin, plateStr);
        LicensePlate plate(plateStr);
        if (plate.isNice()) {
            cout << "nice" << endl;
        } else {
            cout << "not nice" << endl;
        }
    }

    return 0;
}