#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
  int balance;
public:
  BankAccount(int m) : balance(m) {}
  int &getBalance() {
    return balance;
  }
};

int main() {
  int b;
  cin >> b;
  BankAccount account(b);

  while (true) {
    string command;
    cin >> command;

    if (command == "withdraw") {
      int temp;
      cin >> temp;
      account.getBalance() -= temp;
    }
    else if (command == "deposit") {
      int temp;
      cin >> temp;
      account.getBalance() += temp; 
    }
    else if (command == "balance") {
      cout << account.getBalance() << endl;
    }
    else if (command == "exit") {
      break;
    }
  }
}