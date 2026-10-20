#include "Queue.h"
#include <iostream>
using namespace std;

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Original queue" << endl;
    q.displayForward();

    cout << "\nDelete token 30" << endl;
    q.deleteByValue(30);
    q.displayForward();

    cout << "\nDelete front token" << endl;
    q.dequeueFront();
    q.displayForward();

    cout << "\nReverse print" << endl;
    q.printReverse();

    return 0;
}
