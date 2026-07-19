#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class PrimeChecker {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;
        }
        int maxDivisor = sqrt(n) + 1;
        for (int i = 3; i < maxDivisor; i ++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int reverseNumber(int n) {
        string numStr = to_string(n);
        reverse(numStr.begin(), numStr.end());
        return stoi(numStr);
    }

    string checkEmirp(int n) {
        if (!isPrime(n)) {
            return "not prime";
        }
        int reversedN = reverseNumber(n);
        if (reversedN != n && isPrime(reversedN)) {
            return "emirp";
        } else {
            return "prime";
        }
    }
};

int main() {
    PrimeChecker checker;
    int n;
    while (cin >> n) {
        string result = checker.checkEmirp(n);
        if (result == "not prime") {
            cout << n << " is not prime." << endl;
        } else if (result == "prime") {
            cout << n << " is prime." << endl;
        } else if (result == "emirp") {
            cout << n << " is emirp." << endl;
        }
    }
    return 0;
}
