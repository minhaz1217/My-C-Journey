#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int tc,i, peopleCounter = 0, finalCounter =0, counter = 0;
    string song[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
    cin >> tc;
    counter = 0;
    string arr[tc];
    for(i=0;i<tc;i++){
        cin >> arr[i];
    }
    peopleCounter = 0;
    finalCounter = 0;
    while(1){
        cout << arr[peopleCounter++] << ": " << song[counter++] << endl;
        finalCounter++;
        if(peopleCounter >=tc){
            peopleCounter = 0;
        }
        if(finalCounter >= 16 && finalCounter >= tc && counter == 16){
            break;
        }
        if(counter >= 16){
            counter = 0;
        }
    }
    return 0;
}
