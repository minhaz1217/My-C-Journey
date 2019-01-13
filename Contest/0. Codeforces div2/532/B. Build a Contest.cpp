#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

set<int>st[ 100500];
int main(){

    int n,k,a,m,pnt,j;
    cin >> n >> m;

    set<int>::iterator it;
    pnt = 0;
    for(int i=0;i<m;i++){
        cin >> a;
        //msg("VAL", a)
        j = pnt;

        //msg2("INS", a, j)
        it = st[j].find(a);
        while(it!=st[j].end())
        {
            j++;
            it = st[j].find(a);
            //msg2("\nHI", j,st[j].size())
        }
        st[j].insert(a);
        if(st[j].size() == n){
            cout << 1;
            pnt++;
        }else{
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}
