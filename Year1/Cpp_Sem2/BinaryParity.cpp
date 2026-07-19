#include <iostream>
#include <string>
using namespace std;

class Calcul_of_Parity {
private:
    int number;

    string toBinary() {
         if (number == 0) return "0"; 
        
        string binary = "";
        int n = number; 

        while (n > 0) {
           binary = (n % 2 ? "1" : "0") + binary; 
           n /=2;
        }
        return binary;
    }

public:
    Calcul_of_Parity(int n) {
        number = n;
    }

    int getParity() {
        string binary = toBinary();
        int count = 0;
        for (char bit : binary) {
            if (bit == '1') 
                count++;
        }
        return count % 2;
    }
    int count_1s(){
        string binary = toBinary();
        int count = 0; 
        for (char bit : binary){
            if (bit == '1'){
            count++;
        }
    }
    return count;
}

    void printResult() {
        string binary = toBinary();
        int ones = count_1s();
        cout << "The parity of " << binary << " is " << ones << " (mod 2)." << endl;
    }
};

int main() {
    int User_Input;

    while (true) {
        cin >> User_Input;
        if (User_Input == 0) {
            break;
        }
        
        Calcul_of_Parity calc(User_Input);
        calc.printResult();
    }

    return 0;
}