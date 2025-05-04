#include<bits/stdc++.h>
using namespace std;
 
void DBG() { cerr << "]\n"; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << h; if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}
#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif // LOCAL
 
#define FOR(i,a,b) for(int i = (a) ; i<(b) ; i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for(int i = (b)-1 ; i>=(a) ; i--)
#define R0F(i,a) ROF(i,0,a)
#define each(e,a) for(auto &e : (a))
#define sz(v) (int)(v).size()
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back
#define tcT template<class T
#define nl "\n"
 
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
using str = string;
tcT> using V = vector<T>;
tcT> using pqg = priority_queue<T,vector<T>,greater<T>>;
 
void setIO(string NAME = "") {
    cin.tie(0)->sync_with_stdio(0);
    if(sz(NAME)) {
        freopen((NAME + ".in").c_str(),"r",stdin);
        freopen((NAME + ".out").c_str(),"w",stdout);
    }
}
 
const int MX = 2e5+5;
const ll INF = 1e18;
 
ll lzy[2<<18], st[2<<18];
int A[MX];
int N, Q;
 
void push(int ind, int L, int R, int mid) {
    F0R(i,2) st[ind*2+i] += lzy[ind], lzy[ind*2+i] += lzy[ind];
    lzy[ind] = 0;
}
 
void updInc(int l, int r, ll val, int ind = 1, int L = 0, int R = N) {
    if(L >= r || R <= l) return;
    if(l <= L && R <= r) {
        st[ind] += val;
        lzy[ind] += val;
        return;
    }
    int mid = (L + R) >> 1;
    push(ind, L, R, mid);
    updInc(l, r, val, ind<<1, L, mid);
    updInc(l, r, val, ind<<1|1, mid, R);
    st[ind] = max(st[ind<<1], st[ind<<1|1]);
}
 
ll query(int l, int r, int ind = 1, int L = 0, int R = N) {
    if(L >= r || R <= l) return -INF;
    if(l <= L && R <= r) return st[ind];
    int mid = (L + R) >> 1;
    push(ind, L, R, mid);
    return max(query(l, r, ind<<1, L, mid), query(l, r, ind<<1|1, mid, R));
}
 
void solve() {
    cin>>N>>Q;
    F0R(i,N) {
        cin>>A[i];
        updInc(i, N, A[i]);
    }
    F0R(_,Q) {
        int t;
        cin>>t;
        if(t == 1) {
            int k, u;
            cin>>k>>u, --k;
            updInc(k, N, -A[k]);
            A[k] = u;
            updInc(k, N, A[k]);
        }
        else {
            int l, r;
            cin>>l>>r;
            cout << max(0LL,query(l-1, r) - (l==1 ? 0 : query(l-2, l-1))) << nl;
        }
    }
}
 
int main() {
    setIO();
 
    int t=1;
    //cin>>t;
    while(t-->0) {
        solve();
    }
 
    return 0;
}
