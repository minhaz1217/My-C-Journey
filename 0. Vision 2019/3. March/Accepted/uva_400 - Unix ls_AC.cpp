/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-400
Date : 19 / March / 2019
Comment: Creative string manipulation and math
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
    int n;
    while(cin >> n){
        cout << "------------------------------------------------------------" << endl;
        string str,temp;
        int maxSize,cols,k;
        vector<string>vec;
        maxSize = INT_MIN;
        for(int i=0;i<n;i++){
            cin >> str;
            maxSize = max(maxSize, (int)str.size());
            vec.push_back(str);
        }
        int cols1 = ( (60-maxSize) / (maxSize+2)) + 1;

        cols = ceil( (double)vec.size()/cols1);
        //msg(cols1, cols)
        sort(vec.begin(), vec.end());
        for(int i=0;i<cols;i++){
            //str = vec[i];
            k = i;
            str = "";
            while(k<vec.size()){
                temp = vec[k];
                while(temp.size()<maxSize){
                    temp.push_back(' ');
                }
                if(k>=cols){
                    str.push_back(' ');
                    str.push_back(' ');
                }
                str+= temp;
                k = k+cols;
            }
            cout << str << endl;
        }
    }


    return 0;
}
