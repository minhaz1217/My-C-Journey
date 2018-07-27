#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


int sumThis(int n, int sum){
    int a;
    if(n<=0){
        return sum;
    }else{
        cin >> a;
        //sum +=a ;
        return sumThis(n-1,sum+a);
    }
}

int main(){
    int tc,n,caseCounter =1,sum;
    cin >> tc;
    while(tc--){
        cin >> n;
        sum = sumThis(n,0);
        cout << "Case " << caseCounter++ << ": " << sum << endl;
    }

    return 0;
}
