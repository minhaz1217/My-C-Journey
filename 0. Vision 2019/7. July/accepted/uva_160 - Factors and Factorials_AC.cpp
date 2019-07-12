/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-160
Date : 12 / July / 2019
Comment: presentation was a pain.
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
vector<int>prime;


int main(){
    long long int mark[100];
    long long int flag, n,num,counter,len;
    for(int i=2;i<=150;i++){
        flag = 1;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            prime.push_back(i);
        }
    }

    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        for(int i=0;i<prime.size();i++){
            mark[i] = -1;
        }

        for(int i=1;i<=n;i++){
            num = i;
            for(int j=0;prime[j]<=num;j++){
                if(num%prime[j] == 0){
                    if(mark[j] == -1){
                        mark[j] = 0;
                    }
                    while(num%prime[j] == 0){
                        num = num/prime[j];
                        mark[j]++;
                        //msg(mark[j], prime[j])
                    }
                }
            }
        }
        printf("%3lld! =", n);
        //cout << n << "! =";
        len = 6;
        counter = 0;
        for(int i=0;i<prime.size();i++){
            if(mark[i] == -1){
                break;
            }

            if(counter == 15){
                counter = 0;
                cout << endl;
                for(int j=0;j<len;j++){
                    cout << " ";
                }
            }
            printf("%3lld", mark[i]);
            counter++;
        }
        cout <<endl;
    }

    return 0;
}
