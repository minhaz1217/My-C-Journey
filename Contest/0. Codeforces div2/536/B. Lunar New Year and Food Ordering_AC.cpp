#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    _INIT;
    int j;
    long long int n,m,a,t,d,currLow,sum,dish;
    vector<long long int>amount,cost;
    vector<pair<long long int, int> >vec;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a;
        amount.push_back(a);
    }
    for(int i=0;i<n;i++){
        cin >> a;
        cost.push_back(a);
        vec.push_back(make_pair(a,i));
    }
    sort(vec.begin(),vec.end());
    currLow = 0;
    for(int i=1;i<=m;i++){
        cin >> t >> d;
        sum = 0;
        if(amount[t-1] >=d){
            sum += (d*cost[t-1]);
            amount[t-1] -=d;
            d = 0;
        }else{
            sum += (cost[t-1]*amount[t-1]);
            d = d - amount[t-1];
            amount[t-1] = 0;
            for(j=currLow;j<vec.size();j++){
                dish = vec[j].second;
                if(amount[ dish ]>=d){
                    amount[ dish ] -= d;
                    sum += (cost[dish]*d);
                    d = 0;
                    break;
                }else{
                    sum += (cost[dish]*amount[dish]);
                    d -= amount[dish];
                    amount[dish] = 0;
                }
            }
            currLow = j;
        }
        /*
        for(int i=0;i<amount.size();i++){
            cout << amount[i] << " ";
        }
        cout << endl;
        */
        if(d>0){
            cout << 0 << endl;
        }else{
            cout << sum << endl;
        }
    }
    return 0;
}
