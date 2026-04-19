#include <iostream>
#include <string>
using namespace std;

// Base Class
class Account {
protected:
    int accNo;
    string name;
    double balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;

        cout << "Enter Name: ";
        cin.ignore();                 // FIX: clear buffer
        getline(cin, name);           // FIX: full name input

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    virtual void deposit() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Amount Deposited Successfully!\n";
    }

    virtual void withdraw() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Account No: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}   // good practice
};

// Savings Account
class Savings : public Account {
public:
    void withdraw() override {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (balance - amount >= 500) {
            balance -= amount;
            cout << "Withdrawal Successful (Savings)\n";
        } else {
            cout << "Minimum balance of 500 required!\n";
        }
    }
};

// Current Account
class Current : public Account {
public:
    void withdraw() override {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= balance + 1000) {
            balance -= amount;
            cout << "Withdrawal Successful (Current with Overdraft)\n";
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }
};

// Main Function
int main() {
    int type, choice;

    cout << "Select Account Type:\n";
    cout << "1. Savings\n2. Current\nEnter choice: ";
    cin >> type;

    Account* acc;

    if (type == 1)
        acc = new Savings();
    else
        acc = new Current();

    acc->createAccount();

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: acc->deposit(); break;
            case 2: acc->withdraw(); break;
            case 3: acc->display(); break;
            case 4: cout << "Thank You!\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    delete acc;
    return 0;
}