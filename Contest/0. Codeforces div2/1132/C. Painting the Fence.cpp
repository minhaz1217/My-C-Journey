/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 05 / March / 2019
Comment:
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

#define MX 5040

bitset<MX> toggleLR(int l, int r){
    bitset<MX> ans;
    ans = ( (1<<r)-1 )^ ( (1<<(l-1))-1 );
    return ans;
}
int main(){

    long long int n,q,l,r,taken,currCount;
    bitset<MX> ans,ans2,temp;
    cin >> n >> q;
    vector<pair<int,pair<int,int> > >vec;
    for(int i=0;i<q;i++){
        cin >> l >> r;
        vec.push_back(make_pair(r-l, make_pair(l,r)));
    }
    sort(vec.begin(),vec.end());
    ans = toggleLR( vec[q-1].second.first, vec[q-1].second.second );
    currCount = ans.count();
    taken = 1;
    for(int i=q-2;i>=0;i--){
        ans2 = toggleLR(vec[i].second.first, vec[i].second.second);
        temp = (ans|ans2);
        if( temp.count() > currCount && taken< q-2){
            ans = temp;
            //msg(ans, ans2)
            currCount = ans.count();
            taken++;
        }
    }
    //msg(taken, ans)
    cout << currCount <<endl;
    return 0;
}
