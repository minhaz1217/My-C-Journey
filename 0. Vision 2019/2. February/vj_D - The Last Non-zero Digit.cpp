#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int Trailing_Zeros(int N)
{
    int sum=0;
    while(N)
    {
        sum+=N/5;
        N=N/5;
    }
    return sum;
}
int main()
{
    long long int sum,n,m,a;
    while(cin >> n >> m)
    {
        sum = 1;
        for(int i=(n-m)+1; i<=n; i++)
        {
            //sum = ((sum%1000000000)*(i%1000000000) )%1000000000;
               // msg(sum,i)
            //sum = sum*i;
            sum= (sum*i);
            if(sum%10 == 0){
                a = sum%10;
                while(a == 0){
                    sum = sum/10;
                    a = sum%10;
                }
            }
            //msg2(sum, i, sum%10)
        }
        if(n == 0){
            sum = 0;
            a = 0;
        }
        while(sum!=0){
            a = sum%10;
            if(a >0){
                break;
            }
            sum = sum/10;
        }
        cout << a << endl;
    }
    return 0;
}
