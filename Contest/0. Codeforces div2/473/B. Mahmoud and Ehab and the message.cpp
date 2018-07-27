#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int sz,n,k,m,i,j,a,b,currMin,sum;
    scanf("%lld%lld%lld", &n,&k,&m);
    //cin >> n >> k >> m;
    string str;
    vector<long long int>cost,group;
    vector<string>word;
    map<string, long long int>mp;
    for(i=0;i<n;i++){
        cin >> str;
        word.push_back(str);
        mp[str] = i;
    }
    for(i=0;i<n;i++){
        scanf("%lld", &a);
        cost.push_back(a);
        //mp[word[i]] = i;
    }
    for(i=0;i<k;i++){
        scanf("%lld", &a);
        currMin = INT_MAX;
        group.clear();
        for(j=0;j<a;j++){
            scanf("%lld", &b);
            currMin = min(currMin, cost[b-1]);
            group.push_back(b-1);
        }
        sz = group.size();
        //msg(currMin, sz)
        for(j=0;j<sz;j++){
            cost[group[j]] = currMin;
        }
    }
    //cc("HI")
    sum = 0;
    for(i=0;i<m;i++){
        //scanf("%s", &str);
        //cc(str)
        cin >> str;
        sum += cost[mp[str]];
    }
    cout << sum << endl;

    return 0;
}
