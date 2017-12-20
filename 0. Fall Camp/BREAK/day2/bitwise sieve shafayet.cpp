#include<bits/stdc++.h>
using namespace std;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define SIEVE_MX 1000004

bool check(int pos)
{
    return (bool)(SIEVE_MX & (1<<pos));
}
int Set(int pos)
{
    long long int nn = SIEVE_MX;
    return nn = nn| (1<<pos);
}
int N =SIEVE_MX;
int PRIME[SIEVE_MX/32];
void bitWiseSieve()
{
    int i, j, sqrtN;
    sqrtN = int( sqrt( SIEVE_MX ) );
    for( i = 3; i <= sqrtN; i += 2 )
    {
        if( check(i%32)==0)
        {
            for( j = i*i; j <= SIEVE_MX; j += 2*i )
            {
                PRIME[j/32]=Set(j % 32)   ;
            }
        }
    }
}

int main()
{
    bitWiseSieve();
    c(check(3))
    return 0;
}
