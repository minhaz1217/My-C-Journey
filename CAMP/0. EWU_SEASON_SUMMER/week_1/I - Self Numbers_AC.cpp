#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int digitadation(int n){
    int sum =n;
    while(n!= 0){
        sum += n%10;
        n = n/10;
    }
    return sum;
}


int main(){
    int arr[10002],i,n;
    for(i=0;i<=10000;i++){
        arr[i] = 0;
    }
    for(i=1;i<=10000;i++){
        n = digitadation(i);
        if(n <= 10000){
            arr[n] = 1;
        }
    }
    for(i=1;i<=10000;i++){
        if(arr[i] == 0){
            cout << i << endl;
        }
    }

    return 0;
}
