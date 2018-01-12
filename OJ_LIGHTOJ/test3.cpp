#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int i;
    string str = "101101100";
    bitset<32> b(str);
    msg(b.to_ulong(), b)
    for(i=b.to_ulong()+1;;i++){
        bitset<32> d(i);
        if(d.count() == b.count()){
            msg(d.to_ulong(), d)
            break;
        }
    }

    return 0;
}
