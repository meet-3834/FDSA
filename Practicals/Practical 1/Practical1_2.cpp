#include <iostream>
using namespace std;
int main() {
  int book[] = {101, 102, 103, 104, 105};
  int a = 0, b = 0, c = 0, d = 0, e = 0;
  int record[] = {101, 101, 101, 102, 105, 105, 103, 103, 102, 104};
  int size = sizeof(record) / sizeof(record[0]);
  for (int i = 0; i < size; i++) {
    if (record[i] == 101) {
      a++;
    }
    if (record[i] == 102) {
      b++;
    }
    if (record[i] == 103) {
      c++;
    }
    if (record[i] == 104) {
      d++;
    }
    if (record[i] == 105) {
      e++;
    }
  }
  cout << "record: ";
  for (int i = 0; i < size; i++) {
    cout << record[i] << " ";
  }
  cout << endl;
  cout << "Number of books 101:" << a << endl;
  cout << "Number of books 102:" << b << endl;
  cout << "Number of books 103:" << c << endl;
  cout << "Number of books 104:" << d << endl;
  cout << "Number of books 105:" << e << endl;
  return 0;
}