#include<iostream>
using namespace std;

struct Node {
    int token;
    Node *next;
};

class PatientQueue {
    Node *front;
    Node *rear;
    int nextToken;

public:
    PatientQueue() {
        front = NULL;
        rear = NULL;
        nextToken = 1;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void arrive() {
        Node *newNode = new Node();
        newNode->token = nextToken;
        newNode->next = NULL;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Patient " << nextToken << " arrived." << endl;
        nextToken++;
        printFront();
    }

    void attend() {
        if (isEmpty()) {
            cout << "Error: Ward is empty. No patients to attend." << endl;
            return;
        }

        cout << "Patient " << front->token << " attended." << endl;
        Node *temp = front;
        front = front->next;

        if (front == NULL)   
            rear = NULL;

        delete temp;
        printFront();
    }

    void printFront() {
        if (isEmpty())
            cout << "Queue is empty. No front patient." << endl;
        else
            cout << "Current front patient: " << front->token << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Patients in queue (front -> rear): ";
        Node *temp = front;
        while (temp != NULL) {
            cout << temp->token;
            if (temp->next != NULL) cout << " <- ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    PatientQueue q;
    int choice;
    do {
        cout << "\n--- Hospital Emergency Ward ---" << endl;
        cout << "1. Arrive  (New patient)" << endl;
        cout << "2. Attend  (Serve front patient)" << endl;
        cout << "3. Display all patients" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: q.arrive(); break;
            case 2: q.attend(); break;
            case 3: q.display(); break;
            case 4: cout << "Exiting." << endl; break;
            default: cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
