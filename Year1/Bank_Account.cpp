#include <iostream>
#include <string>

using namespace std;

// Class to manage a bank account
class BankAccount {
private:
    int balance; // Stores the current balance

public:
    // Constructor to set the initial balance
    BankAccount(int init_Balance) {
        balance = init_Balance;
    }

    // Function to add money
    void deposit(int amount) {
        balance += amount;
    }

    // Function to take out money
    void withdraw(int amount) {
        balance -= amount;
    }

    // Function to check the current balance
    int getBalance() {
        return balance;
    }
};

int main() {
    int balance, n;
    // Read the starting balance and the number of transactions
    cin >> balance >> n;

    // Create a bank account object with the starting balance
    BankAccount account(balance);

    // Process each transaction one by one
    for (int i = 0; i < n; i++) {
        string command;
        int amount;
        cin >> command >> amount; // Read transaction type and money amount

        // Perform deposit or withdrawal based on the command
        if (command == "deposit") {
            account.deposit(amount);
        } else if (command == "withdraw") {
            account.withdraw(amount);
        }
    }

    // Print the final closing balance
    cout << "Balance: " << account.getBalance() << endl;

    return 0;
}
