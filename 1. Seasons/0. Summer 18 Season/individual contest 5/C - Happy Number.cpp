#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

long long int sum(long long int a){
    long long int sm = 0,t;
    while(a!=0){
        t = a%10;
        sm += (t*t);
        a = a/10;
    }
    return sm;
}

int main(){

    long long int a,tc,sm,flag,caseCounter=1;
    cin >> tc;
    while(tc--){
        cin >> a;
        flag = 0;
        map<long long int,int>mp;
        sm = a;
        while(1){
            if(sm == 1){
                flag = 1;
                break;
            }else{
                if(!mp[sm]){
                    mp[sm] = 1;
                }else{
                    flag = 0;
                    break;
                }
            }
            sm = sum(sm);
        }
        if(flag == 1){
            cout << "Case #" << caseCounter++ << ": " << a << " is a Happy number." << endl;
        }else{
            cout << "Case #" << caseCounter++ << ": " << a << " is an Unhappy number." << endl;
        }
    }

    return 0;
}
