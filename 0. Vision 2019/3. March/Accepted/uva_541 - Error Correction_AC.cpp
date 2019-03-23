/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-541
Date : 23 / March / 2019
Comment: Easy problem.
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
    long long int n,counter1, counter2, sum;
    long long int row[104], col[104], rows, cols, mat[104][104];
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=0;j<n;j++){
                cin >> mat[i][j];
                sum += mat[i][j];
            }
            row[i] = sum;
        }

        for(int i=0;i<n;i++){
            sum = 0;
            for(int j=0;j<n;j++){
                sum += mat[j][i];
            }
            col[i] = sum;
        }
        counter1 = 0;
        counter2 = 0;
        for(int i=0;i<n;i++){
            if(col[i] %2 !=0){
                counter1++;
                cols = i;

            }
            if(row[i]%2 != 0){
                counter2++;
                rows = i;
            }
        }
        //msg(counter1, counter2)
        if(counter1+counter2 == 0){
            cout << "OK" << endl;
        }else if(counter1 == 1 && counter2 == 1){
            cout << "Change bit (" << rows +1<< "," << cols +1<<")"<<endl;
        }else{
            cout << "Corrupt" << endl;
        }
    }

    return 0;
}
