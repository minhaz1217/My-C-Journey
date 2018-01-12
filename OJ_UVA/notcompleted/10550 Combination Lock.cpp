#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int a,b,c,d,res = 0;
    while(1){
        cin >> a >> b>>c>>d;
        if(a == 0 && b==0 && c ==0 && d==0){
            break;
        }
        res = 360*2;
        if(a<=b){
            res += (b-a)*9;
        }
        if(c <=b){
            res += (b-c) * 9;
        }
        if(c <=d){
            res += (d-c)*9;
        }

    cout << res << endl;

    }



	return 0;
}
