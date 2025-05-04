// Problem: Prefix Sum Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2166
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Username: BrehamPie
// Created on: 11:17:09 02-03-2023
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef BrehamPie
#include <debug.h>
#else
#define debug(args...)
#endif
using namespace std;
using namespace __gnu_pbds;
mt19937 myrand(chrono::steady_clock::now().time_since_epoch().count());
#define pb push_back
#define mem(x, i) memset(x, i, sizeof x)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef long double ld; //%Lf
 
template <typename T>using orderedSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(k) - number of element strictly less than k.",find_by_order(k) - k'th element in set.(0 indexed)(iterator)"
ll powmod(ll a,ll b,ll MOD){ll res=1;a%=MOD;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
const int mod = 1e9+7;
const int mx = 2e5+3;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-12;
/*edit:data,combine,build check datatype*/
vector<int>a(mx);
template<typename T>
struct SegmentTree {
#define lc (C << 1)
#define rc (C << 1 | 1)
#define M ((L+R)>>1)
  struct data {
    T pref_sum;
    T ttl_sum;
    data() :pref_sum(-LL_INF),ttl_sum(0) {};
  };
  vector<data>st;
  vector<bool>isLazy;
  vector<T>lazy;
  int N;
  SegmentTree(int _N) :N(_N) {
    st.resize(4 * N);
    isLazy.resize(4 * N);
    lazy.resize(4 * N);
  }
  void combine(data& cur, data& l, data& r) {
    cur.pref_sum = max(l.pref_sum,l.ttl_sum+r.pref_sum);
    cur.ttl_sum = l.ttl_sum+r.ttl_sum;
  }
  void push(int C, int L, int R) {
    if (!isLazy[C]) return;
    if (L != R) {
      isLazy[lc] = 1;
      isLazy[rc] = 1;
      lazy[lc]= lazy[C];
      lazy[rc] = lazy[C];
    }
    st[C].pref_sum = lazy[C];
    st[C].ttl_sum = lazy[C];
    lazy[C] = 0;
    isLazy[C] = false;
  }
  void build(int C, int L, int R) {
    if (L == R) {
      st[C].pref_sum = a[L];
      st[C].ttl_sum = a[L];
      return;
    }
    build(lc, L, M);
    build(rc, M + 1, R);
    combine(st[C], st[lc], st[rc]);
  }
  data Query(int i, int j, int C, int L, int R) {
    push(C, L, R);
    if (j < L || i > R || L > R) return data();  // default val 0/INF
    if (i <= L && R <= j) return st[C];
    data ret;
    data d1 = Query(i, j, lc, L, M);
    data d2 = Query(i, j, rc, M + 1, R);
    combine(ret, d1, d2);
    return ret;
  }
  void Update(int i, int j, T val, int C, int L, int R) {
    push(C, L, R);
    if (j < L || i > R || L > R) return;
    if (i <= L && R <= j) {
      isLazy[C] = 1;
      lazy[C] = val;
      push(C, L, R);
      return;
    }
    Update(i, j, val, lc, L, M);
    Update(i, j, val, rc, M + 1, R);
    combine(st[C], st[lc], st[rc]);
  }
  void Update(int i, int j, T val) {
    Update(i, j, val, 1, 1, N);
  }
  T Query(int i, int j) {
    return Query(i, j, 1, 1, N).pref_sum;
  }
};
 
void solve() {
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	SegmentTree<ll>st(n);
	st.build(1,1,n);
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int id, val;
			cin>>id>>val;
			st.Update(id,id,val);
		}else{
			int l,r;
			cin>>l>>r;
			cout<<max(0ll,st.Query(l,r))<<'\n';
		}
	}
}
 
 
void preprocess() {
 
 
}
int main() {
    // freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    preprocess();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        //  cout<<"Case "<<i<<':'<<' ';
        solve();
    }
}
