/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-10352
Date : 28 / July / 2019
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

map<string, vector<string> > mp;
long long int caseCounter =1;
void showOutput(){
    cout << "Set #" << caseCounter++ << ":"<<endl;
    for(map<string, vector<string> >::iterator it = mp.begin();it != mp.end();it++){
        string st = (it->first);
        vector<string>pq = (it->second);
        sort(pq.begin(), pq.end());
        //msg(st,pq[pq.size()-1])
        cout << pq[pq.size()-1] << " " << pq.size() << endl;
    }
    cout << endl;
    mp.clear();
}
int main(){
    string str,word,temp,t2;
    while(getline(cin, str)){
        if(str == "#"){
            showOutput();
            continue;
        }
        stringstream ss(str);
        while(ss>>word){
            if(word == "#"){
                showOutput();
                continue;
            }
            temp = word.substr(0,5);
            t2 = temp;
            if(t2.size()>=3){
                t2.erase(2,1);
            }
            //msg(temp,t2)
            mp[t2].push_back(temp);

        }
    }
//    if(mp.size()!=0){
//        showOutput();
//    }

    return 0;
}
