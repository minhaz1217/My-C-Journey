#include<iostream>
#include<stdio.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    double tc = 12, sum =0,i,n;
    for(i=0;i<tc;i++){
        cin >> n;
        sum += n;
    }
    printf("$%.2lf", sum/tc);

    return 0;
}
