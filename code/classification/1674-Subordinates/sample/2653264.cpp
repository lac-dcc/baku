#include <bits/stdc++.h>
 
#define forr(i, a, b) for (int i = a; i < b; i++)
#define forn(i, n) forr(i, 0, n)
#define rforr(i, a, b) for (int i = b - 1; i >= a; i--)
#define rforn(i, n) rforr(i, 0, n)
#define db(v) cout << #v << " = " << (v) << '\n';
#define bn '\n'
#define pb(v) push_back(v)
#define mkp(i, j) make_pair(i, j)
#define pow2(x) ((x) * (x))
#define med(a, b) ((a + b) / 2)
using namespace std;
 
#define IOS_HACK                                                               \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);                                                            \
  cout.tie(nullptr);
 
#ifndef ONLINE_JUDGE
#define FREOPEN                                                                \
  assert(freopen("input.txt", "r", stdin));                                    \
  assert(freopen("output.txt", "w", stdout));
#else
#define FREOPEN ;
#endif
 
using ll = long long;
using ui = unsigned int;
using ii = pair<int, int>;
using ull = unsigned long long;
using vi = vector<int>;
 
const ll MAXN = 2e5 + 100, MAXVAL = 2e6 + 100, MOD = 1e9 + 7, INF = 1e9 + 7;
 
template <class A, class B> ostream &operator<<(ostream &strm, pair<A, B> p)
{
  return strm << "{" << p.first << ";" << p.second << "}";
}
 
vi G[MAXN];
 
vi euler_tour;
bool visto[MAXN];
int cant_sub[MAXN];
 
void dfs(int start)
{
  int ini,fini;
  euler_tour.pb(start);
  ini=euler_tour.size()-1;
  for(auto v:G[start])
    if(!visto[v])
    {
      visto[v]=true;
      dfs(v);
    }
  euler_tour.pb(start);
  fini=euler_tour.size();
  cant_sub[start]=(fini-ini-2)>>1;
}
 
int main()
{
  IOS_HACK;
  FREOPEN;
  int n;
  cin>>n;
  forn(i,n-1)
  {
    int p;
    cin>>p;
    G[p-1].pb(i+1);
  }
  dfs(0);
  forn(i,n)
    cout<<cant_sub[i]<<" ";
  return 0;
}
