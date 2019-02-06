//https://vjudge.net/contest/278631#problem/R
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int> z_algo(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}
vector<int>zz;

int main(){
    int tc,n,a;
    cin>> tc;
    vector<pair<int,int> > vec;
    vector<int>arr;
    string str, st;
    a= 0;
    while(tc--){
        cin >> n;
        vec.clear();
        arr.clear();
        arr.assign(300,0);
        for(int i=0;i<n;i++){
            cin >> str;
            msg(str, str.size())

            if(i>0){
                st += '$';
                a = st.size();
            }

            vec.push_back(make_pair(a, a+str.size()-1));
            st += str;

        }
        /*
        zz = z_algo(st);
        for(int i=0;i<vec.size();i++){
            msg(vec[i].first, vec[i].second)
        }
        for(int i=0;i<zz.size();i++){
            cout << zz[i] << " ";
        }
        cout << endl;
        for(int i=1;i<vec.size();i++){
                cc("HELLO")
            for(int j=vec[i].first;j<=vec[i].second;j++){
                cout << zz[j] << " ";
                arr[ zz[j] ]++;
            }
        cout << endl;
        }
        for(int i=0;i<10;i++){
            cout << arr[i] << " ";
        }
        cout << endl;

    }
    */
}
    return 0;
}
