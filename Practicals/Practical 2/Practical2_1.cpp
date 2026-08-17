#include <iostream>
#include <string>
using namespace std;
int searchIterative(string plates[], int size, string target) {
    for (int i = 0; i < size; i++) {
        if (plates[i] == target) {
            return i;
        }
    }
    return -1;
}
int searchRecursive(string plates[], int size, string target, int index) {
    if (index >= size) {
        return -1;
    }
    
    if (plates[index] == target) {
        return index;
    }
    return searchRecursive(plates, size, target, index + 1);
}

int main() {
    string plates[] = {"GJ12AB1234", "GJ3C5678", "GJ51EM9012", "GJ3C5678", "GJ26AZ4321"};
    int size = sizeof(plates) / sizeof(plates[0]);

    cout << "Vehicle list (license plates):\n";
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] " << plates[i] << endl;
    }
    cout << endl;
    string target;
    cout << "Enter the license plate to search: ";
    cin >> target;
    int posIterative = searchIterative(plates, size, target);
    int posRecursive = searchRecursive(plates, size, target, 0);
    if (posIterative != -1) {
        cout << "Iterative Search: Target found at position (index) " << posIterative << endl;
    } else {
        cout << "Iterative Search: Target not found." << endl;
    }
    if (posRecursive != -1) {
        cout << "Recursive Search: Target found at position (index) " << posRecursive << endl;
    } else {
        cout << "Recursive Search: Target not found." << endl;
    }
    return 0;
}
