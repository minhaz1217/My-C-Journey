/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-514#author=0
Date : 25 / March / 2019
Comment: Hard to understand question.
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
    long long n,a,counter =1,flag,b,mainF;
    while(cin >> n){
        if(counter>1){
            cout << endl;
        }
        if(n == 0){
            break;
        }
        counter++;
        while(1){

            mainF = 0;
            stack<long long int>st2;
            cin >> a;
            if(a == 0){
                break;
            }
            b = 1;
            flag = 0;
            while(flag == 0){
                if(st2.size()>0){
                    if(st2.top() == a){
                        msg("MATCHED", a)
                        st2.pop();
                        flag = 1;
                        continue;
                    }
                }
                if(a != b){
                    st2.push(b);
                }else{
                    flag = 1;
                }
                b++;
                if(b>n){
                    mainF = 1;
                    break;
                }
            }
            for(int i=1;i<n;i++){
                cin >> a;
                flag = 0;
                while(flag == 0){
                    if(st2.size()>0){
                        if(st2.top() == a){
                            st2.pop();
                            flag = 1;
                            continue;
                        }
                    }
                    if(a != b){
                        st2.push(b);
                    }else{
                        flag = 1;
                    }
                    b++;
                    if(b>n){
                        mainF = 1;
                        break;
                    }
                }
            }
            if(st2.size() == 0){
                cout << "Yes"<<endl;
            }else{
                cout << "No" <<endl;
            }
        }
    }
    return 0;
}
