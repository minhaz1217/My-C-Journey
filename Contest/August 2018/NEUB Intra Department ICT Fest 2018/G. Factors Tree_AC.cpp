#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define SV 1000010
long long int mark[SV+2];
void sieve()
{
    int i,j,root;
    for(i=0; i<SV; i++)
    {
        mark[i] = 1;
    }
    root = sqrt(SV) + 1;
    for(i=2; i<= root; i++)
    {
        if(mark[i] == 1)
        {
            for(j=i; i*j<SV; j++)
            {
                mark[i*j] = 0;
            }
        }
    }
}
long long int  countDivisors(long long int  n)
{
    if(mark[n] == 1){
        return 1;
    }
    long long int  cnt = 0;
    long long int N = n;
    for (long long int  i = 2; i <= sqrt(N)&&n!=1; i++)
    {
        if(mark[n] == 1){
            cnt++;
            break;
        }
        if(n%i == 0){
            cnt++;
            n = n/i;
            i--;
        }
        //msg(i,n)
    }
    return cnt;
}

int main()
{
    sieve();
    mark[1] = 0;
    mark[0] = 0;
    long long int tc,a,caseCounter = 1;
    cin >> tc;
    while(tc--)
    {
        cin >> a;
        cout << "Case " << caseCounter++ << ": " << countDivisors(a) << endl;
        //cc(countDivisors(a));
    }


    return 0;
}
