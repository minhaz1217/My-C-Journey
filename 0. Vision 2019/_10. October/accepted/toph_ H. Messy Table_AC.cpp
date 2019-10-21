/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://toph.co/arena?contest=ngpc-2019-preliminary-r#!/p/messy-table
Date : 21 / October / 2019
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
    long long int tc,a,b,prev,counter;
    vector<pair<long long int, long long int> >vec;
    vector<long long int>myVec;
    cin>> tc;
    while(tc--){
        cin >> a >> b;
        vec.push_back({max(a,b), min(a,b)} );
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    for(auto it: vec){
        msg(it.first, it.second)
    }
    for(int i=0;i<vec.size();i++){
        counter = 0;
        for(int j=i+1;j<vec.size();j++){
                //msg(vec[i].first, vec[j].first)
            if(vec[i].first > vec[j].first && vec[i].second > vec[j].second){
                counter++;
            }
        }
        //msg(i,counter)
        myVec.push_back(counter);
    }
    sort(myVec.begin(),myVec.end());
    if(myVec[myVec.size()-1] == 0){
        cout << 1 << endl;
    }else{
        cout << myVec[myVec.size()-1] << endl;
    }
    return 0;
}
