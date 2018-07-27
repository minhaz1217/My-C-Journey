#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int n,low,high,i,a,currEven, currOdd,even = 0, odd = 0;
    vector<int>vec;
    cin >> n;
    low = INT_MAX;
    high = INT_MIN;
    for(i=0;i<n/2;i++){
        cin >> a;
        vec.push_back(a);
        //arr[a] = 1;
        low = min(a, low);
        high = max(a,high);
    }
    sort(vec.begin(), vec.end());
    currEven = n;
    currOdd = n-1;
    for(i=vec.size()-1;i>=0;i--){
        even += abs(currEven - vec[i]);
        odd += abs(currOdd - vec[i]);
        currEven -= 2;
        currOdd -= 2;
        //msg(even, odd)
    }
    low = min(even, odd);
    currEven = 2;
    currOdd = 1;
    for(i=0;i< vec.size();i++){
        even += abs(currEven - vec[i]);
        odd += abs(currOdd - vec[i]);
        currEven += 2;
        currOdd += 2;
        //msg(even, odd)
    }
    low = min(even, low);
    low = min(odd, low);
    cout << low << endl;
    return 0;
}
