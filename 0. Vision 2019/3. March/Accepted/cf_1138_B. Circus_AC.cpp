/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://codeforces.com/contest/1138/problem/B
Date : 15 / March / 2019
Comment: solved after 11 WAs.
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
    int n,founder,sz1,sz2,sz3,sz4;
    string str1,str2;
    deque<int>vec1,vec2,vec3,vec4,vec;
    cin >> n >> str1 >> str2;
    for(int i=0;i<str1.size();i++){
        if(str1[i] == '0' && str2[i]== '0'){
            vec1.push_back(i);
        }else if(str1[i] == '0' && str2[i]== '1'){
            vec2.push_back(i);
        }else if(str1[i] == '1' && str2[i]== '0'){
            vec3.push_back(i);
        }else{
            vec4.push_back(i);
        }
    }
    //msg3(vec1.size(), vec2.size(), vec3.size(), vec4.size())
int    updated = 1;
    while(vec4.size()>0 && updated){
        updated = 0;
        sz1 = vec4.size();
        sz2 = vec2.size();
        sz3 = vec3.size();

//        if(sz1 <2 && sz1> sz2+sz3){
//            cout << -10 << endl;
//            return 0;
//        }
        if(sz1>sz2 && sz1>sz3  && sz1>2){
            //msg("P1", vec2[0])
            vec.push_back(vec4.front());
            vec4.pop_front();
            vec4.pop_front();
            updated = 1;
        }else if(sz2>sz1 && sz2>sz3){
            vec.push_back(vec4.front());
            vec2.pop_front();
            vec4.pop_front();
            updated = 1;
        }else if(sz3>sz1 && sz3>sz2){
            vec.push_back(vec3.front());
            vec3.pop_front();
            vec4.pop_front();
            updated = 1;
        }else{
            //cc("HELLO")
            if(vec3.size()>0){
            vec.push_back(vec3.front());
            vec3.pop_front();
            vec4.pop_front();
            updated = 1;
            }else if(vec2.size()>0){
                vec.push_back(vec4.front());
                vec2.pop_front();
                vec4.pop_front();
                updated = 1;
            }else if(vec4.size()>=2){
                vec.push_back(vec4.front());
                vec4.pop_front();
                vec4.pop_front();
                updated = 1;
            }
        }
    }
    //msg("SZ 1" , vec.size())
    //msg3(vec1.size(), vec2.size(), vec3.size(),vec4.size())
    while(vec2.size()>0 && vec3.size()>0){
        vec.push_back(vec2.front());
        vec2.pop_front();
        vec3.pop_front();
    }

    //msg3("SZ 2" , vec.size(),vec2.size(), vec3.size())
    while(vec2.size()>0 && vec1.size()>0){
        vec.push_back(vec2.front());
        vec2.pop_front();
        vec1.pop_front();
    }

    while(vec3.size()>0 && vec1.size()>0){
        vec.push_back(vec1.front());
        vec3.pop_front();
        vec1.pop_front();
    }

//msg("SZ 3" , vec.size())

    while(vec1.size()>1){
        vec.push_back(vec1.front());
        vec1.pop_front();
        vec1.pop_front();
    }
//msg("SZ 4" , vec.size())
    if((int)vec.size() == (n/2)){
        //cc("WHAT?")
        sort(vec.begin(), vec.end());
        for(int i=0;i<vec.size();i++){
            if(i >0){
                cout << " ";
            }
            cout << vec[i]+1;
        }
    }else{
        cout << -1 << endl;
    }

    return 0;
}
