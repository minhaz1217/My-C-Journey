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

    int n,m,mn,a,j;

    cin >> n>> m;
    vector<int>arr,vec,arr2;

    arr.assign(n+10,0);
    arr2.assign(n+10,0);
    for(int i=0;i<m;i++){
        scanf("%d", &a);
        vec.push_back(a);
        arr[a]++;
    }

    mn = INT_MAX;
    //msg("MA", mn)
    for(int i=1;i<=n;i++){
        mn = min(mn, arr[i]);
    }

    //msg("MA", mn)
    for(int i=0;i<m;i++){
        if(arr2[vec[i]] <= mn){
            j = arr2[vec[i]];
            st[j].insert(vec[i]);
            //msg3("\n",vec[i], j,st[j].size())
            arr2[vec[i]]++;

            if(st[j].size() == n){
                printf("1");
            }else{
                printf("0");
            }
        }else{
            printf("0");
        }
    }

    return 0;
}
