#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int n,x,y,a;
    vector<int>vec;
    cin >> n >> x >> y;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a <= x && a +y>=x ){
            vec.push_back(a);
        }
    }
    sort(vec.begin(),vec.end());
    //msg("SZ", vec.size());
    if( x > y ){
        cout << n  << endl;
    }else{
        cout << (int)ceil( (double)vec.size()/2.0 ) << endl;
    }

    return 0;
}
