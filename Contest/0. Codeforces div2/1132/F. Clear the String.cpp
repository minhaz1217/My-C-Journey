/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 05 / March / 2019
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


int main(){
    int n,a,counter, l, r, myMin, pos,zeroCount;
    string str;
    char prev;
    vector<int>vec, vec2(30);
    cin >> n >> str;
    prev = str[0];
    for(int i=1;i<str.size();i++){
        if(str[i] != prev){
            a = prev - 'a' + 1;
            vec2[a]++;
            vec.push_back( prev-'a'+1 );
            prev = str[i];
        }
    }
    a = prev - 'a' + 1;
    vec2[a]++;
    vec.push_back( prev-'a'+1 );
    counter = 0;
    while(1){
        myMin = INT_MAX;
        zeroCount = 0;
        for(int i=1;i<=26;i++){
            if(myMin > vec2[i] && vec2[i] > 0){
                myMin = vec2[i];
                pos = i;
            }
            if(vec2[i] <= 0){
                zeroCount++;
            }
        }
        if(zeroCount == 25){
            counter++;
            break;
        }
        if(myMin == INT_MAX){
            break;
        }
        /*
msg2("SELECTED", myMin, pos)
for(int i=0;i<vec2.size();i++){
//cout << vec2[i] << " ";
}
cout << endl;
*/
        vector<int>newVec;
        for(int i=0;i<vec.size();i++){
            if(vec[i] == pos){
                counter++;
                vec[i] = -1;
                vec2[pos]--;
                l = 0;
                r = 0;
                if(i-1>=0){
                    l = vec[i-1];
                }
                if(i+1<vec.size()){
                    r = vec[i+1];
                }
                if(l && r){
                    if(l == r){
                        vec2[l]--;
                        newVec.push_back(vec[i-1]);
                        i = i+1;
                    }
                }
            }else{
                newVec.push_back(vec[i]);
            }
        }
        /*
        for(int l=0;l<newVec.size();l++){
            cout << newVec[l] << " ";
        }
        cout << endl;*/
        prev = newVec[0];
        vec.clear();
        for(int i=0;i<30;i++){
            vec2[i] = 0;
        }
        vec2[prev]++;
        for(int i=1;i<newVec.size();i++){
            if(newVec[i] != prev){
                vec.push_back(prev);
                prev = newVec[i];
                vec2[prev]++;
            }
        }
        vec.push_back(prev);
        vec2[prev]++;
    }

    cout << counter << endl;
    return 0;
}
