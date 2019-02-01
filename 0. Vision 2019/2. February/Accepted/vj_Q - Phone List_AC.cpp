// https://vjudge.net/contest/278631#problem/Q
// should've been a string matching algorithm, used basic sorting and go AC. the reason being the range was small enough
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
    int tc,n,flag;
    vector<string>vec;
    string str,temp;
    cin>> tc;
    while(tc--){
        vec.clear();
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> str;
            vec.push_back(str);
        }
        sort(vec.begin(),vec.end());
        flag = 0;
        for(int i=1;i<vec.size();i++){
            temp = vec[i].substr(0, vec[i-1].size());
            if(temp == vec[i-1]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }

    }

    return 0;
}
