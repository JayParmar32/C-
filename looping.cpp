#include <iostream>
using namespace std;

int main() {
    int p, n;

    do {
        cout << "\n===== PATTERN MENU =====\n";
        cout << "1. Star Triangle\n";
        cout << "2. Inverted Triangle\n";
        cout << "3. Number Triangle\n";
        cout << "4. Pyramid\n";
        cout << "5. Floyd Triangle\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> p;

        if (p == 6) break;

        cout << "Enter number of rows: ";
        cin >> n;

        if (p == 1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << "* ";
                }
                cout << endl;
            }
        }

        else if (p == 2) {
            for (int i = n; i >= 1; i--) {
                for (int j = 1; j <= i; j++) {
                    cout << "* ";
                }
                cout << endl;
            }
        }

        else if (p == 3) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << j << " ";
                }
                cout << endl;
            }
        }

        else if (p == 4) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n - i; j++) {
                    cout << " ";
                }
                for (int k = 1; k <= (2 * i - 1); k++) {
                    cout << "*";
                }
                cout << endl;
            }
        }

        else if (p == 5) {
            int num = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    cout << num << " ";
                    num++;
                }
                cout << endl;
            }
        }

        else {
            cout << "Invalid choice\n";
        }

    } while (true);

    return 0;
}