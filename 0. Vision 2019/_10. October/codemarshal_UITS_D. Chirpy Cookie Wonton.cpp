/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 31 / October / 2019
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


bool cmp(string a, string b){
    stringstream ss1(a), ss2(b);
    long long int aa,bb;
    ss1 >> aa;
    ss2 >> bb;
    return aa>=bb;
}
int main(){
    long long int caseCounter = 1,n,tc,l,r;
    cin.tie(0);
    ios::sync_with_stdio(false);
    string str,myStr,a,b,myStr2;
    cin >> tc;
    while(tc--){
        myStr = "";
        myStr2 = "";
        vector<string>vec;
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> str;
            vec.push_back(str);
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            myStr += vec[i];
        }
        for(int i=vec.size()-1;i>=0;i--){
            myStr2 += vec[i];
            //myStr2.push_back(vec[i]);
        }
        vector<string>vec2;
        vec2.push_back(myStr);
        vec2.push_back(myStr2);
        sort(vec2.begin(),vec2.end());
        cout << "Case " << caseCounter++ << ": " << vec2[1] << endl;
    }
    return 0;
}
