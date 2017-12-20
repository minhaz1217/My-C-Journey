#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int n,q, lastAns =0,a,b,c,calc,xr;
    cin>> n >> q;
    vector<int> v[n];
    while(q--){
        cin >> a >> b >> c;
        if(a==1){
            xr = b^lastAns;
            /*
            if(xr < n){
                calc = xr;
            }else{
                calc = floor(xr%n);
            }
            */
            //msg(xr, calc)
                calc = (xr%n);
            v[ calc ].push_back(c);
        }else if(a ==2){
            xr = b^lastAns;
            /*
            if(xr < n){
                calc = xr;
            }else{
                calc = floor(xr%n);
            }
            */
            calc = (xr%n);
            //msg(xr, calc)
            lastAns = v[ calc ][c%v[calc].size()];
            cout << lastAns << endl;
        }
    }
    return 0;
}
