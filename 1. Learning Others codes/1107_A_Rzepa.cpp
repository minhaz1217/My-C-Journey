/*
4
6
654321
4
1337
2
33
4
2122

--output--
YES
2
6 54321
YES
2
1 337
NO
YES
2
2 122

*/
//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
//~ #pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define erase_duplicates(x) sort(all(x)); (x).resize(distance((x).begin(), unique(all(x))));


using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<
T,
null_type,
less<T>,
rb_tree_tag,
tree_order_statistics_node_update>;

//X.find_by_order(k); - zwraca iterator na k-ty element (numeracja od zerowego)
//X.order_of_key(k); - zwraca liczbę elementów ostro mniejszych niż k

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<LL> VLL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef long double LD;
typedef pair<LD,LD> PLD;
typedef vector<LD> VLD;
typedef vector<PLD> VPLD;

template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<" = "<<h<<", "; _dbg(sdbg+1, a...);
}

#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define cerr if(0)cout
#endif

const int maxn = (1e6)+7;
const int maxk = 20;
const int inf = (1e9)+7;
const LL LLinf = ((LL)1e18)+7LL;
const LD eps = 1e-9;
const LL mod = 1e9+7;

// ***************************** CODE ***************************** //

int tab[maxn];

int main()
{
	_upgrade
  int q;
  cin>>q;
  while(q--)
  {
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
      char c;
      cin>>c;
      tab[i] = c - '0';
    }
    if(n == 2 && tab[0] >= tab[1])
    {
      cout<<"NO\n";
    }
    else
    {
      cout<<"YES\n2\n";
      cout<<tab[0]<<" ";
      for(int i = 1;i < n;i++)
        cout<<tab[i];
      cout<<"\n";
    }
  }

	return 0;
}
