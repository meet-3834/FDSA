/*
 * Practical 7 - Problem 1
 * Government Office Token Counter using Circular Queue (Array-based)
 *
 * A circular queue of fixed capacity n is used. Two pointers track state:
 *   - front: index of the element to be served next
 *   - rear : index of the last element that was added
 *
 * Why circular?
 *   With a plain linear queue, front and rear both move forward on every
 *   join/serve. After n operations the array "appears" full even though
 *   earlier slots have been freed. A circular queue wraps the pointers
 *   using modulo arithmetic (rear = (rear+1) % n), so freed slots are
 *   reused and the queue only reports "full" when it genuinely holds n
 *   elements.
 */

#include <iostream>
using namespace std;

class TokenQueue {
    int *arr;       // dynamically allocated array
    int front;      // index of the front element (-1 when empty)
    int rear;       // index of the rear  element (-1 when empty)
    int capacity;   // maximum number of tokens the counter can hold
    int count;      // current number of tokens in the queue
    int nextToken;  // auto-incrementing token number

public:
    // Constructor: allocate array and initialise pointers
    TokenQueue(int n) {
        capacity = n;
        arr = new int[capacity];
        front = -1;
        rear  = -1;
        count = 0;
        nextToken = 1;  // tokens start from 1
    }

    // Destructor: free heap memory
    ~TokenQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    // Issue a new token (enqueue)
    void join() {
        if (isFull()) {
            cout << "Error: Counter is full. Cannot issue new token." << endl;
            return;
        }

        if (isEmpty()) {
            // First element — reset both pointers to 0
            front = 0;
            rear  = 0;
        } else {
            // Wrap around using modulo arithmetic
            rear = (rear + 1) % capacity;
        }

        arr[rear] = nextToken;
        count++;
        cout << "Token " << nextToken << " issued." << endl;
        nextToken++;
        printFront();
    }

    // Serve the visitor at the front (dequeue)
    void serve() {
        if (isEmpty()) {
            cout << "Error: Counter is empty. No one to serve." << endl;
            return;
        }

        cout << "Token " << arr[front] << " served." << endl;
        count--;

        if (isEmpty()) {
            // Queue became empty — reset pointers
            front = -1;
            rear  = -1;
        } else {
            // Advance front, wrapping around
            front = (front + 1) % capacity;
        }

        printFront();
    }

    // Display the current front token
    void printFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front token." << endl;
        } else {
            cout << "Current front token: " << arr[front] << endl;
        }
    }

    // Display all tokens currently in the queue (front to rear)
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Tokens in queue (front -> rear): ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % capacity];
            if (i < count - 1) cout << " <- ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter maximum capacity of the token counter: ";
    cin >> n;

    TokenQueue q(n);

    int choice;
    do {
        cout << "\n--- Token Counter Menu ---" << endl;
        cout << "1. Join  (Issue new token)" << endl;
        cout << "2. Serve (Serve front visitor)" << endl;
        cout << "3. Display all tokens" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                q.join();
                break;
            case 2:
                q.serve();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
