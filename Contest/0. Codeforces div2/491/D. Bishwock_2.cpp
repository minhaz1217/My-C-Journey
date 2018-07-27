#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int i,sz,counter =0;
    string str1, str2;
    cin >> str1 >> str2;
    sz =str1.length();
    int arr[sz];
    for(i=0;i<sz;i++){
        arr[i] = 0;
    }
    for(i=0;i<sz;i++){
        if(str1[i] == '0'){
            arr[i] += 1;
        }
        if(str2[i] == '0'){
            arr[i] += 1;
        }
    }
/*
    for(i=0;i<sz;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
*/
/*
    for(i=0;i<sz-2;i++){
        if(arr[i] == 2 && arr[i+1] == 2 && arr[i+2] == 2){
            counter+=2;
            arr[i] = 0;
            arr[i+1] = 0;
            arr[i+2] = 0;
        }
    }
    */
/*
    for(i=0;i<sz;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    */
    for(i=0;i<sz;i++){
        if(arr[i] == 2 && arr[i+1] == 2){
            arr[i] = 0;
            arr[i+1] = 1;
            counter++;
        }
        if(arr[i] == 2 && arr[i+1] == 1){
            arr[i] = 0;
            arr[i+1] = 0;
            counter++;
        }else if(arr[i] == 1 && arr[i+1] == 2){
            arr[i] = 0;
            arr[i+1] = 0;
            counter++;

        }
    }
    cout << counter << endl;



    return 0;
}
