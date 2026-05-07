#include <iostream>
using namespace std;


struct Node {
    int data;       
    Node* next;     
};


class SimpleList {
    Node* head; 

public:
    SimpleList() { head = nullptr; }

    void add(int value) {
        Node* newNode = new Node(); 
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) { 
                temp = temp->next;
            }
            temp->next = newNode; 
        }
        cout << "Inserted " << value << endl;
    }

    
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void update(int target, int newValue) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == target) {
                temp->data = newValue;
                cout << "Updated " << target << " to " << newValue << endl;
                return;
            }
            temp = temp->next;
        }
        cout << target << " not found!" << endl;
    }

    
    void remove(int value) {
        if (head == nullptr) return;

        
        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete; 
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next; 
            delete toDelete; 
            cout << "Deleted " << value << endl;
        }
    }
};


int main() {
    SimpleList myTable;

    myTable.add(10);     
    myTable.add(20);
    myTable.add(30);

    myTable.display();   

    myTable.update(20, 99); 
    myTable.display();

    myTable.remove(10);  
    myTable.display();

    return 0;
}