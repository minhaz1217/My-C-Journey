#include<stdio.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
long long int bigmod(long long int a,long long int p,long long int m)
{
    if(p==0)
        return 1;

    if(p%2==0)
    {
        long long int c=bigmod(a,p/2,m);
        return ((c%m)*(c%m)%m);
    }
    else
    {
        return ((a%m)*(bigmod(a,p-1,m)%m) %m);
    }

}
int main()
{
    long long int a,b,m,sum,i;
    while(1)
    {

        scanf("%lld%lld%lld", &a, &b, &m);
        //cin >> a >> b >> m;
        if(a==0 && b == 0 && m == 0 )
        {
            break;
        }
        /*

        if(b<0){
            while(1){

            }
        }
        */

        sum = bigmod(a,b,m) %m;
        //cout << (sum%m) << endl;
        printf("%lld\n", sum);
    }

    return 0;
}
