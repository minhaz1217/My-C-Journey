#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int n,sum=0,a,j;
    vector<long long int>vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(), vec.end());
    j = vec.size()-1;
    for(int i=0;i<n/2;i++){
        sum = sum + ( (vec[i]+vec[j])*(vec[i]+vec[j]));
        j--;
    }
    cout << sum << endl;
    return 0;
}
