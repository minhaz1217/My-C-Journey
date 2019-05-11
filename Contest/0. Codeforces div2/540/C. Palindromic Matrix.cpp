/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 19 / February / 2019
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
long long int mat[24][24];
long long int arr[1005];
int main(){
    int n,a,flag = 1;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a;
            arr[a]++;
            //cin >> mat[i][j];
        }
    }
    deque<int> posCounter[5];
    for(int i=0;i<1005;i++){
            while(arr[i]/4.0>=1){
                posCounter[4].push_back(i);
                arr[i]-=4;
            }
            while(arr[i]/2.0>=1){
                posCounter[2].push_back(i);
                arr[i]-=2;
            }
            if(arr[i] == 1){
                posCounter[1].push_back(i);
            }
    }
    if(n%2 != 0){
        // this is odd
        if(posCounter[1].size()!= 1){
            flag = 0;
        }
        //filling out the middle part
        l = 0;
        r = n-1;
        mid = floor(n/2.0);
        if(posCounter[2].size() != mid*2){
            while(posCounter[2].size()<mid*2){
                select = posCounter[4].front();
                posCounter[4].pop_front();
                posCounter[2].push_back(select);
                posCounter[2].push_back(select);
            }
        }
        if(posCounter[2].size() > mid*2){
            flag = 0;
        }
        while(l<r){
            select = posCounter[2].front();
            posCounter[2].pop_front();
            mat[mid][l]= select;
            mat[mid[r] = select;
            l++;r--;
        }
        l=0;
        r = n-1;
        while(l<r){
            select = posCounter[2].front();
            posCounter[2].pop_front();
            mat[mid][l]= select;
            mat[mid[r] = select;
            l++;r--;
        }
        mat[mid][l] = posCounter[1].front();

    }

    if(posCounter[1].size() >0||posCounter[2].size()>0){
        flag = 0;
    }
    if(flag == 1){
        go = ceil(n/2.0)-1;
        for(int i = 0;i<go;i++){
            for(int j=0;j<go;j++,a--){
            select = posCounter[4].front();
            posCounter[4].pop_front();
            mat[i][j] = select;
        }
    }
    if(n%2 == 0){
        st = go;
    }else{
        st = go+1;
    }
    for(int i=0;i<go;i++){
        for(int j=0;j<go;j++){
            arr[j] = mat[i][j];
        }
    }


    return 0;
}
