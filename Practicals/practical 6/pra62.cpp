#include <iostream>
#include <string>

using namespace std;

struct Node {
  string page;
  Node *next;
};

class BrowserHistory {
private:
  Node *top;

public:
  BrowserHistory() { top = NULL; }

  bool isEmpty() { return (top == NULL); }

  void visit(string pageName) {
    Node *newNode = new Node();
    newNode->page = pageName;
    newNode->next = top;
    top = newNode;

    cout << "Visited: " << top->page << endl;
    cout << "Current Page: " << top->page << endl;
  }

  void back() {
    if (isEmpty()) {
      cout << "Cannot go back! No history left. You are on the starting page."
           << endl;
      return;
    }

    Node *temp = top;
    top = top->next;
    cout << "Pressed BACK. Left page: " << temp->page << endl;
    delete temp; // Free dynamically allocated memory

    if (isEmpty()) {
      cout << "Current Page: [Home / Blank Page (No history left)]" << endl;
    } else {
      cout << "Current Page: " << top->page << endl;
    }
  }

  void showCurrent() {
    if (isEmpty()) {
      cout << "Current Page: [Home / Blank Page]" << endl;
    } else {
      cout << "Current Page: " << top->page << endl;
    }
  }

  ~BrowserHistory() {
    while (!isEmpty()) {
      Node *temp = top;
      top = top->next;
      delete temp;
    }
  }
};

int main() {
  BrowserHistory browser;
  int choice;
  string pageName;

  cout << "=== Web Browser History (Unlimited Stack) ===" << endl;
  cout << "1. Visit New Page" << endl;
  cout << "2. Press Back" << endl;
  cout << "3. Display Current Page" << endl;
  cout << "4. Exit" << endl;

  while (true) {
    cout << "\nEnter choice (1-4): ";
    if (!(cin >> choice))
      break;

    if (choice == 1) {
      cout << "Enter page name/URL: ";
      cin >> pageName;
      browser.visit(pageName);
    } else if (choice == 2) {
      browser.back();
    } else if (choice == 3) {
      browser.showCurrent();
    } else if (choice == 4) {
      cout << "Exiting program." << endl;
      break;
    } else {
      cout << "Invalid choice! Enter 1, 2, 3, or 4." << endl;
    }
  }

  return 0;
}
