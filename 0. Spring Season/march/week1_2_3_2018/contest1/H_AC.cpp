//http://codeforces.com/gym/101498/problem/A
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
int arr[999994];
int main(){
    int tc,lw,k,a,big,i,ml,curr;
    string str;
    cin >> tc;
    while(tc--){
        for(i=11111;i<=99999;i++){
            arr[i] = 0;
        }
        cin >> k;
        lw = INT_MAX;
        ml = INT_MIN;
        big = INT_MIN;
        while(k--){
            cin >> str >> a;
            arr[a]++;
            lw = min(lw, a);
            ml = max(ml,a);
        }

        for(i=lw;i<=ml;i++){
            if(big < arr[i]){
                big = arr[i];
                curr = i;
            }
        }
        cout << curr << endl;

    }

    return 0;
}
