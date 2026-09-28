#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrayStack {
private:
  vector<string> stack;
  int capacity;
  int top;

public:
  TrayStack(int n) {
    capacity = n;
    stack.resize(capacity);
    top = -1;
  }

  bool isFull() { return top == capacity - 1; }

  bool isEmpty() { return top == -1; }

  void placeTray(const string &trayID) {
    if (isFull()) {
      cout << "[Error] Stack Overflow: Cannot place tray '" << trayID
           << "'. Counter is full (Capacity: " << capacity << ").\n";
      return;
    }
    top++;
    stack[top] = trayID;
    cout << "Placed tray '" << trayID << "'. Current top tray: '" << stack[top]
         << "'\n";
  }

  void takeTray() {
    if (isEmpty()) {
      cout << "[Error] Stack Underflow: Cannot take tray. Counter is empty.\n";
      return;
    }
    string removedTray = stack[top];
    top--;
    cout << "Customer took tray '" << removedTray << "'. ";
    if (isEmpty()) {
      cout << "Counter is now empty (No top tray).\n";
    } else {
      cout << "Current top tray: '" << stack[top] << "'\n";
    }
  }

  // Display current status
  void displayTop() {
    if (isEmpty()) {
      cout << "Current Status: Counter is empty.\n";
    } else {
      cout << "Current Status: Top tray is '" << stack[top] << "'\n";
    }
  }
};

int main() {
  int n;
  cout << "Enter the maximum capacity of the tray counter (n): ";
  if (!(cin >> n) || n <= 0) {
    cout << "Invalid capacity. Exiting program.\n";
    return 1;
  }

  TrayStack counter(n);
  int choice;

  cout << "\n--- Fixed-Capacity Cafeteria Tray Counter ---\n";
  cout << "1. Place Tray (Push)\n";
  cout << "2. Take Tray (Pop)\n";
  cout << "3. Display Top Tray\n";
  cout << "4. Exit\n";

  do {
    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
      string trayID;
      cout << "Enter Tray ID/Name to place: ";
      cin >> trayID;
      counter.placeTray(trayID);
    } else if (choice == 2) {
      counter.takeTray();
    } else if (choice == 3) {
      counter.displayTop();
    } else if (choice == 4) {
      cout << "Exiting program.\n";
    } else {
      cout << "Invalid choice! Please try again.\n";
    }
  } while (choice != 4);

  return 0;
}
