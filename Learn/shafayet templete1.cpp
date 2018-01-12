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



int b[100002];
vector<int>sav[100002];
int main() {
	  //READ("in");
	  int n,m;
	  cin>>n>>m;
      assert(n>=1 and n<=100000);
      assert(m>=1 and m<=1000000);
    rep(i,n){cin>>b[i];assert(b[i]>=1 and b[i]<=10000);}
	  sort(b,b+n);

	  set<int>ms;
	  rep(i,m)
	  {
		  int p,c;
		  cin>>p>>c;
          assert(p>=1 and p<=100000);
          assert(c>=1 and c<=100);
		  sav[p].pb(c);
		  ms.insert(p);

	  }


	  int cc=0;
	  int p=0;
	  priority_queue<int>pq;
	  foreach(it,ms)
	  {
		  int a=*it;
		  if(p>=n) break;
		  if(a>b[p])
		  {
			  while(p<n and a>b[p])
			  {
				  int cap=pq.top();
				  pq.pop();
				  p+=cap;
				  cc+=1;
				//  cout<<">>>>"<<cap<<endl;
			  }
		  }
		  rep(j,sz(sav[a]))
		  {
			//	cout<<"P"<<sav[a][j]<<endl;
				pq.push(sav[a][j]);
		  }

	  }
	  while(p<n)
	  {
		  int cap=pq.top();
		  cc+=1;
		  // cout<<">>>>"<<cap<<endl;
		  pq.pop();
		  p+=cap;
	  }

	  int ans=m-sz(pq);
	  cout<<cc<<endl;
	  return 0;
}
