#include <iostream>
using namespace std;


void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n)
{
    int minIndex, temp;

    for(int i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Array Sorted Using Selection Sort:\n";
    display(arr, n);
}
    void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[100], R[100];

    for(int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


int linearSearch(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[100], n, choice, key, result;

    cout << "Enter Number of Elements: ";
    cin >> n;

    cout << "Enter Elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    do
    {
        cout << "\nMENu\n";
        cout << "1. Selection Sort\n";
        cout << "2. Merge Sort\n";
        cout << "3. Linear Search\n";
        cout << "4. Binary Search\n";
        cout << "5. Display Array\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                selectionSort(arr, n);
                break;

            case 2:
                mergeSort(arr, 0, n - 1);
                cout << "Array Sorted Using Merge Sort:\n";
                display(arr, n);
                break;

            case 3:
                cout << "Enter Element to Search: ";
                cin >> key;

                result = linearSearch(arr, n, key);

                if(result != -1)
                    cout << "Element Found at Position " << result + 1 << endl;
                else
                    cout << "Element Not Found\n";
                break;

            case 4:
                cout << "Enter Element to Search: ";
                cin >> key;

                result = binarySearch(arr, n, key);

                if(result != -1)
                    cout << "Element Found at Position " << result + 1 << endl;
                else
                    cout << "Element Not Found\n";
                break;

            case 5:
                cout << "Array Elements:\n";
                display(arr, n);
                break;
            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}