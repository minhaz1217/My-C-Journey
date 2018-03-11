#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long int tc, i,num,half,rt,flag;
    cin >> tc;
    while(tc--){
        cin >> num;
        flag = 1;
        if((num>4 && num%2 == 0) || num<4){
            cout << "NO" << endl;
            continue;
        }
        rt = sqrt(num);
        if(rt*rt == num){
            half = num/2;
            for(i=3;i<=half;i+=2){
                if(num%i == 0 && i != rt){
                    flag = 0;
                    break;
                }
            }
        }else{
            flag = 0;
        }
        if(flag == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
	return 0;
}
