/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-706
Date : 15 / March / 2019
Comment: easy to understand but hard to implement problem;
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
int s, m;
vector<string>vec;
void draw(int n, int ll){
//    msg2("INPUT", n,ll)
    int l , r, top = 0, mid , down = 2*s+2;
    mid = down/2;
    string str;
//    vector<string>vec;
    map<int,int>mp;
    l = 0, r =s+1;
    str = "";

//    for(int i=0;i<s+2;i++){
//        str += " ";
//    }
//    for(int i=0;i<=down;i++){
//        vec.push_back(str);
//    }
//    for(int i=top;i<=down;i++){
//        for(int j=l;j<=r;j++){
//            cout << vec[i][j];
//        }
//        cout << endl;
//    }
    //return;
//    vec.push_back(str);
    if(n == 1){
        mp[3] = 1;
        mp[6] = 1;
    }else if(n == 2){
        mp[1] = 1;
        mp[3] = 1;
        mp[4] = 1;
        mp[5] = 1;
        mp[7] = 1;
    }else if(n == 8){
        mp[1] = 1;
        mp[2] = 1;
        mp[3] = 1;
        mp[4] = 1;
        mp[5] = 1;
        mp[6] = 1;
        mp[7] = 1;
    }else if(n == 3){
        mp[1] = 1;
        mp[3] = 1;
        mp[4] = 1;
        mp[6] = 1;
        mp[7] = 1;
    }else if(n == 4){
        mp[2] = 1;
        mp[3] = 1;
        mp[4] = 1;
        mp[6] = 1;
    }else if(n == 5){
        mp[1] = 1;
        mp[2] = 1;
        mp[4] = 1;
        mp[6] = 1;
        mp[7] = 1;
    }else if(n == 6){
        mp[1] = 1;
        mp[2] = 1;
        mp[4] = 1;
        mp[5] = 1;
        mp[6] = 1;
        mp[7] = 1;
    }else if(n == 7){
        mp[1] = 1;
        mp[3] = 1;
        mp[6] = 1;
    }else if(n == 9){
        mp[1] = 1;
        mp[2] = 1;
        mp[3] = 1;
        mp[4] = 1;
        mp[6] = 1;
        mp[7] = 1;
    }else if(n == 0){
        mp[1] = 1;
        mp[2] = 1;
        mp[3] = 1;
        mp[5] = 1;
        mp[6] = 1;
        mp[7] = 1;
    }
//    for(int i=1;i<=7;i++){
//        if(mp[i] == 1){
//            cout << i << " ";
//        }
//    }
//    cout << endl;


    if(mp[1] == 1){
        for(int i=l+1;i<r;i++){
            vec[top][i+ll] = '-';
        }
    }
    if(mp[2] == 1){
        for(int i=top+1;i<mid;i++){
            vec[i][l+ll] = '|';
        }
    }
    if(mp[3] == 1){
        for(int i=top+1;i<mid;i++){
            vec[i][r+ll] = '|';
        }
    }
    if(mp[4] == 1){
        for(int i=l+1;i<r;i++){
            vec[mid][i+ll] = '-';
        }
    }

    if(mp[5] == 1){
        for(int i=mid+1;i<down;i++){
            vec[i][l+ll] = '|';
        }
    }
    if(mp[6] == 1){
        for(int i=mid+1;i<down;i++){
            vec[i][r+ll] = '|';
        }
    }
    if(mp[7] == 1){
        for(int i=l+1;i<r;i++){
            vec[down][i+ll] = '-';
        }
    }

//    for(int i=top;i<=down;i++){
//        //vec3[i] = vec[i];
////        cc(vec[i])
//        for(int j=l;j<=r;j++){
//            vec3[i][j+ll] = vec[i][j];
////            msg(i, j+ll)
//        }
//        //cout << endl;
//    }
}
int main(){
    _INIT;
    string str,st;
    int last, ll,counter = 1;
    while(1){
        //scanf("%d %d", &s, &m);
        cin >> s >> st;
        if(s == 0 && m == 0){
            break;
        }

        vector<int>vec2;
        vec.clear();
        str = "";
        for(int i=0;i<st.size();i++){
            vec2.push_back(st[i] - '0');
        }
        for(int i=0;i< vec2.size()*(s+2)+ (vec2.size()-1);i++){
            str+= " ";
        }
        for(int i=0;i<2*s+3;i++){
            vec.push_back(str);
        }
//        for(int i=0;i<vec3.size();i++){
//            cout << vec3[i] << endl;
//        }
        last = -1;
        for(int i=0;i<vec2.size();i++){
            ll = last+1;
            last = ll+s+2;
            draw(vec2[i], ll);
            //cout << vec2[i] << endl;
        }
        for(int i=0;i<vec.size();i++){
            cout << vec[i] << endl;
            //printf("%c\n", vec[i] );
        }
        //printf("\n");
        cout << endl;
    }

    return 0;
}
