#include <iostream>
using namespace std;
int main() {
  int n;
  cout << "enter the size of array:";
  cin >> n;
  int arr[n];
  cout << "enter the elements of array:";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << endl;
  cout << "array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl << endl;
  // bubble sort
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  cout << "Sorted array using bubble sort:";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i] > arr[j]) {
        int temp = arr[i]; // if arr[i] is greater than arr[j] then swap them
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  cout << "Sorted array using selection sort: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // insertion sort
  for (int i = 1; i < n; i++) {
    int current = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > current) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = current;
  }
  cout << "Sorted array using insertion sort: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}