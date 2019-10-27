/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://onlinejudge.org/external/126/12626.pdf
Date : 28 / October / 2019
Comment: easy problem.
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
    long long int tc,mCount,aCount, rCount, gCount,iCount,tCount,ans;
    string str;
    cin >> tc;
    while(tc--){
        cin >> str;
        mCount = 0;
        aCount = 0;
        rCount = 0;
        gCount = 0;
        iCount = 0;
        tCount = 0;
        for(int i=0;str[i];i++){
            if(str[i] == 'M'){
                mCount++;
            }else if(str[i] == 'A'){
                aCount++;
            }else if(str[i] == 'R'){
                rCount++;
            }else if(str[i] == 'G'){
                gCount++;
            }else if(str[i] == 'I'){
                iCount++;
            }else if(str[i] == 'T'){
                tCount++;
            }
        }
        ans = min(mCount, min(aCount/3, min(rCount/2, min(gCount, min(iCount, tCount)))));
        cout << ans << endl;
    }
    return 0;
}
