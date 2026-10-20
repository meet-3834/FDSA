#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    int token;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

    void displayReverse(Node* node) const;

public:
    Queue();
    ~Queue();

    bool empty() const;
    void enqueue(int value);
    void dequeueFront();
    void deleteByValue(int value);
    void displayForward() const;
    void printReverse() const;
};

#endif
