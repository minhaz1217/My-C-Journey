/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 03 / March / 2019
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
    long long int n,k,a,solved,counter,mainCounter,index = 0;
    vector<long long int>vec,vec2;
    vector<pair<int,int> > vec3;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin  >> a;
        vec.push_back(a);
        //vec2.push_back( i/(double)n * 100.0 );
    }
    for(int i=0;i<min(n,k);i++){
            vec3.push_back( make_pair(0, vec[index++]) );

    }
    counter = 0;
    solved = 0;
    mainCounter = 0;
    while(solved!=n){
        for(int i=0;i<vec3.size();i++){
            if(vec3[i].first <0){
                continue;
            }
            //msg2(i, vec3[i].first, vec3[i].second)
            if(vec3[i].first == vec3[i].second){
                solved++;
                vec3[i].first = -5;
                vec3[i].second = 100;
                if(index<n){
                    vec3[i] = make_pair(0, vec[index++]);
                }
            }
            if(solved == n){
                break;
            }
            mainCounter = floor( (solved/(double)n  *100.0)+.5 );
            vec3[i].first++;
            if(vec3[i].first == mainCounter){
                //msg2(i, vec3[i].first, "MA")
                counter++;
            }
        }
    }
    cout << counter << endl;


    return 0;
}
