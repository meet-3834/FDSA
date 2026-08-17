#include<iostream>
using namespace std;
int main() {
    char sentence[1000]; 
    cout<<"Enter a sentence: ";
    cin.getline(sentence, 1000);
    int maxLength = 0;
    int maxStart = 0;
    int currentLength = 0;
    int currentStart = 0;
    int i = 0;
    while (true) {
        if ((sentence[i]>='a' && sentence[i]<='z') || 
            (sentence[i]>='A' && sentence[i]<='Z')) {
            if (currentLength==0) {
                currentStart=i;
            }
            currentLength++;
        } else
         {
            if (currentLength>maxLength) {
                maxLength=currentLength;
                maxStart=currentStart;
            }
            currentLength=0;
            
            if (sentence[i]=='\0') {
                break;
            }
        }
        i++;
    }
    if(maxLength>0)
    {
        cout<<"Winning word: ";
        for (int j=0;j<maxLength;j++) {
            cout<<sentence[maxStart + j];
        }
        cout<<"\nLength: " << maxLength << endl;
    }
    else
    {
        cout<<"No words found in the sentence."<<endl;
    }

    return 0;
}
