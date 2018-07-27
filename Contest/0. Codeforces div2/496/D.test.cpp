#include<bits/stdc++.h>
#define fl(n)           for(int i=0; i<n; i++)
#define pb              push_back
#define ll              long long int
#define inf             1/0.0
#define sf              scanf
#define pf              printf
#define nl              printf("\n")
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)
#define sync            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mem(a,b)        memset(a,b,sizeof(a))
#define err             cout << "OK" << endl;
#define PI              2*acos(0.0)
#define F               first
#define S               second
#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))
#define PS              system("pause")
#define MOD             100000007
#define M               1000000000000
#define MX              505

using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')
            sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

///___________________________________________________________________________________________________________________
///                              CODE STARTS FROM HERE
///-------------------------------------------------------------------------------------------------------------------

int main()
{
    string s;
    int cnt=0, d=0;

    cin >> s;
    for(int i=0; s[i]; i++)
    {
        if((s[i]-'0')%3==0)
        {
            cnt++;
            d=0;
            continue;
        }
        if(d>=1)
        {
            if((s[i-1]-'0'+s[i]-'0')%3==0)
            {
                cnt++;
                d=0;
                continue;
            }
        }
        if(d>=2)
        {
            if((s[i-2]-'0'+s[i-1]-'0'+s[i]-'0')%3==0)
            {
                cnt++;
                d=0;
                continue;
            }
        }
        d++;
    }

    cout << cnt << endl;

    return 0;
}
