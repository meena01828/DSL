#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int no;        
    int start, end;  
    bool status;    
    node* prev;     
    node* next;     
    
    node() : no(0), start(0), end(0), status(0), prev(NULL), next(NULL) {}
};


class appt {
protected:
    node* head;  
    node* tail;  
public:
    appt() : head(NULL), tail(NULL) {}

    void create(int n, int t);   
    void display();              
    void book(int n);         
    void cancel(int n);        
};


void appt::create(int n, int t) {
    node* temp = NULL;
    for (int i = 0; i < n; ++i) {
        node* curr = new node;
        curr->no = i + 1;
        curr->start = (i == 0) ? 0 : temp->end;
        curr->end = curr->start + (60 / n);  
        curr->status = false;

        if (head == NULL) {
            head = curr;
        } else {
            temp->next = curr;
            curr->prev = temp;
        }
        temp = curr;
    }
    tail = temp;
}


void appt::display() {
    node* curr = head;
    cout << "\nNo.\tTime\t\tStatus\n";
    cout << "--------------------------------------\n";
    while (curr != NULL) {
        cout << curr->no << "\t" << curr->start << "-" << curr->end
             << "\t\t" << (curr->status ? "Booked" : "Free") << endl;
        curr = curr->next;
    }
}


void appt::book(int n) {
    node* curr = head;
    while (curr != NULL) {
        if (curr->no == n && !curr->status) {
            curr->status = true;
            cout << "Appointment " << n << " is now booked.\n";
            return;
        }
        curr = curr->next;
    }
    cout << "Invalid appointment number or already booked.\n";
}


void appt::cancel(int n) {
    node* curr = head;
    while (curr != NULL) {
        if (curr->no == n && curr->status) {
            curr->status = false;
            cout << "Appointment " << n << " has been canceled.\n";
            return;
        }
        curr = curr->next;
    }
    cout << "Invalid appointment number or not booked.\n";
}

int main() {
    appt a;
    int choice, slots, time, appt_no;

    do {
        cout << "\n1. Create schedule\n2. Display schedule\n3. Book appointment\n4. Cancel appointment\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
 {
            case 1:
                cout << "Enter total time (e.g., 9 for 9 AM): ";
                cin >> time;
                cout << "Enter number of appointment slots: ";
                cin >> slots;
                a.create(slots, time);
                break;
            case 2:
                a.display();
                break;
            case 3:
                a.display();
                cout << "Enter appointment number to book: ";
                cin >> appt_no;
                a.book(appt_no);
                break;
            case 4:
                a.display();
                cout << "Enter appointment number to cancel: ";
                cin >> appt_no;
                a.cancel(appt_no);
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } 
while (choice != 5);

    return 0;
}


