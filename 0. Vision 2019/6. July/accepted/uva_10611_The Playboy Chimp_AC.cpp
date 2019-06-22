/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: easy binary search.
Date : 21 / July / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    long long int n,a,q,u,l,r,lpos;
//    vector<long long int>vec;
    set<long long int>st;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        st.insert(a);
        //vec.push_back(a);
    }

    vector<long long int>vec;
    vec.assign(st.begin(),st.end());
    cin >> q;
    while(q--){
        cin >> a;
        lpos = upper_bound(vec.begin(), vec.end(),a)-vec.begin();
//        msg("HI", lpos)
lpos--;
//msg(a, vec[vec.size()-1])
        if(a<vec[0]){
            l = -1;
            r = vec[0];
        }else if(a>vec[vec.size()-1]){
            l = vec[vec.size()-1];
            r = -1;
        }else{
            if(vec[lpos] == a){
                if(lpos-1>=0){
                    l = vec[lpos-1];
    //                cout << vec[lpos-1];
                }else{
                    l = -1;
                }
                if(lpos+1<vec.size()){
                    r = vec[lpos+1];
                }else{
                    r = -1;
                }
            }else{
                l = vec[lpos];
                r = lpos+1 < vec.size()? vec[lpos+1]:-1;
            }
    }

    if(l == -1){
        cout << "X";
    }else{
        cout << l;
    }
    cout << " ";
    if(r == -1){
        cout << "X";
    }else{
        cout << r;
    }
    cout << endl;

    }
    return 0;
}


