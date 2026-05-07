#include <iostream>
using namespace std;

int main() {
    int choice;
    double num, result = 0;

    cout << "===== Memory Calculator =====" << endl;

    do {
        cout << "\n1. Add to Memory";
        cout << "\n2. Subtract from Memory";
        cout << "\n3. Multiply Memory";
        cout << "\n4. Divide Memory";
        cout << "\n5. Show Memory";
        cout << "\n6. Clear Memory";
        cout << "\n0. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                cout << "Enter number: ";
                cin >> num;
                result = result + num;
                cout << "Memory = " << result << endl;
                break;

            case 2:
                cout << "Enter number: ";
                cin >> num;
                result = result - num;
                cout << "Memory = " << result << endl;
                break;

            case 3:
                cout << "Enter number: ";
                cin >> num;
                result = result * num;
                cout << "Memory = " << result << endl;
                break;

            case 4:
                cout << "Enter number: ";
                cin >> num;

                if(num != 0) {
                    result = result / num;
                    cout << "Memory = " << result << endl;
                } else {
                    cout << "Cannot divide by zero!" << endl;
                }
                break;

            case 5:
                cout << "Current Memory = " << result << endl;
                break;

            case 6:
                result = 0;
                cout << "Memory Cleared!" << endl;
                break;

            case 0:
                cout << "Calculator Closed!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while(choice != 0);

    return 0;
}