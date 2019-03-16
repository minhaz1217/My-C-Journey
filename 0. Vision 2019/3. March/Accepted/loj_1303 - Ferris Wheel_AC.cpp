/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: http://lightoj.com/volume_showproblem.php?problem=1303
Date : 16 / March / 2019
Comment: Hard to implement but easy if the concept is right. Also using map with pair as key was throwing RTE. Probably mp [make_pair(0,0)] == 1 throwing the error
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

int mat[40][40];

int main(){
    long long int tc,caseCounter = 1;
    cin >> tc;
    while(tc--){
        long long int n,m,down,time,visited;
        //map<pair<int,int> , int> mp;
        deque<int>vec;
        vector<int>wheel(m+2,0);
        cin >> n >> m;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mat[i][j] = 1;
                //mp[ make_pair(i,j) ] = 1;
            }
            vec.push_back(i);
        }
        down = 0;
        time = 0;
        visited = 0;
        while(visited != n*m){
            time+= 5;
            down++;
            if(down == m+1){
                down = 1;
            }
            //msg2("DOWN", down,wheel[down])
            if(wheel[down] !=0){
                vec.push_back(wheel[down]);
                wheel[down] = 0;
            }
            while(vec.size()>0){
                if(vec.front() == 0){
                    vec.pop_front();
                }else{
                    break;
                }
            }
            //cc("HI")
            for(int i=0;i<(int)vec.size();i++){
                if(mat[vec[i] ][down] == 1){
                    //msg(down, vec[i])
                    visited++;
                    wheel[down] = vec[i];
                    mat[vec[i] ][down] = 0;
                    //mp[ make_pair(vec[i],down) ] = 0;
                    vec[i] = 0;
                    break;
                }
            }
        }
        int lastFound = 0;
        for(int i=0;i<m;i++){
            down++;
            if(down == m+1){
                down = 1;
            }
            if(wheel[down] !=0){
                lastFound = i+1;
            }
        }
        cout << "Case " << caseCounter++<< ": " << time + lastFound*5 <<endl;

    }

    return 0;
}
