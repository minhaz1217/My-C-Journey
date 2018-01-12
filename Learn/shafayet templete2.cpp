//Programming Contest Template
//Shafaet Ashraf
#include <bits/stdc++.h>

#define stream istringstream
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sz(x) (int)x.size()
#define inf (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define pii pair<int,int>
#define pmp make_pair
#define uu first
#define vv second
using namespace std;
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }
template<class T> string itoa(T a){if(!a) return "0";string ret;for(T i=a; i>0; i=i/10) ret.pb((i%10)+48);reverse(all(ret));return ret;}
typedef  long long i64;
typedef unsigned long long ui64;
double log(double N,double B){  return (log10l(N))/(log10l(B)); }
vector< string > token( string a, string b ) {const char *q = a.c_str();while( count( b.begin(), b.end(), *q ) ) q++;vector< string >
	oot;while( *q ) {const char *e = q;while( *e && !count( b.begin(), b.end(), *e ) ) e++;oot.push_back( string( q, e ) );q = e;while( count( b.begin(),
	b.end(), *q ) ) q++;}return oot;
}
//bool operator < ( const node& p ) const {      return w < p.w;   }
#define on(n,pos) (n | (1LL<<(pos)))
#define off(n,pos)  n & ~(1LL<<pos)
#define ison(n,pos) (bool)(n & (1LL<<(pos)))
string toBin(int n){ string s; repv(i,10)s+=(ison(n,i)+'0');return s;}
bool eq(long double a,long double b){return fabs(a-b)<eps;}
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pks printf("Case %d: ",++ks);



bool vis[3000000];
int arr[20];
int dp[2000000][20];

bool isprime(int n)
{
	if(n==2)return 1;
	if(n==1)return 0;
	if(n%2==0)return 0;
	return vis[n]==0;
}
int main() {
	 // READ("in");
	  int n=2000000;
	  for(int i=2;i<=n;i++)
	  {
		  if(vis[i]==0)
		  {
			  for(int j=i+i;j<=n;j+=i)
			  {
					vis[j]=1;
			  }
		  }
	  }

	  cin>>n;
	  int sum=0;
	  assert(n<=18);
	  repl(i,n)
	  {
		  cin>>arr[i];
		  assert(arr[i]<=100000);
		  sum+=arr[i];
	  }


	  repl(i,n+1)
	  dp[0][i]=1;
	  for(int make=1;make<=sum;make++)
	  {

		  for(int i=n;i>=1;i--)
		  {
			  int coin=arr[i];
			  int ret1=0,ret2=0;

			  if(make-coin>=0)
			  {
				  ret1=dp[make-coin][i+1];

			  }
			  ret2=dp[make][i+1];

			  dp[make][i]=ret1||ret2;

		  }
	  }

	  int ans=0;
	  for(int i=1;i<=sum;i++)
	  {
		  if(isprime(i) and dp[i][1]) {

			  ans++;
		  }
	  }

	  cout<<ans<<endl;


	  return 0;
}
