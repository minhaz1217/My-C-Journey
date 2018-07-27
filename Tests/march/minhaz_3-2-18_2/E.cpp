#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    long long int a,b,i,tc,flag,n;
    cin >> tc;
    while(tc--){
        cin >> n;
        flag = 0;
        for(i=0;i<=n;i++){
            b = n - 7*i;
            if(b<0){
                break;
            }else if(b<4){
                continue;
            }else if(b==0 ){
                flag = 1;
                break;
            }else if(b>=4 && b%4 == 0){
                flag =1;
                break;
            }
        }

        if(flag == 1){
            cout <<"YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
    return 0;
}
