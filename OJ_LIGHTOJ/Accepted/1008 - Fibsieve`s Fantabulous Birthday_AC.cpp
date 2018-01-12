#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long long int x,y,n,sq,midVal, caseCounter =1,tc;
    cin >> tc;
    while(tc--){
    cin >> n;
    sq = ceil(sqrt(n));
    midVal = sq*sq - (sq-1);
    if(n > midVal){
        if(sq%2 == 0){
            x = sq;
            y = sq*sq -n +1;
        }else{
            x = sq*sq - n+1;
            y= sq;
        }
    }else if(n <midVal){

        if(sq%2 == 0){
            x = sq - (midVal-n);
            y= sq;
        }else{
            x = sq;
            y = sq - (midVal-n);
        }
    }else{
        x = sq;
        y = sq;
    }
    cout << "Case "<< caseCounter++ << ": " << x <<" " << y << endl;
    }


    return 0;
}
