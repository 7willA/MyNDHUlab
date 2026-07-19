
#include <iostream>
using namespace std;

enum NumberType { notPrime, Prime, Emirp };

class EmirpChecker {
private:
    int originalNum;
    int reversedNum;

    int reverseNumber(int num) const {
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
    }

    bool isPrime(int num) const {
        if (num < 2) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

public:
    
    EmirpChecker(int num) : originalNum(num), reversedNum(reverseNumber(num)) {}

   
    NumberType classifyNumber() const {
        if (!isPrime(originalNum)) return notPrime;
        if (originalNum != reversedNum && isPrime(reversedNum)) return Emirp;
        return Prime;
    }

    int getOriginal() const { return originalNum; }
    int getReversed() const { return reversedNum; }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    EmirpChecker checker(n);
    NumberType result = checker.classifyNumber();

    if (result == Emirp) {
        cout << n << " is emirp." << endl;
    }
    else if (result == Prime) { cout << n << " is prime." <<endl;
    } 
    else {
        cout << n << " is not prime." <<endl;
    }

    return 0;
}




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
            char c = lettersPart[2 - i]; // Process from right to left
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
    cin.ignore(); // To ignore the newline after reading N

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