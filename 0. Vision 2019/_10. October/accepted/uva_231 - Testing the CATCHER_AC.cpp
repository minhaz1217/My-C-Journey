/*
Minhazul Hayat Khan
minhaz1217.github.io
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link: https://uva.onlinejudge.org/external/2/231.pdf
Date : 20 / October / 2019
Comment: basic LIS problem.
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


int lis(vector<long long int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<long long int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int main(){
    long long int a,ans,caseCounter = 1;
    while(1){
        vector<long long int>vec;
        cin >> a;
        if(a == -1){
            break;
        }else{
            vec.push_back(a);
            while(1){
                cin >> a;
                if(a == -1){
                    break;
                }
                vec.push_back(a);
            }
            reverse(vec.begin(),vec.end());
            ans = lis(vec);
            if(caseCounter>1){
                cout << endl;
            }
            cout << "Test #"<<caseCounter++<<":\n";
            printf("  maximum possible interceptions: %d\n", ans);

        }
    }
    return 0;
}
