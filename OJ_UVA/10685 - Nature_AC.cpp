#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define MX 5004
int p[MX];
int members[MX];

int findSet(int x){
    if(p[x] == x){
        return x;
    }
    return findSet(p[x]);
}
int unionSet(int x, int y){
    x = findSet(x);
    y = findSet(y);
    if(x != y){
        p[y] = x;
        members[x] += members[y];
    }


}


int main(){
    int a,b,i,big;
    string str, str1, str2;
    while(1){
        cin >> a >> b;
        map<string, int>mp;
        if(a== 0 && b == 0){
            break;
        }
        for(i=1;i<=a;i++){
            p[i] = i;
            members[i] = 1;
        }
        for(i=1;i<=a;i++){
            cin >> str;
            mp[str] = i;
        }
        for(i=1;i<=b;i++){
            cin >> str1 >> str2;
            unionSet(mp[str1], mp[str2]);
        }
        big = INT_MIN;
        for(i=1;i<=a;i++){
            big = max(big, members[i]);
        }
        cout << big << endl;
    }

    return 0;
}
