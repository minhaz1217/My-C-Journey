#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,a,sum,i,currMin = INT_MAX, currMinPos;
    vector<int>vec;
    cin >> n;
    sum =0 ;
    for(i=1;i<=n;i++){
        cin >> a;
        vec.push_back(a);
        if(a < currMin){
            currMin = a;
            currMinPos = i;
        }
    }
    sort(vec.begin(),vec.end());
    if(n>2){
        cout << 1 << endl << currMinPos << endl;
    }else{
        if(n==2){
            if(vec[0] == vec[1]){
                cout << -1 << endl;
            }else{
                cout << 1 << endl <<currMinPos << endl;
            }
        }else{
            cout << -1 << endl;
        }
    }

    return 0;
}
