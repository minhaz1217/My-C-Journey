#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

int main(){
    int n,a,down,up,minsum,x,sum=0;
    vector<int>vec;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;

        vec.push_back(a);
    }
    sum = 0;
    minsum = INT_MAX;
    for(int x=1;x<=n;x++){
        for(int i=1;i<=n;i++){
            down = abs(x - i) + abs(i - 1) + abs(1 - x);
            up = abs(x - 1) + abs(i - 1) + abs(i - x);
            //msg(down, up)
            sum = sum + (down+up)*vec[i-1];
        }
        minsum = min(sum, minsum);

        sum = 0;
    }
    cout << minsum << endl;




    return 0;
}
