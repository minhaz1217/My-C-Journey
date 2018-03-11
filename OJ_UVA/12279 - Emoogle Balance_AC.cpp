#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,a,i,counter,caseCounter = 1;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        counter = 0;
        for(i=0;i<n;i++){
            cin >> a;
            if(a == 0){
                counter--;
            }else{
                counter++;
            }
        }
        cout << "Case "<< caseCounter++ << ": " << counter << endl;


    }

    return 0;
}
