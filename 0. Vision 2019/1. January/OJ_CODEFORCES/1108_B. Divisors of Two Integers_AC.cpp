#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    long long int tc,a;
    long long int arr[20000];
    vector<long long int>vec;
    cin >> tc;
    for(int i=0;i<20000;i++){
        arr[i] = 0;
    }
    for(int i=0;i<tc;i++){
        cin >> a;
        vec.push_back(a);
        arr[a]++;
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(),vec.end());
    for(int i=1;i<vec.size();i++){
        if(arr[ __gcd(vec[0], vec[i]) ] ==2){
            cout << vec[0] << " " << vec[i] << endl;
            break;
        }
    }


    return 0;
}
