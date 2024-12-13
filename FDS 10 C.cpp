#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int seat;
    string id;
    int status;  // 0 for available, 1 for booked
    Node* next;
    Node* prev;
};

class Cinema {
public:
    Node* head;
    Node* tail;

    Cinema() {
        head = NULL; // Replace nullptr with NULL
        tail = NULL; // Replace nullptr with NULL
    }

    void createList();
    void display();
    void book();
    void cancel();
    void available();
};

void Cinema::createList() {
    for (int i = 1; i <= 70; ++i) {
        Node* newNode = new Node;
        newNode->seat = i;
        newNode->status = 0;  // 0 means available
        newNode->id = "null";
        
        if (!head) {
            head = tail = newNode;
            head->next = head->prev = head;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }
    }
}

void Cinema::display() {
    Node* temp = head;
    int count = 0;
    cout << "\n------------------------------------------------------------------------------------\n";
    cout << "Screen this way\n";
    cout << "------------------------------------------------------------------------------------\n";
    
    do {
        cout << (temp->seat < 10 ? "S0" : "S") << temp->seat << " :";
        cout << (temp->status == 0 ? "|___| " : "|_B_| ");
        count++;
        if (count % 7 == 0) {
            cout << endl;
        }
        temp = temp->next;
    } while (temp != head);
}

void Cinema::book() {
    int seatNumber;
    string userId;
    
    cout << "\nEnter seat number to book (1-70): ";
    cin >> seatNumber;
    cout << "Enter your ID: ";
    cin >> userId;

    if (seatNumber < 1 || seatNumber > 70) {
        cout << "Invalid seat number. Please enter a number between 1 and 70.\n";
        return;
    }

    Node* temp = head;
    while (temp->seat != seatNumber) {
        temp = temp->next;
    }

    if (temp->status == 1) {
        cout << "Seat already booked!\n";
    } else {
        temp->status = 1;
        temp->id = userId;
        cout << "Seat " << seatNumber << " booked!\n";
    }
}

void Cinema::cancel() {
    int seatNumber;
    string userId;
    
    cout << "Enter seat number to cancel booking: ";
    cin >> seatNumber;
    cout << "Enter your ID: ";
    cin >> userId;

    if (seatNumber < 1 || seatNumber > 70) {
        cout << "Invalid seat number. Please enter a number between 1 and 70.\n";
        return;
    }

    Node* temp = head;
    while (temp->seat != seatNumber) {
        temp = temp->next;
    }

    if (temp->status == 0) {
        cout << "Seat not booked yet!\n";
    } else if (temp->id == userId) {
        temp->status = 0;
        temp->id = "null";
        cout << "Seat " << seatNumber << " booking cancelled!\n";
    } else {
        cout << "Wrong User ID! Seat cannot be cancelled.\n";
    }
}

void Cinema::available() {
    Node* temp = head;
    int count = 0;

    cout << "\nAvailable seats:\n";
    do {
        if (temp->status == 0) {
            cout << (temp->seat < 10 ? "S0" : "S") << temp->seat << " ";
        }
        count++;
        if (count % 7 == 0) {
            cout << endl;
        }
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    Cinema cinema;
    cinema.createList();

    char choice = 'y';
    while (choice == 'y') {
        cinema.display();
        
        int option;
        cout << "\n*********************************************\n";
        cout << " CINEMAX MOVIE THEATRE\n";
        cout << "*********************************************\n";
        cout << "\nEnter Choice:\n";
        cout << "1. Current Seat Status\n";
        cout << "2. Book Seat\n";
        cout << "3. Available Seats\n";
        cout << "4. Cancel Seat\n";
        cin >> option;

        switch (option) {
            case 1:
                cinema.display();
                break;
            case 2:
                cinema.book();
                break;
            case 3:
                cinema.available();
                break;
            case 4:
                cinema.cancel();
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> choice;
    }

    return 0;
}

