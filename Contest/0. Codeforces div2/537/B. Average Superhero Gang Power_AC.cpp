#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    double n,k,m,a,sum,mCount,currAvg,rem,mem,mn,mx,possibleOp;
    vector<double>vec;
    cin >> n >> k >> m;
    for(int i=0;i<n;i++){
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    sum = 0;
    currAvg = 0;
    for(int i=vec.size()-1;i>=0;i--){
        sum += vec[i];
        mem = n-i;
        //msg2(i,mem,sum)
        if(m - (i) >=0){
            rem = m-i;
           // msg("REM", rem)
            mn = min( rem/mem,k);
            possibleOp = min(mn*mem, rem);
            //msg("POSS", possibleOp)
            //msg("MIN", mn*mem)
            currAvg = max( (sum+(possibleOp )) / mem , currAvg);
        }
    }
    printf("%.20f\n",currAvg);

    return 0;
}
