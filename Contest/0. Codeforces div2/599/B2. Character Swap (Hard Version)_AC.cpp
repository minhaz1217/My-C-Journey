/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 06 / November / 2019
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


string str1,str2;
vector<pair<int,int> >vec;

bool matchFromFirst(int k){
    for(int i=0;i<k;i++){
        if(str1[i] == str1[k]){
            swap(str2[k],str1[i]);
            vec.push_back({i,k});
            return 1;
        }
    }
    return 0;
}
bool matchFromSecond(int k){
    for(int i=0;i<k;i++){
        if(str2[i] == str2[k]){
            swap(str1[k],str2[i]);
            vec.push_back({k,i});
            return 1;
        }
    }
    return 0;
}
bool doubleMatch(int k){
    for(int i=0;i<k;i++){
        if(str1[i] == str2[k]){
            swap(str2[0], str1[i]);
            vec.push_back({i,0});
            swap(str2[0], str1[k]);
            vec.push_back({k,0});
            return 1;
        }
    }
    return 0;
}
int main(){
    int tc,n;
    cin >> tc;
    while(tc--){
        vec.clear();
        cin >> n >> str1 >> str2;
        for(int i=n-1;i>=0;i--){
            if(str1[i] != str2[i]){
                if(matchFromFirst(i) == 0){
                    if(matchFromSecond(i) == 0){
                        doubleMatch(i);
                    }
                }
            }
        }
        if(str1 == str2 && vec.size() <= 2*n){
            cout << "Yes" << endl;
            cout << vec.size() << endl;
            for(int i=0;i<vec.size();i++){
                cout << vec[i].first+1 << " "<<vec[i].second+1 << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
