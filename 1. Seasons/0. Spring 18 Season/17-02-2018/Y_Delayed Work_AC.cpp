#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : "<<b << endl;


int main(){
    double k,p,x,mm,days,sum,i;
    cin >> k  >> p >> x;
    mm = (double)INT_MAX;
    for(i=1;;i++){
        days = k/i;
        sum = i *x + days*p;
        mm = min(mm, sum);
        if(i*x > days*p){
           // msg(i*x, days*p)
            break;
        }
    }
    printf("%.3lf", mm);
    return 0;
}
