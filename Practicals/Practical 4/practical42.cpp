#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue() {
    while (!empty()) {
        dequeueFront();
    }
}

bool Queue::empty() const {
    return front == nullptr;
}

void Queue::enqueue(int value) {
    Node* newNode = new Node{value, nullptr};

    if (empty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void Queue::dequeueFront() {
    if (empty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;
    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
}

void Queue::deleteByValue(int value) {
    if (empty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    if (front->token == value) {
        dequeueFront();
        return;
    }

    Node* prev = front;
    Node* curr = front->next;

    while (curr != nullptr && curr->token != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "Token not found in queue." << endl;
        return;
    }

    prev->next = curr->next;

    if (rear == curr) {
        rear = prev;
    }

    delete curr;
}

void Queue::displayForward() const {
    if (empty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue from front to rear: ";
    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->token;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

void Queue::displayReverse(Node* node) const {
    if (node == nullptr) {
        return;
    }

    displayReverse(node->next);
    cout << node->token << " ";
}

void Queue::printReverse() const {
    if (empty()) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue in reverse order: ";
    displayReverse(front);
    cout << endl;
}
