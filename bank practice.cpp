#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class representing a bank account
class Account {
private:
    string number;
    string holderName;
    double balance;

public:
    // Constructor
    Account(string num, string name, double initialBalance) {
        number = num;
        holderName = name;
        balance = initialBalance;
    }

    // Deposit function
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << " successfully." << endl;
    }

    // Withdraw function
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully." << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    // Check balance function
    double checkBalance() {
        return balance;
    }
};

// Main function to demonstrate the banking system
int main() {
    // Create an account
    Account account("1234567890", "John Doe", 1000.0);

    // Perform transactions
    account.deposit(500);
    account.withdraw(200);
    account.withdraw(1500);

    // Check balance
    cout << "Current balance: $" << account.checkBalance() << endl;

    return 0;
}