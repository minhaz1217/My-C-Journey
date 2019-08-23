/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://www.codechef.com/AUG19B/problems/MSNSADM1
Date : 10 / August / 2019
Comment: no point in me solving this.
*/
 /// #include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(){
    long long int tc,n,a,mx;
    long long int arr[200];
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=0;i<200;i++){
            arr[i] = 0;
        }
        mx = INT_MIN;
        for(int i=0;i<n;i++){
            cin >> a;
            arr[i] = a*20;
        }
        for(int i=0;i<n;i++){
            cin >> a;
            mx = max(mx, max( (long long int)0, (arr[i] - a*10)) );
        }
        cout << mx << endl;
    }
    return 0;
}
