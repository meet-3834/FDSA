#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    void addBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        display();
    }

    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        display();
    }

    void insertAfter(string givenSong, string newSong) {
        Node* temp = head;

        while (temp != NULL && temp->song != givenSong) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Song \"" << givenSong << "\" not found." << endl;
            display();
            return;
        }

        Node* newNode = new Node(newSong);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL) {
            temp->next->prev = newNode;
        } else {
            tail = newNode;
        }

        temp->next = newNode;
        display();
    }

    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;
        display();
    }

    void countSongs() {
        int count = 0;
        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        cout << "Number of songs: " << count << endl;
    }

    void display() {
        Node* temp = head;

        cout << "Playlist: ";

        if (head == NULL) {
            cout << "Empty";
        }

        while (temp != NULL) {
            cout << temp->song;

            if (temp->next != NULL) {
                cout << " -> ";
            }

            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Playlist p;

    p.addBeginning("Song A");
    p.addEnd("Song B");
    p.addEnd("Song D");

    p.insertAfter("Song B", "Song C");
    p.countSongs();
    p.removeFirst();
    p.countSongs();
    p.insertAfter("Song X", "Song E");

    return 0;
}