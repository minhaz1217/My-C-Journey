#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){

    long long int n,mnIndex,sum,mn =INT_MAX,a;
    vector<long long int> vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }

    for(int i=1;i<250;i++){
        sum =0;
        for(int j=0;j<vec.size();j++){
            sum += min(abs( vec[j] - i ),min( abs( vec[j] - (i+1) ),abs( vec[j] - (i-1) )) );
        }
        //msg(i,sum)
        if(sum < mn){
            mn = sum;
            mnIndex = i;
        }
    }
    cout << mnIndex << " " << mn << endl;
    return 0;
}
