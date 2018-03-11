#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int tc,n,flag,i;
    cin >> tc;
    while(tc--){
        cin >> n;
        flag = 1;
        if(n%2 == 0 && n!=2){
            flag =0;
        }else{
            for(i=3;i<=n/2;i+=2){
                if(n%i == 0){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag==1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
	return 0;
}
