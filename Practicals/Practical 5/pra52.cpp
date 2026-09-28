#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = NULL;
    }
};

class CircularList {
private:
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    void insertBeginning(string name) {
        Node* newNode = new Node(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        display();
    }

    void insertEnd(string name) {
        Node* newNode = new Node(name);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        }
        else {
            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
        display();
    }

    void insertAfter(string student, string newStudent) {
        if (head == NULL) {
            cout << "Circle is empty." << endl;
            return;
        }
        Node* temp = head;

        do {
            if (temp->name == student) {
                Node* newNode = new Node(newStudent);

                newNode->next = temp->next;
                temp->next = newNode;

                display();
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << student << " not found." << endl;
        display();
    }

    void deleteStudent(string name) {
        if (head == NULL) {
            cout << "Circle is empty." << endl;
            return;
        }
        if (head->name == name && head->next == head) {
            delete head;
            head = NULL;

            display();
            return;
        }
        if (head->name == name) {
            Node* last = head;

            while (last->next != head) {
                last = last->next;
            }

            Node* temp = head;
            head = head->next;
            last->next = head;

            delete temp;

            display();
            return;
        }

        Node* temp = head;

        while (temp->next != head &&
               temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next == head) {
            cout << name << " not found." << endl;
        }
        else {
            Node* deleteNode = temp->next;
            temp->next = deleteNode->next;

            delete deleteNode;
        }
        display();
    }

    void display() {
        if (head == NULL) {
            cout << "Circle: Empty" << endl;
            return;
        }

        Node* temp = head;
        cout << "Circle: ";

        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to " << head->name << ")" << endl;
    }
};

int main() {
    CircularList students;

    students.insertEnd("A");
    students.insertEnd("B");
    students.insertEnd("C");
    students.insertBeginning("D");
    students.insertAfter("B", "E");
    students.deleteStudent("C");
    students.deleteStudent("D");
    students.deleteStudent("X");
    return 0;
}