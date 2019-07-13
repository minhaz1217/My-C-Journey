/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/contest/310684#problem/E
Date : 13 / July / 2019
Comment: easy implementation.
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

long long int mark[3004];
int main(){
    vector<long long int> prime;
    long long int flag,caseCounter =1,tc,printed;
    long long int arr[30];
    string str;
    mark[0] = 1;
    mark[1] = 1;

    for(int i=2;i<=3000;i++){
        flag = 1;
        for(int j=2;j*j<=i;j++){
            if(i%j == 0){
                flag = 0;
            }
        }
        if(flag == 1){
            prime.push_back(i);
        }else{
            mark[i] = 1;
        }
    }
    cin >> tc;

    while(tc--){
        cin >> str;
        vector<char>vec,strgroup;
        map<char,int>mp;
        for(int i=0;i<30;i++){
            arr[i] = 0;
        }
        for(int i=0;str[i];i++){
            if(mp.find(str[i]) == mp.end()){
                vec.push_back(str[i]);
                mp[str[i]]=1;
            }else{
                mp[str[i]]++;
            }
        }
        sort(vec.begin(),vec.end());
        cout << "Case " << caseCounter++ <<": ";
        printed = 0;
        for(int i=0;i<vec.size();i++){
            if( mark[ mp[ vec[i] ] ] == 0 ){
                //strgroup.push_back(vec[i]);
                printed = 1;
                cout << vec[i];
                //msg(vec[i], mp[ vec[i] ])
            }
        }
        if(printed == 0){
            cout << "empty";
        }
        cout << endl;

    }
    return 0;
}
