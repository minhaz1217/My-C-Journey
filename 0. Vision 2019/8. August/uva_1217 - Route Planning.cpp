/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 31 / August / 2019
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

long long int mat[104][104],n,r,a,totalN,beg,en;
string str;
long long int mainCost = INT_MAX;
long long int findPath(int u, long long int cost, int n, vector<int>vec){
    //msg2(u,n,cost)
    long long int v,mn = INT_MAX;
    if(cost>=99999){
        return;
    }
    if(memo[u][n]!=-1){
        return memo[u][n];
    }
    if(n == totalN){
        //msg("REACHED", cost+mat[u][en])
        mainCost = min(mainCost , cost+mat[u][en]);
        //return cost;
    }
//    for(int i=0;i<vec.size();i++){
//        v = vec[i];
//        if(v!=-1 && v != en){
//            mn = min(mn, mat[u][v]);
//        }
//    }

    vector<int>temp;
    for(int i=0;i<vec.size();i++){
        v = vec[i];
        if(v != -1 && v != en){
                temp = vec;
                temp[i] = -1;
                //msg(u,v)
                findPath(v, cost+mat[u][v],n+1,temp);
        }

    }
}

int main(){
    vector<int>vec;
    cin >> n >> r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a;
            mat[i+1][j+1] = a;
            if(a == 0){
                mat[i+1][j+1] = 99999;
            }
        }
    }
    cin.ignore();
    for(int i=0;i<r;i++){
        getline(cin,str);
        stringstream ss(str);
        beg = -1;
        while(ss >> a){
            if(beg == -1){
                beg = a;
            }else{
                vec.push_back(a);
            }
        }
        en = vec[vec.size()-1];
        vec.pop_back();
//        for(int i=0;i<vec.size();i++){
//            cout << vec[i] << "" ;
//        }
//        cout << endl;
        totalN = vec.size();
        mainCost = INT_MAX;
        findPath(beg,0,0,vec);
        if(mainCost >= 99999){
            cout << 0 << endl;
        }else{
            cout << mainCost << endl;
        }
        //msg2(beg, findPath(beg,0,0, vec),mainCost)
        vec = vector<int>();

    }
    return 0;
}
