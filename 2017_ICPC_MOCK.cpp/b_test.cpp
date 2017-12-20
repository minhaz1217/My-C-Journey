#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
long long int arr[100010] = {0};

long long fib(long long a){
    if(arr[a] != 0){
        return arr[a];
    }
    arr[a] = fib(a-1) + fib(a-2);
    return arr[a];
}

int main(){
    arr[0] = 1;
    arr[1] = 2;
    cout << fib(10) << endl;
    return 0;
}
