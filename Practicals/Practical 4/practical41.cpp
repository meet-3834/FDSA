#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

struct node {
  int token;
  struct node *next;
};

struct node *head = NULL;

void InsertAtBeg(int token) {
  struct node *newnode = new struct node();
  newnode->token = token;
  newnode->next = head;
  head = newnode;
}

void InsertAtPOS(int POS, int token) {
  if (POS <= 1 || head == NULL) {
    InsertAtBeg(token);
    return;
  }

  struct node *newnode = new struct node();
  newnode->token = token;
  newnode->next = NULL;

  struct node *temp = head;
  for (int i = 1; i < POS - 1 && temp->next != NULL; i++) {
    temp = temp->next;
  }

  newnode->next = temp->next;
  temp->next = newnode;
}

void InsertAtEnd(int val) {
  struct node *newnode = new struct node();
  newnode->token = val;
  newnode->next = NULL;

  if (head == NULL) {
    head = newnode;
    return;
  }

  struct node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = newnode;
}

void print() {
  struct node *temp = head;
  while (temp != NULL) {
    cout << temp->token << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

int main() {
  string choice;

  cout << "enter BEG if you want to insert token at beggining" << endl;
  cout << "enter END if you want to insert token at end" << endl;
  cout << "enter POS if you want to insert token at position" << endl;
  cout << "enter PRINT if you want to print the token" << endl;
  cout << "enter EXIT/no if you want to exit" << endl;

  while (true) {
    cin >> choice;

    if (choice == "BEG") {
      int val;
      cout << "enter token number:" << endl;
      cin >> val;
      InsertAtBeg(val);
    } else if (choice == "END") {
      int val;
      cout << "enter token number:" << endl;
      cin >> val;
      InsertAtEnd(val);
    } else if (choice == "POS") {
      int position, val;
      cout << "enter position:" << endl;
      cin >> position;
      cout << "enter token number:" << endl;
      cin >> val;
      InsertAtPOS(position, val);
    } else if (choice == "PRINT") {
      print();
    } else if (choice == "EXIT" || choice == "no" || choice == "NO") {
      break;
    } else {
      cout << "Invalid choice" << endl;
    }
  }

  return 0;
}