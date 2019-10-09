/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://codeforces.com/contest/1241/problem/C
Date : 10 / October / 2019
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
    long long int l,prevMid,r,mid,tc,n,a,b,flag ,k;
    long double sum;
    double x,y;
    scanf("%lld", &tc);
    while(tc--){
        vector<long long int>vec1;
        vector<double> vec2,vec3;
        scanf("%lld", &n);
        //cin >> n;
        for(int i=0;i<n;i++){
            scanf("%lld", &a);
            vec1.push_back(a);
        }

        scanf("%lf%lld", &x,&a);
        scanf("%lf%lld", &y,&b);
        scanf("%lld", &k);
        //cin >> k;
        for(int i=1;i<=n;i++){
            sum = 0;
            if(i%a == 0){
                sum = sum + (x/100.0);
            }
            if(i%b == 0){
                sum+= (y/100.0);
            }
            vec2.push_back(sum);
        }
        sort(vec1.begin(), vec1.end(), greater<long long int>());
        l = 0;
        r = n;
        prevMid = -1;
        while(l<r){
            mid = ((l+r)/2.0);
//            msg2(l,r,mid)
            vec3 = vector<double>(vec2.begin(),vec2.begin()+mid);
            sort(vec3.begin(),vec3.end(),greater<double>());
            sum = 0;
            for(int i=0;i<vec3.size();i++){
                sum += vec3[i]*vec1[i];
                if(sum>=k || vec3[i] == 0){
                    break;
                }
            }
            if(sum >= k){
                r = mid;
            }else{
                l = mid;
            }
            if(mid == prevMid){
                break;
            }else{
                prevMid = mid;
            }
        }
//        msg("ANS", mid)
        vec3 = vector<double>(vec2.begin(),vec2.begin()+r);
        sort(vec3.begin(),vec3.end(),greater<double>());
        sum = 0;
        for(int i=0;i<vec3.size();i++){
            sum += vec3[i]*vec1[i];
            if(sum>=k || vec3[i] == 0){
                break;
            }
        }
        if(sum >=k){
            printf("%lld\n", r);
            //cout << r << endl;
        }else{
            sort(vec2.begin(), vec2.end(), greater<double>());
            sum = 0;
            for(int i=0;i<vec2.size();i++){
                sum += vec2[i]*vec1[i];
                if(sum>=k || vec2[i] == 0){
                    break;
                }
            }
            if(ceil(sum) >= k){
                printf("%lld\n", n);
            }else{
                printf("-1\n");
            }//cout << -1 << endl;
        }
    }
    return 0;
}
