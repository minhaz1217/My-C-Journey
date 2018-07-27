#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    char p,a;
    int n,counter;
    cin >> n;
    counter = 0;
    p = ' ';
    for(int i=0;i<n;i++){
        cin >> a;
        //msg(p,a)
        if(p == ' '){
            p = a;
        }
        if(p != a){
            counter++;
            p = ' ';
        }
    }
    //cc(counter)
    cout << (n)-counter << endl;

    return 0;
}
