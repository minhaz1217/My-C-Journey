#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long int n,k=1,caseCounter =1,tc,tmp;
    cin >> tc;
    while(tc--){
        cin >> n;
        tmp = n;
        k = 0;
        if(n%2!=0){
            cout << "Case "<< caseCounter++ << ": Impossible"  << endl;
        }else{
            while(n %2 ==0){
                n = n/2;
                k *=2;
            }
            cout << "Case "<< caseCounter++ << ": "<<  n << " "<< tmp/n << endl;
        }
    }
    return 0;
}
