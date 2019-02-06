/*
https://codeforces.com/contest/1105/problem/C
9 9 99
output: 711426616

2 1 3
output : 3

*/
#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<map>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;

using namespace std;
long long n,m,i,j,k,dp[200005][3],l,r,f[3],mod=1e9+7;
int main()
{
	cin>>n>>l>>r;l+=2;r+=3;
	fz0k(i,3)
	{
		f[i]=(r-i)/3-(l-i)/3;
	}
	for(int i=0;i<3;i++){
        msg(i, f[i])
	}
	dp[0][0]=1;
	fz0k(i,n)
	{
		fz0k(j,3)
		{
			fz0k(k,3)
			{
				(dp[i+1][(j+k)%3]+=dp[i][j]*f[k])%=mod;
			}
		}
	}
	cout<<dp[n][0]<<endl;
	return 0;
}
