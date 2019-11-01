/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 28 / October / 2019
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


int main(){
    long long int caseCounter = 1,tc,zo,oz,z1,z2,o1,o2,ans,q,mn;
    string str1,str2;
    cin >> tc;
    while(tc--){
        zo = oz = z1 = z2 = o1 = o2 = 0;
        cin >> str1 >> str2;
        for(int i=0;i<str1.size();i++){
            if(str1[i] == '0' && str2[i] == '1'){
                zo++;
            }
            if(str1[i] == '1' && str2[i] == '0'){
                oz++;
            }
            if(str1[i] == '0'){
                z1++;
            }
            if(str1[i] == '1'){
                o1++;
            }
            if(str2[i] == '0'){
                z2++;
            }
            if(str2[i] == '1'){
                o2++;
            }
        }
        q = str1.size() - (z1 + o1);
        ans = min(zo, oz);
        z1 -= ans;
        z2 -= ans;
        o1 -= ans;
        o2 -= ans;
        oz -= ans;
        zo -= ans;
        ans = ans + (oz + zo);
        msg("ANS" , ans)

        mn = min(z1,z2);
        z1 -= mn;
        z2 -= mn;

        mn = min(o1,o2);
        o1 -= mn;
        o2 -= mn;

        if(z2 > 0){
            ans += z2;
            q = q - z2;
        }
        if(o2 > 0){
            ans += o2;
            mn = min(o2, z1);
            o2 -= z1;
            q = q - o2;
        }
//        msg2(zo,oz, q)
        if(q<0){
            ans = -1;
        }
        cout << "Case " << caseCounter++ << ": " << ans << endl;
    }
    return 0;
}
