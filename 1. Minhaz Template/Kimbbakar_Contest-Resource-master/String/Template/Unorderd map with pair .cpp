
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;


struct pair_hash {
    std::size_t operator () (const std::pair<long long,long long> &p) const {
        auto h1 = std::hash<long long>{}(p.first);
        auto h2 = std::hash<long long>{}(p.second);


        return (h1 << 30 ) ^ h2;
    }
};

unordered_map<int, int, pair_hash>maps;
int main(){
    maps[1] = 1;

    return 0;
}
