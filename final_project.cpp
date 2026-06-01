#include <iostream>
using namespace std;


struct Node
{
    int id;
    Node* next;
};


Node* head = NULL;


void insert(int id)
{
    Node* newNode = new Node();
    newNode->id = id;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void displayList()
{
    Node* temp = head;

    cout << "\nStudent IDs in Linked List:\n";

    while(temp != NULL)
    {
        cout << temp->id << " ";
        temp = temp->next;
    }
    cout << endl;
}


void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[50], R[50];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for(int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1)
        arr[k++] = L[i++];

    while(j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}


void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}


void displayArray(int arr[], int n)
{
    cout << "\nArray Elements:\n";

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[50];
    int n, choice, key;

    cout << "Enter Number of Student IDs: ";
    cin >> n;

    cout << "Enter Student IDs:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        insert(arr[i]);
    }

    do
    {
        cout << "\nMENU\n";
        cout << "1. Display Linked List\n";
        cout << "2. Merge Sort\n";
        cout << "3. Quick Sort\n";
        cout << "4. Binary Search\n";
        cout << "5. Display Array\n";
    

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayList();
                break;

            case 2:
                mergeSort(arr, 0, n - 1);
                cout << "\nSorted Using Merge Sort\n";
                displayArray(arr, n);
                break;

            case 3:
                quickSort(arr, 0, n - 1);
                cout << "\nSorted Using Quick Sort\n";
                displayArray(arr, n);
                break;

            case 4:
                cout << "Enter ID to Search: ";
                cin >> key;

                {
                    int pos = binarySearch(arr, n, key);

                    if(pos != -1)
                        cout << "ID Found at Position: " << pos + 1 << endl;
                    else
                        cout << "ID Not Found" << endl;
                }
                break;

            case 5:
                displayArray(arr, n);
                break;

            case 6:
                cout << "Program Ended" << endl;
                break;

            default:
                cout << "Invalid Choice" << endl;
        }

    } while(choice != 6);

    return 0;
}