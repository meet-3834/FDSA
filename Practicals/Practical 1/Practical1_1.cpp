#include<iostream>
using namespace std;
void print(const int arr[], int n, long long h) {
    if (n==0) return;
    int k=h%n;
    for (int i=k; i < n; ++i) {
        cout<<arr[i]<<" ";
    }
    for (int i=0;i<k;++i) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
  int arr[5];
  cout<<"enter the 5 elements:";
  for(int i=0;i<5;i++)
  {
    cin>>arr[i];
  }
    int n = sizeof(arr) / sizeof(arr[0]);   
    long long h;
    cout<<"Enter Number of hours: ";
    cin>>h;
    cout<<"Initial row: ";
    for (int i=0;i<n;++i) {
        cout<<arr[i]<<" ";
    }
    cout<<"\nHours (h): "<<h<<"\n";
    cout<<"Final display order: ";
    print(arr, n, h);
    return 0;
}
