#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int n,x,sum,minimum,minimumCount,a,remaining;
    vector<long long int> vec;
    cin >> n >> x;
    sum = 0;
    for(int i=0;i<n;i++){
        cin >> a;
        sum += a;
        vec.push_back(a);
    }
    if(sum < x){
        cout << -1 << endl;
    }else{
        sort(vec.begin(),vec.end());
        minimum = vec[0];
        minimumCount = 0;
        sum = 0;
        for(int i=0;i<vec.size();i++){
            sum += (vec[i] - minimum);
        }
        if(sum >= x){
            cout << minimum << endl;
        }else{
            //cc("HI")
            remaining = x - sum;
            cout << (int)(minimum - ceil((double)remaining/(double)n)) << endl;
            //cc(x)
            //cout << minimum << endl;
        }
    }

    return 0;
}
