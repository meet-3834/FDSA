#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int target) {
    int left=0;
    int right=size-1;
    while (left <= right) {
        int mid=left+(right-left)/2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
    else {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }
}
int main() {
    int arr[] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    int target;
    cout << "Enter the element to search: ";
    cin >> target;
    int indexIterative = binarySearch(arr, size, target);
    int indexRecursive = binarySearchRecursive(arr, 0, size - 1, target);
    if (indexIterative != -1) {
        cout << "Iterative Search: Element found at index " << indexIterative << endl;
    } else {
        cout << "Iterative Search: Element not found." << endl;
    }
    if (indexRecursive != -1) {
        cout << "Recursive Search: Element found at index " << indexRecursive << endl;
    } else {
        cout << "Recursive Search: Element not found." << endl;
    }
    return 0;
}