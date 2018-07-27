#include<bits/stdc++.h>
#include<time.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

void generateNumbersAtoB(){
    long long int n,a,b;
    srand(time(NULL));
    cout << "Generate n numbers from a to b.\n" << endl;
    cout << "Enter N: ";
    cin >> n;
    cout << "Enter A(startig position): ";
    cin >> a;
    cout << "Enter B (ending position): ";
    cin >> b;
    cout << endl;
    cout << "Generating " << n << " numbers from " << a << " to " << b << endl;
    for(long long int i=0;i<n;i++){
        cout << a+((rand())%(b-a)) << " ";
    }
    cout << endl;
}



int main(){
    generateNumbersAtoB();
    return 0;
}
