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
    int n,m,k,a,counter;
    cin >> n >> m >> k;
    vector<int>vec1,vec2;
    vector<int>vec3[200];
    vec1.push_back(-1);
    vec2.push_back(-1);
    for(int i=0;i<n;i++){
        cin >> a;
        vec1.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin >> a;
        vec2.push_back(a);
    }
    for(int i=1;i<vec2.size();i++){
        vec3[ vec2[i] ].push_back(vec1[i]);
        //vec3.push_back(make_pair( vec2[i], vec1[i] ));
    }
    for(int i=1;i<=m;i++){
        sort(vec3[i].rbegin(),vec3[i].rend());
    }
    counter = 0;
    for(int i=1;i<=k;i++){
        cin >> a;
        //msg2(vec2[a],vec1[a],vec3[vec2[a] ][0])
        if(vec3[ vec2[a] ][0] != vec1[a]){
            counter++;
        }
    }
    cout << counter << endl;

    return 0;
}
