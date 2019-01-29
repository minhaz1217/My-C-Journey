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
    int n,k,mx;
    int arr[27];
    string str,st="";
    map<string, int>mp;
    vector<string>vec;
    cin >> n >> k;
    cin>> str;
    for(int i=0;i<27;i++){
        arr[i] = 0;
    }
    st = str[0];
    if(st.size() == k){
        //cc(st)
        if(!mp[st]){
            mp[st] = 1;
            vec.push_back(st);
        }else{
            mp[st]++;
        }
        st = "";
    }
    for(int i=1;str[i];i++){

        if(str[i] == str[i-1]){
            //msg(i, st)
            st += str[i];
        }else{
            st = str[i];
        }
        if(st.size() == k){
            //cc(st)
            if(!mp[st]){
                mp[st] = 1;
                vec.push_back(st);
            }else{
                mp[st]++;
            }
            st = "";
        }
    }
    mx = 0;
    for(int i=0;i<vec.size();i++){
        mx = max(mx, mp[ vec[i] ]);
    }
    cout << mx << endl;
    return 0;
}
