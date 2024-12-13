#include <iostream>
#include <string>
using namespace std;

class Node {
    int prn;
    string name;
    Node* next;

public:
    Node(int x, string nm) : prn(x), name(nm) { next = NULL; }
    friend class List;
};

class List {
    Node* head;

public:
    List() : head(NULL) {}

    void create() {
        if (head) {
            cout << "List already exists.\n";
            return;
        }
        int no;
        string nam;
        cout << "Enter President PRN and name: ";
        cin >> no >> nam;
        head = new Node(no, nam);
        cout << "List created with President.\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "List Members:\n";
        while (temp) {
            cout << temp->prn << " - " << temp->name << endl;
            temp = temp->next;
        }
    }

    void insertAtStart() {
        int no;
        string nam;
        cout << "Enter President PRN and name: ";
        cin >> no >> nam;
        Node* newNode = new Node(no, nam);
        newNode->next = head;
        head = newNode;
        cout << "President added.\n";
    }

    void insertAtEnd() {
        if (!head) {
            create();
            return;
        }
        int no;
        string nam;
        cout << "Enter Secretary PRN and name: ";
        cin >> no >> nam;
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new Node(no, nam);
        cout << "Secretary added.\n";
    }

    void deleteAtStart() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "President removed.\n";
    }

    void deleteAtEnd() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = NULL;
            cout << "Secretary removed.\n";
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
        cout << "Secretary removed.\n";
    }

    int countMembers() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    List list;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create List\n";
        cout << "2. Display List\n";
        cout << "3. Add President\n";
        cout << "4. Add Secretary\n";
        cout << "5. Remove President\n";
        cout << "6. Remove Secretary\n";
        cout << "7. Count Members\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.create();
                break;
            case 2:
                list.display();
                break;
            case 3:
                list.insertAtStart();
                break;
            case 4:
                list.insertAtEnd();
                break;
            case 5:
                list.deleteAtStart();
                break;
            case 6:
                list.deleteAtEnd();
                break;
            case 7:
                cout << "Total Members: " << list.countMembers() << endl;
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

