#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define all(t) t.begin(), t.end()
#define inrange(i, a, b) (((i)>= min((a), (b))) && ((i) <= max((a), (b))))
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
#define fi first
#define se second
#define show(x) cout << #x << " is " << x << "\n";
const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void print(ll a[], ll n){for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<"\n";}
ll power(ll x, ll y, ll M = inf){
	if(y<=0) return 1;
    ll ans = 1;
    x %= M;
    while(y){
        if(y&1)
            ans = (x * ans) % M;
 
        x = (x * x) % M;
        y >>= 1;
    }
    return ans;
}
ll modInverse(ll n) {return power(n, mod-2, mod);}
inline ll mul(ll a, ll b){ return (a * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c >= mod) c -= mod; return c; }
inline ll divi(ll a, ll b){ return mul(a, modInverse(b)); }
 
//------------------------------------------------------------------------------------------
 
//const ll N = 1e5 + 1;
//vector<ll> adj[N];
//bool visited[N];
 
class node{
	public:
		ll mxsum=0, mnsum=0, sum=0, ans=0;
 
		node(ll x){
			sum = x;
			mxsum = max(x, 0ll);
			mnsum = min(x, 0ll);
			ans = max(x, 0ll);
		}
		node(){
			node(0);
		}
};
 
template<class T, int n> struct SegTree { // n should be power of 2
    T seg[2*n], MIN = node(0);
 
    SegTree() {
		for(ll i=0;i<2*n;i++){
			seg[i] = MIN;
		}
	}
 
	T combine(T a, T b) {
		node op = node(0);
 
		op.mxsum = max(a.mxsum, a.sum+b.mxsum);
		op.mnsum = min(a.mnsum, a.sum+b.mnsum);
		op.sum = a.sum + b.sum;
		op.ans = max({a.ans, b.ans, a.sum-a.mnsum+b.mxsum});
 
		return op;
	}
 
    void build() {
		for (int i = n-1; i >= 0; i--)
			seg[i] = combine(seg[2*i],seg[2*i+1]);
	}
 
    void update(int p, T value) {  // set value at position p
        for (seg[p += n] = node(value); p > 1; p >>= 1)
            seg[p>>1] = combine(seg[(p|1)^1], seg[p|1]);
        // make sure non-commutative operations work
    }
 
    T query(int l, int r) {  // sum on interval [l, r]
        T res1 = MIN, res2 = MIN; r++;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res1 = combine(res1,seg[l++]);
            if (r&1) res2 = combine(seg[--r],res2);
        }
        return combine(res1,res2);
    }
};
// 1-indexing
 
SegTree<node, (1<<18) > S;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout<<fixed<<setprecision(10);
 
 
 
	int n, m;
	cin>>n>>m;
	int a[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		S.update(i, a[i]);
	}
	while(m--){
		int k, x;
		cin>>k>>x;
		S.update(k-1, x);
		cout<<S.query(0, n-1).ans<<"\n";
	}
    return 0;
}
 
