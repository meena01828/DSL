#include <iostream>
#define MAX 10
using namespace std;

class Queue {
    int data[MAX];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full! Cannot insert.\n";
        } else {
            data[++rear] = x;
            cout << x << " added to the queue.\n";
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot delete.\n";
        } else {
            cout << "Deleted: " << data[++front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Queue contains: ";
            for (int i = front + 1; i <= rear; ++i) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue queue;
    int choice, x;

    do {
        cout << "\n1. Insert Job\n2. Delete Job\n3. Display Queue\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data to insert: ";
            cin >> x;
            queue.enqueue(x);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.display();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
