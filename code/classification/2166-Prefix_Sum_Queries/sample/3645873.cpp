/*
今ここから始まる　新しい旅に
Hello! Hello!
I Say Hello! Hello!
なんか反省ばっかしちゃってた　昨日の自分に
Good Bye! Good Bye!
One More Good Bye! Good Bye!
走り出しちゃったこの想いに　理由なんていらないよ
眩しい太陽を浴びて
目的地まだ見えないけれど
靴ひもを結んで　Walk This Way!
*/
#include <bits/stdc++.h>
using namespace std;
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define int ll
#define vi vector<int>
#define pii pair<int,int>
#define mii map<int,int>
#define si stack<int>
#define qi queue<int>
#define upb upper_bound
#define lwb lower_bound
#define pf push_front
#define pb push_back
#define pp push
#define pof pop_front
#define pob pop_back
#define ff first
#define ss second
#define inf 1e18
#define mod 998244353
#define modd 1000000007
#define gcd __gcd
#define N 200005
#define skip(x) if(x)continue;
 
int node[N << 2], arr[N], pre[N], tag[N << 2];
 
void push(int i, int l, int r){
    int t = tag[i], mid = (l + r) >> 1;
    tag[i<<1] += t; tag[(i<<1) + 1] += t;
    node[i<<1] += t; node[(i<<1) + 1] += t;
    tag[i] = 0;
}
 
void pull(int i){
    node[i] = max(node[i<<1], node[(i<<1) + 1]);
}
 
void build(int l, int r, int i){
    if(l == r) {node[i] = pre[l]; return;}
    int mid = (l + r) >> 1;
    build(l, mid, (i<<1));
    build(mid + 1, r, (i<<1) + 1);
    pull(i);
}
 
void modify(int l, int r, int i, int ql, int qr, int v){
    if(ql > r || qr < l) return;
    if(l == r){node[i] += v; return;}
    push(i, l, r);
    if(ql <= l && r <= qr){node[i] += v; tag[i] += v; return;
    }
    int mid = (l + r) >> 1;
    modify(l, mid, (i<<1), ql, qr, v);
    modify(mid + 1, r, (i<<1) + 1, ql, qr, v);
    pull(i);
}
 
int maxquery(int l, int r, int i, int ql, int qr){
    if(qr == 0) return 0;
    if(ql > r || qr < l) return -inf;
    if(l == r){return node[i];}
    push(i, l, r);
    if(ql <= l && r <= qr){return node[i];}
    int mid = (l + r) >> 1;
    return max(maxquery(l, mid, (i<<1), ql, qr), maxquery(mid + 1, r, (i<<1) + 1, ql, qr));
}
 
void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i]; pre[i] = pre[i - 1] + arr[i];
    }
    for(int &x:node) x = -inf;
    build(1, n, 1);
    while(m--){
        int t; cin >> t;
        if(t == 1){
            int k, u; cin >> k >> u;
            int d = u - arr[k];
            modify(1, n, 1, k, n, d);
            arr[k] = u;
        }else{
            int a, b; cin >> a >> b;
            cout << max(0ll, maxquery(1, n, 1, a, b) - maxquery(1, n, 1, a - 1, a - 1)) << '\n';
        }
    }
}
 
signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}


