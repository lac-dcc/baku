#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<pll> vpl;
typedef vector<int> vi;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
const int N = 200005;
struct node{
	node() = default;
	ll sum = 0 , best = 0 ,  bestpref = 0 , bestsuf = 0;
	node(int x){
		sum = x;
		best = max(x , 0);
		bestsuf = max(x,0);
		bestpref = max(x,0);	
	}
	node operator+ (const node & rhs) const{
		node u;
		u.sum = rhs.sum + sum;
		u.best = max({rhs.best, best, bestsuf + rhs.bestpref});
		u.bestpref = max({sum + rhs.bestpref , bestpref});
		u.bestsuf = max(rhs.sum + bestsuf , rhs.bestsuf);
		return u;
	}
};
template <class T>
struct ST{
	vector<T> st; int n; 
	ST(int n) : st(2*n) , n(n){}
	void upd(int pos, T val){ // pos 0index
		for(st[pos += n] = val ; pos /= 2;)
			st[pos] = st[2*pos] + st[2*pos + 1];
	}
	T query(int x , int y){ // [x,y] , x, y -0index
		T ra , rb;
		bool okl = false, okr = false;
		for(x += n, y += n+1 ; x < y ; x/=2 , y/=2){
			if(x&1) ra = (okl ? ra + st[x] : st[x]) , x++ , okl = true;
			if(y&1) --y , rb = (okr ? st[y] + rb : st[y]) , okr = true;
		}
		return (okl ? (okr ? ra + rb : ra): rb);
	}
};
int n , m , p[N];
int32_t main(){
	scanf("%d%d" , &n , &m);
	ST<node> seg(n+1);
	for(int i = 1; i <= n; i ++){
		scanf("%d" , &p[i]);
		seg.upd(i,node(p[i]));
	}
	while(m--){
		int k , x;
		scanf("%d%d" , &k , &x);
		seg.upd(k,node(x));
		printf("%lld\n" , seg.query(1,n).best);
	}
}
