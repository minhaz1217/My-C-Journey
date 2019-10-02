/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 05 / September / 2019
Comment: https://vjudge.net/problem/UVA-10567
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
    string str;
    char prev;
    long long int counter,n,curr,firstPos,lastPos,sum;
    queue<long long int> q;
    vector<long long int>cumSum;
    vector<pair<char,long long int> > vec;
    cin >> str;
    prev = str[0];
    counter = 1;
    sum = 0;
    for(int i=1;i<str.size();i++){
        if(str[i] != prev){
            vec.push_back({prev, counter});
            prev = str[i];
            su m += counter;
            cumSum.push_back(sum);
            counter = 0;
        }
        counter++;
    }

    sum += counter;
    cumSum.push_back(sum);
//    for(auto it:cumSum){
//        cc(it)
//    }
    vec.push_back({prev, counter});

    cin >> n;
    for(int i=0;i<n;i++){
        vector<pair<char,long long int> > temp;
        cin >> str;
        prev = str[0];
        counter = 1;
        for(int i=1;i<str.size();i++){
            if(str[i] != prev){
                temp.push_back({prev, counter});
                prev = str[i];
                counter = 0;
            }
            counter++;
        }
        temp.push_back({prev, counter});
        curr = 0;
        firstPos = -1;
        lastPos = -1;
        sum = 0;
        for(int i=0;i<vec.size();i++){
            if(vec[i].first == temp[curr].first && vec[i].second >= temp[curr].second){
                curr++;
                if(firstPos == -1){
                    firstPos = i;
                }
                lastPos = i;
            }
            if(curr == temp.size()){
                break;
            }
        }
        if(curr != temp.size()){
            cout << "Not matched" << endl;
//
//            while(!q.empty()){
//                firstPos = q.front();
//                lastPos = -1;
//                curr = 0;
//                q.pop();
//                sum =0;
//                for(int i=q.front();i<vec.size();i++){
//                    if(vec[i].first == temp[curr].first && vec[i].second >= temp[curr].second){
//                        curr++;
//                        lastPos = i;
//                    }
//                }
//                sum += vec[i].second;
//                if(curr == temp.size()){
//                    break;
//                }
//            }
//            if(curr == temp.size()){
//                cout << "Matched " << cumSum[firstPos]-vec[firstPos].second << " " << cumSum[lastPos]-vec[lastPos].second+temp[temp.size()-1].second-1<<endl;
//                }else{
//                cout << "Not matched" << endl;
//            }
        }else{
//            cout << "Matched " <<
            cout << "Matched " << cumSum[firstPos]-vec[firstPos].second << " " << cumSum[lastPos]-vec[lastPos].second+temp[temp.size()-1].second-1<<endl;

        }

    }
    return 0;
}
