// easy funny, look like disjoint set union first.

#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int tc,counter = 0;
    cin >> tc;
    map<long long int, long long int>friends, ffriends;
    long long int n,m,a,b;
    while(tc--){
        cin >> a >> m;
        if(!friends[a]){
            if(ffriends[a]){
                counter--;
            }
            friends[a] = 1;
        }
        while(m--){
            cin >> b;
            if(!friends[b] && !ffriends[b]){
                counter++;
                ffriends[b] = 1;
            }
        }
    }
    cout << counter << endl;
    return 0;
}
