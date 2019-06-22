/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name: Get the containers
Problem Link: https://vjudge.net/problem/LightOJ-1076
Date : 22 / June / 2019
Comment: got the true flavour of bisection binary search.
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
    long long int tc,n,m,mx,sum,l,prevl, prevr, r,mid,counter,a,curr,caseCounter =1 ;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        vector<long long int > vec;
        mx = INT_MIN;
        sum = 0;
        for(int i=0;i<n;i++){
            cin >> a;
            vec.push_back(a);
            mx = max(a,mx);
            sum += a;
        }
        l = 0;
        r = sum*sum;
        curr = INT_MAX;
        while(l<r){
            prevl = l;
            prevr = r;
            mid = (l+r)/2;
            sum = 0;
            counter = 0;
            for(int i=0;i<vec.size();i++){
                sum += vec[i];
                if(sum >mid){
                    sum = 0;
                    i--;
                    //sum = vec[i];
                    counter++;
                }
                if(counter > m){
                    break;
                }
            }

            if(sum != 0){
                counter++;
            }
            //msg2(l,r,mid)
            //msg(mid, counter)
            if(counter <= m){
                curr = min(mid, curr);
                //msg(l, curr)
            }
            if(counter > m){
                l = mid;
            }else{
                r = mid;
            }
            if(l ==prevl && r == prevr){
                break;
            }
        }
        cout << "Case " << caseCounter++ << ": " << curr << endl;
    }
    return 0;
}
