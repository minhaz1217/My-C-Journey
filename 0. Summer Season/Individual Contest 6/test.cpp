#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b  << " : " << c << endl;

int main(){
    int i;
    vector<int>vec;
    for(i=1;i<=10;i++){
        vec.push_back(i);
    }
    vec.erase(0);
    for(i=0;i<vec.size();i++){
        cout << vec[i] << endl;
    }

    return 0;
}
