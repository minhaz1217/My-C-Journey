#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    int n,i,sz;
    map<int, int>mp;
    vector<int>vec;
    while(scanf("%d", &n) == 1){
        if(mp.find(n) == mp.end()){
            mp[n] = 1;
            vec.push_back(n);
        }else{
            mp[n]++;
        }
    }
    sz = vec.size();
    for(i=0;i<sz;i++){
        printf("%d %d\n", vec[i], mp[vec[i]]);
    }


    return 0;
}
