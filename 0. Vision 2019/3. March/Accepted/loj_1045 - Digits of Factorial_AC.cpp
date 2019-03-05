/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: http://lightoj.com/volume_showproblem.php?problem=1045
Date : 05 / March / 2019
Comment: easy problem but it took a long time to understand the solution.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    double tc,n,b,sum;
    int caseCounter = 1;
    vector<double>vec;
    vec.push_back(1);
    sum = 0;
    for(double i=1;i<=1000020;i++){
        sum +=(double)log10(i);
        vec.push_back(sum);
    }
    cin >> tc;
    while(tc--){
        cin >> n >> b;
        sum  = 0;
        sum = vec[n]/ log10(b);
        cout << "Case "<< caseCounter++<< ": " << (long long int)ceil(sum) << endl;
    }


    return 0;
}
