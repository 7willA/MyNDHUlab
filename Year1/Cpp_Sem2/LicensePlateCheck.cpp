#include <iostream>
#include <string>
using namespace std;

class CheckLicense {
private:
    string digits;
public:
    CheckLicense(string d) : digits(d) {}
    bool has4() {
        for (char c : digits) {
            if (c == '4') {
                return true;
            }
        }
        return false;
    }
};
int main() {
    string digits;
    cin >> digits;
    CheckLicense check(digits);
    cout << (check.has4() ? "Yes" : "No") << endl;
    return 0;
}