/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-12032
Date : 06 / August / 2019
Comment:problem recommended by PICCHI. at first glance seems normal implementation but actually is a binary search problem.
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
    long long int tc,n,a,l,r,mid,temp,flag,caseCounter = 1,ans,prev;
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<long long int> vec;
        prev = 0;
        for(int i=0;i<n;i++){
            cin >> a;
            vec.push_back(a-prev);
            prev =a;
        }
        l = 1;
        r = 10000400;
        while(l<r-1){
            mid = (l+r) /2;
            flag = 1;
            temp = mid;
            for(int i=0;i<vec.size();i++){
                if(vec[i] > temp){
                    flag = 0;
                    break;
                }else if(vec[i] == temp){
                    temp--;
                }
            }

            //msg3(l,r, mid, flag)
            if(flag){
                ans = mid;
                r = mid;
            }else{
                l = mid;
            }
        }
        if(n == 1){
            ans = vec[0];
        }
        cout << "Case " << caseCounter++ << ": " << ans << endl;
    }

    return 0;
}
