#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int tc,n,k,counter;
    cin >>tc;
    while(tc--){
        cin >> n >> k;
        counter = 0;
        while(counter != n){
            for(int i=0;i<k;i++){
                cout << char('a'+i);
                counter++;
                if(counter == n){
                    cout << endl;
                    break;
                }
            }
        }
    }

    return 0;
}
