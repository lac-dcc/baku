// Bismillahir Rahmanir Rahim
 
 
#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double ld ;
typedef unsigned long long ull ;
typedef vector<int> vi ;
typedef vector<ll> vl ;
typedef vector<vi> vvi ;
typedef vector<vl> vvl ;
typedef pair<int, int> pii ;
typedef pair<ll, ll> pll ;
typedef pair<float, float> pff ;
typedef pair<double, double> pdd ;
typedef pair<ll, ll> pll ;
#define pb push_back
#define el << '\n' ;
#define all(a) (a).begin(),(a).end()
#define allr(a) (a).begin(),(a).end()
#define F first
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds ;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0) ;
ll bin_expo(ll base, ll pow, ll m) {
    if (pow == 0) return 1;ll ret = bin_expo(base, pow / 2, m) % m ;
    if (pow & 1) return (ret % m * ret % m * base % m) % m;else return (ret % m * ret % m) % m ; }
ll mod_add(ll a, ll b, ll m) { return ((a % m) + (b % m)) % m ; }
ll mod_sub(ll a, ll b, ll m) { return (a-b+m)%m ; }
ll mod_mul(ll a, ll b, ll m) { return ((a % m) * (b % m)) % m ; }
ll mod_div(ll a, ll b, ll m) { return ((a % m) * bin_expo(b, m - 2, m)) % m ; }
ll aModB(ll a , ll b) { if(a<0 ) { return ((a+(abs(a)/b)*b)+b)%b ; } else { return a%b; } }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b) ; }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 4e18 + 123 ;
const ll inf = 1e12 + 7 ;
const ll mod = 1e9 + 7 ;
const ll mod2 = 998244353 ;
const ll mx = 2e5 + 10 ;
ll LOG = 21 ; 
 
// ---------------------------------------------------------------------------------------------------------------------
 
 
ll a[mx] , n , m ;
struct Node {
    ll prefix , sum ;
} ; 
Node segtree[mx * 4] ;
ll Operation( ll x , ll y ) {        
    return x+y ; 
}
void build( int node , int start , int end ) {
    if(start==end) {
        segtree[node].sum = a[end] ;
        segtree[node].prefix = a[end] ; 
        return ;    
    }
    int mid = ( start+end ) / 2 ;
    int left = node*2 ;
    int right = node*2 + 1 ;
    build( left,start,mid ) ;
    build( right,mid+1,end ) ;
    segtree[node].prefix = max(segtree[left].prefix,segtree[left].sum+segtree[right].prefix) ;
    segtree[node].sum = Operation(segtree[left].sum , segtree[right].sum ) ;
}
void update(int node , int start , int end , int l , int r , ll x ) {
    if(l>end || r<start) return ;
    if(l<=start and end<=r){
        segtree[node].sum = x ;
        segtree[node].prefix = x ; 
        return ;
    }
    int mid = (start+end) / 2 ;
    int left = node*2 ;
    int right = node*2 + 1 ;
    update(left,start,mid,l,r,x) ;
    update(right,mid+1,end,l,r,x) ;
    segtree[node].prefix = max(segtree[left].prefix,segtree[left].sum+segtree[right].prefix) ;
    segtree[node].sum = Operation(segtree[left].sum , segtree[right].sum ) ;
}
Node query(int node, int start, int end , int l,  int r ) {
    if (l > end || r < start) { 
        Node temp ; 
        temp.prefix = 0;
        temp.sum = 0 ; 
        return temp ; 
    }
    if (start >= l and end <= r) { 
        return segtree[node] ;
    } 
    int mid = (start+end) / 2 ;
    int left = node*2 ;
    int right = node*2 + 1 ;
    Node p1 = query(left,start,mid,l,r) ; 
    Node p2 = query(right,mid+1,end,l,r) ; 
    Node ans ; 
    ans.prefix = max(p1.prefix,p1.sum+p2.prefix) ; 
    ans.sum = p1.sum + p2.sum ; 
    return ans ; 
}
void solution(int cs) {
    ll n , m ; 
    cin >> n >> m ; 
    for(ll i=1;i<=n;i++) {
        cin >> a[i] ; 
    }
    build(1,1,n) ; 
    for(ll i=1;i<=m;i++) {
        int c ; 
        cin >> c ; 
        if(c==1) {                   // update
            int k , u ; 
            cin >> k >> u ; 
            update(1,1,n,k,k,u) ; 
        }
        else {                       // query 
            int a , b ; 
            cin >> a >> b ; 
            Node ans = query(1,1,n,a,b)  ;
            cout << max(ans.prefix,0LL)  el ;  
        }
    }
}             
int main() { 
    fastIO ;
    #ifndef ONLINE_JUDGE
    file() ;
    #endif
    int t = 0 ; 
    int cs = 1 ;
    //cin >> cs ;  
    for(ll i=1;i<=cs;i++) solution(i) ; 
    return 0 ;
}
