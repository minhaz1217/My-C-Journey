#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){

    int n = 9,a,b,c,i;
    vector<pair<int, pair<int,int> > >vec;
    cout << "Give edges count: ";
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a >> b >> c;
       // cout << "GOT: " << a << b << c;
        vec.push_back(make_pair(a, make_pair(b,c)));
    }
    for(i=0;i<vec.size();i++){
        a = vec[i].first;
        b = vec[i].second.first;
        c = vec[i].second.second;
        printf("mat[%d][%d] = %d;\n", a,b,c);
        printf("mat[%d][%d] = %d;\n", b,a,c);
    }


    return 0;
}
