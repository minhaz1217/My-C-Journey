#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int i, n,reach, sum,mCount;

    cin >> n;
    if(n<=4){
        cout << 1 << endl;
        return 0;
    }
    if(n%2 == 0){
        reach = (n/4) * (n-1);
    }else{
        reach = ((n-1)/4) *n;
    }

    sum = 0;
    //msg("REch", reach)
    //reach = reach/2;
    //msg("REACH", reach)
    for(i=1;i<=n;i++){
        sum += (n-i);
        if(sum >=reach){
            mCount = i;
            break;
        }
    }
    //msg(sum,i)
    cout << i << endl;
    return 0;
}
