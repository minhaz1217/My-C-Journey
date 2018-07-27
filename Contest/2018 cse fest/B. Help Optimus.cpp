#include<bits/stdc++.h>
//#include<iostream>
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a, b) cout <<  a << " : " << b << endl;
#define msg2(a, b, c) cout <<  a << " : " << b << " : " << c << endl;
using namespace std;

int main(){
    long long int tc,d,f,l,k,x,y,i, pos,currMin;
    scanf("%lld", &tc);
    while(tc--){
        scanf("%lld %lld %lld %lld", &d, &f, &l, &k);
        i = 0;
        x = 0;
        y = 0;
        currMin = INT_MIN;
        pos = 1;
        while(x<=y){
            i ++;
            x = (d + f) * (i*i) + l;
            y = i*k;
            if((y-x) >= currMin)
            {
                currMin = (y-x);
                pos = i;
            }
            //msg(x,y)
            //i++;
        }
        cc(currMin)
        cc(i)
        printf("%lld\n", pos);
    }
    return 0;
}
