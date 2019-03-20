/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: http://codeforces.com/contest/1141/problem/D
Date : 20 / March / 2019
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 41
#define pp 29
int main(){
    long long int n,mn,q1,q2;
    string str1, str2;
    cin >> n;
    cin >> str1 >> str2;
    vector<int>vec1[28], vec2[28],emp;
    vector<pair<int,int> >vec;
    for(int i=0;i<str1.size();i++){
        if(str1[i] == '?'){
            vec1[27].push_back(i);
        }else{
            vec1[ str1[i]-'a' ].push_back(i);
        }
        if(str2[i] == '?'){
            vec2[27].push_back(i);
        }else{
            vec2[ str2[i]-'a' ].push_back(i);
        }
    }
    q1 = 0;
    q2 = 0;
    for(int i=0;i<26;i++){
        //msg2((char) (i+'a'), vec1[i].size(), vec2[i].size())
        mn = min(vec1[i].size(), vec2[i].size());
        for(int j=0;j<mn;j++){
            vec.push_back(make_pair(vec1[i][j]+1, vec2[i][j]+1));
           // msg2("1", vec[vec.size()-1].first,vec[vec.size()-1].second )
        }
        if(vec1[i].size() == mn){
            for(int j=mn;j<vec2[i].size();j++){
                if(q1<vec1[27].size()){
                    vec.push_back(make_pair( vec1[27][q1]+1, vec2[i][j]+1 ));
            //msg2("3", vec[vec.size()-1].first,vec[vec.size()-1].second )
                    q1++;
                }
            }
        }else{
            for(int j=mn;j<vec1[i].size();j++){
                if(q2<vec2[27].size()){
                    vec.push_back(make_pair( vec1[i][j]+1, vec2[27][q2]+1 ));
           // msg2("4", vec[vec.size()-1].first,vec[vec.size()-1].second )
                    q2++;
                }
            }
        }
    }
    mn = min(vec1[27].size()-q1,vec2[27].size()-q2);
    for(int i=0;i<mn;i++){
        vec.push_back(make_pair(vec1[27][q1]+1, vec2[27][q2]+1));
        q1++;
        q2++;
    }
    cout << vec.size() << endl;
    for(int i=0;i<vec.size();i++){
        cout << vec[i].first << " " << vec[i].second << endl;
    }

    return 0;
}
