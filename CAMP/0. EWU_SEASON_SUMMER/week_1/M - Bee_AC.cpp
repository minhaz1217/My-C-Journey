#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    long int f=1,m=0,n,sum=0,pm,pf;
    while(1){
        cin >> n;
        m=0;
        f=1;
        pm =0;
        pf = 0;
        if(n == -1){
            break;
        }
        while(n--){
            pm = m;
            pf = f;
            f = pm+1;
            m = pm + pf;
        }
        cout << m << " " << f+m << endl;
    }


    return 0;
}
