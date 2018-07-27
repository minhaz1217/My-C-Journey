#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    long long int n,i,j,k,minCost, myCost,curr,counter, curr2, firstMax = INT_MIN, secondMax=INT_MIN, thirdMax=INT_MIN;


    scanf("%lld", &n);
    long long int arr[n], cost[n],arr2[n];
    for(i=0;i<n;i++){
        scanf("%lld", &arr[i]);
        arr2[i] = arr[i];
    }
    sort(arr2, arr2+n);
    curr = arr2[n-1];
    counter = 1;
    for(i = n-1;i>=0 && counter<3;i--){
        if(arr2[i] < curr){
            counter++;
            curr = arr2[i];
        }

    }
    //cc(curr)
    //msg2(firstMax, secondMax, thirdMax)
    for(i=0;i<n;i++){
        scanf("%lld", &cost[i]);
    }
    minCost = INT_MAX;
    for(i=0;i<n;i++){
        counter = 1;
        if(arr[i] <= curr){
        for(j=i;j<n;j++){
            if(arr[j] > arr[i]){
                for(k=j;k<n;k++){
                        //cc(arr[k])
                    if(arr[k] > arr[j]){
                        minCost = min(minCost, cost[i] + cost[j] + cost[k]);
                        //cc(minCost)
                    }
                }
            }
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
