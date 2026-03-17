#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "1. Print characters\n";
    cout << "2. Count digits\n";
    cout << "3. Sum of first and last digit\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        char ch = 'a';
        do {
            cout << ch << " ";
            ch = ch + 4;
        } while (ch <= 'z');
    }

    else if (choice == 2) {
        int num, count = 0;
        cout << "Enter Number: ";
        cin >> num;

        do {
            count++;
            num = num / 10;
        } while (num != 0);

        cout << "Digits = " << count;
    }

    else if (choice == 3) {
        int num, first, last;
        cout << "Enter Number: ";
        cin >> num;

        last = num % 10;

        while (num >= 10) {
            num = num / 10;
        }

        first = num;

        cout << "Sum = " << first + last;
    }

    else {
        cout << "Invalid choice!";
    }

    return 0;
}