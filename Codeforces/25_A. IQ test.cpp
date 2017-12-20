#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long tc,a,b,c,d,n,num1,num2,num3,pos = -1, diff = -1,i;
    cin >> tc;
    cin >> num1 >> num2 >> num3;
    if(abs(num1- num2-num3) ==0){
        diff = abs(num2-num3);
    }else if(a == b){
        pos = 3;
    }else if(b == c){
        pos = 1;
    }else if(a == c){
        pos = 2;
    }else if(tc >3){
        cin >> d;
        if(abs(a-b-d) == 0){
            pos = 3;
        }else if(abs(a-c-d) == 0){
            pos = 2;
        }else if(abs(b-c-d) == 0){
            pos = 1;
        }
        for(i=4;i<=tc;i++){
            cin>>n;
        }
    }else{
        for(i=4;i<=tc;i++)
    }
    if(diff != -1){
        for(i=5;i<=tc;i++){
            cin >> n;
            if(abs(n-c) != diff){
                pos = i;
                c = c+diff;
            }
            c = n;
        }
    }
    cout << pos << endl;

	return 0;
}
