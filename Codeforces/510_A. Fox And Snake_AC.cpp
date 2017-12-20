#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long n,m,i,j;
    cin >> n >>m;
    for(i=1;i<=n;i++){
        if(i%4 == 0){
            cout << "#";
            for(j=1;j<m;j++){
                cout << ".";
            }
        }else if(i%2 == 0){
            for(j=1;j<m;j++){
                cout << ".";
            }
            cout << "#";
        }else{
            for(j=1;j<=m;j++){
                cout << "#";
            }
        }
        cout << endl;
    }


	return 0;
}
