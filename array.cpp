#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "1. 1D Array (Sum)\n";
    cout << "2. 2D Array (Matrix)\n";
    cout << "Enter choice: ";
    cin >> choice;

    // -------- 1D ARRAY --------
    if (choice == 1) {
        int n, sum = 0;

        cout << "Enter size: ";
        cin >> n;

        int arr[50];

        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        cout << "Sum = " << sum;
    }

    // -------- 2D ARRAY --------
    else if (choice == 2) {
        int r, c;

        cout << "Enter rows and columns: ";
        cin >> r >> c;

        int a[10][10];

        cout << "Enter matrix:\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> a[i][j];
            }
        }

        cout << "Matrix is:\n";
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    else {
        cout << "Invalid choice!";
    }

    return 0;
}