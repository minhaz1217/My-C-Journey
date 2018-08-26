#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){

    long long int n,m,a,Max, Min,flag, ans,cMin;
    Max = INT_MIN;
    Min = INT_MAX;
    cMin = INT_MAX;
    vector<long long int>right, wrong;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a;
        right.push_back(a);
        Max = max(a, Max);
        cMin = min(a,cMin);
    }
    for(int i=0;i<m;i++){
        cin >> a;
        wrong.push_back(a);
        Min= min(a, Min);
    }
    if(Max >= Min){
        flag = 0;
    }else{
        flag = 0;
        for(int i=cMin;i< Min;i++){
            if(cMin *2 <= i && i>=Max){
                flag = 1;
                ans = i;
                break;
            }
        }
    }
    //msg(Max, Min)
    if(flag == 0){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }



    return 0;
}
