#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    int n,b,even=0,odd=0,i,j,currMin, cutAt,temp,counter;
    cin >> n >> b;
    int arr[n], evens[n], odds[n];

    for(i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i] %2 ==0){
            even++;
        }else{
            odd++;
        }
        evens[i] = even;
        odds[i] = odd;
    }
    /*
    for(i=0;i<n;i++){
        cout << evens[i] << " ";
    }
    cout << endl;
    for(i=0;i<n;i++){
        cout << odds[i] << " ";
    }
    cout << endl;
    */
    map<int,int>mp;
    counter = 0;
    while(1){
        currMin = INT_MAX;
        for(i=0;i<n-1;i++){
            if(odds[i] == evens[i]  && !mp[i]){
                temp = abs(arr[i] - arr[i+1]);
                if(temp < currMin){
                    currMin = temp;
                    cutAt = i;
                }
            }
        }
        if(b>currMin && !mp[cutAt]){
            counter++;
            b -= currMin;
            mp[cutAt] = 5;
        }else{
            break;
        }
        //msg(b,currMin)
    }
    cout << counter << endl;



    return 0;
}
