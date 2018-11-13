#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int tc,a,n,k,counter;
    cin >>tc;
    while(tc--){
        cin >> n >> k;
        counter = 0;
        for(int i=0;i<n;i++){
            cin >> a;
            //vec.push_back(a);
            if(a != 1){
                counter++;
            }
        }
        //cc(counter)
        if(k>=counter){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
