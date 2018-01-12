#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define msg(a,b) cout << a << " : " << b << endl;

#define myInput %lld
int main() {
    int n=2, i;
    cin >> n;
    bitset<32> b(n);
    msg(n, b)
    for(i=n+1;;i++){
        bitset<32> d(i);
        if(d.count() == b.count()){
            msg(d.to_ulong(), d)
            break;
        }
    }
    return 0;
}
