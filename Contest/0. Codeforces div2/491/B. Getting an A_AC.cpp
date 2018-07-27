#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,i;
    double sum,temp,a,counter,sub;
    cin >> n;
    sum = 0;
    temp = n;
    double arr[n];
    for(i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    counter = 0;
    while(round(sum/n) < 5 ){
        sum +=1;
        counter++;
    }
    sort(arr,arr+n);
    sub = 0;
    for(i=0;i<n;i++){
        if(arr[i] < 5){
            a = 5 - arr[i];
        }
        if(counter <=0){
            break;
        }else{
            sub++;
        }
        //msg(a, arr[i])
        counter -= a;
    }

    cout << sub << endl;



    return 0;
}
