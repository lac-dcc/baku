#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
const int MAX = 2e6 + 15;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
 
#define pb push_back
#define sz(x) (int) x.size()
#define fr first
#define sc second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define dbg(x) cerr << #x << ": " << "[ " << x << " ]\n"
 
struct Node{
    ll pref, suff, sum, ans;
 
    Node(ll a = 0, ll b = 0, ll c = 0, ll d = 0){
        pref = a, suff = b, sum = c, ans = d;
    }
 
    Node operator + (Node other){
        Node ret = Node();
        ret.sum = sum + other.sum;
        ret.pref = max(pref, sum + other.pref);
        ret.suff = max(other.suff, other.sum + suff);
        ret.ans = max(max(ans, other.ans), suff + other.pref);
        return ret;
    }
};
 
ll n, q, v[MAX];
Node seg[4 * MAX];
 
void build(ll p, ll l, ll r){
    if(l == r){
        seg[p] = Node(v[l], v[l], v[l], v[l]);
        return;
    }
 
    ll m = (l + r) >> 1, e = 2 * p, d = e + 1;
    build(e, l, m); build(d, m + 1, r);
    seg[p] = seg[e] + seg[d];
}
 
void update(ll i, ll x, ll p, ll l, ll r){
    if(i > r || i < l) return;
    if(l == r){
        seg[p] = Node(x, x, x, x);
        return;
    }
 
    ll m = (l + r) >> 1, e = 2 * p, d = e + 1;
    update(i, x, e, l, m); update(i, x, d, m + 1, r);
 
    seg[p] = seg[e] + seg[d];
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
 
    cin >> n >> q;
 
    for(int i = 1; i <= n; i++)
        cin >> v[i];
 
    build(1, 1, n);
 
    while(q--){
        ll k, x; cin >> k >> x;
        update(k, x, 1, 1, n);
 
        cout << max(0LL, seg[1].ans) << '\n';
    }
 
    return 0;
}
