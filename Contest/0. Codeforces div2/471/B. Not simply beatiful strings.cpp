#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    vector<int>arr;
    string str;
    int i,counter, foundTwo,pos,foundOne = 0;
    arr.assign(27,0);
    cin >> str;
    for(i=0;str[i];i++){
        pos = str[i] - 'a';
        arr[pos]++;
    }
    foundTwo = 0;
    counter = 0;
    for(i=0;i<27;i++){
        if(arr[i] % 2 == 0){
            foundTwo++;
        }else if(arr[i]%2 == 1){
            foundOne++;
        }
        if(arr[i] !=0){
            counter++;
        }
    }
    //msg(counter, foundTwo)
    if(counter >= 2 && foundTwo>=2){
        if(counter%2 == 0 && foundTwo%2 ==0 ){
            cout << "No" << endl;
        }else{
            cout << "Yes"<< endl;
        }
    }else{
        cout << "No" << endl;
    }

    return 0;
}
