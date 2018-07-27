#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int n,i,j,k,minCost, myCost,curr,counter, curr2, sz1,sz2, v;


    scanf("%lld", &n);
    long long int arr[n], cost[n],arr2[n];
    vector<long long int>vec[n];
    for(i=0;i<n;i++){
        scanf("%lld", &arr[i]);
        arr2[i] = arr[i];
    }
    for(i=0;i<n;i++){
        scanf("%lld", &cost[i]);
        //arr2[i] = arr[i];
    }
    sort(arr2, arr2+n);
    for(i=0;i<n;i++){
        curr = arr[i];
        //vec[i].push_back(cost[i]);
        for(j=i;j<n;j++){
            if(arr[i] < arr[j]){
                vec[i].push_back(j);
            }
        }
    }
    minCost = INT_MAX;
    for(i=0;i<n;i++){
        myCost = cost[i];
        sz1 = vec[i].size();
        for(j=0;j<sz1;j++){
            v = vec[i][j];
            sz2 = vec[v].size();
            for(k=0;k<sz2;k++){
                minCost = min(minCost, cost[i] + cost[v] + cost[vec[v][k]]);
            }
        }
    }


    if(minCost == INT_MAX){
        printf("-1\n");
    }else{
        printf("%lld\n", minCost);
    }
    //cout << minCost << endl;
    return 0;
}
