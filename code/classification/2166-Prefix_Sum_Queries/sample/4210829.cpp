#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define sz(a) a.size()
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define fi first
#define se second
const int MAXN = 2e6 + 10;
const ll inf = 1e18 + 10;
const ll MOD = 1e9 + 7;
const int offset = 131;
const int base = 31;
const int mask_s = 1 << 13;
 
ll a[MAXN],pre[MAXN],T[MAXN*4],laz[MAXN*4];
 
void push_down(int id)
{
    laz[id*2] += laz[id];
    laz[id*2+1] += laz[id];
    T[id*2] += laz[id];
    T[id*2+1] += laz[id];
    laz[id] = 0;
}
 
void build(int l,int r,int id)
{
    if(l == r)
    {
        T[id] = pre[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l,mid,id*2);
    build(mid+1,r,id*2+1);
    T[id] = max(T[id*2],T[id*2+1]);
}
 
void update(int l,int r,int id,int pos,ll val)
{
    if(r < pos) return;
    if(laz[id] != 0) push_down(id);
    if(l >= pos)
    {
        laz[id] += val;
        T[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(l,mid,id*2,pos,val);
    update(mid+1,r,id*2+1,pos,val);
    T[id] = max(T[id*2],T[id*2+1]);
}
 
ll get(int l,int r,int id,int x,int y)
{
    if(x == 0) return (ll) 0;
    if(laz[id] != 0) push_down(id);
    if(l > y || r < x) return -inf;
    if(x <= l && r <= y) return T[id];
    int mid = (l + r) / 2;
    ll res = max(get(l,mid,id*2,x,y),get(mid+1,r,id*2+1,x,y));
    T[id] = max(T[id*2],T[id*2+1]);
    return res;
}
 
 
void solve()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        pre[i] += pre[i-1] + a[i];
    }
    build(1,n,1);
    while(q--)
    {
        ll t,x,y;
        cin >> t >> x >> y;
        if(t == 1)
        {
            update(1,n,1,x,y - a[x]);
            a[x] = y;
        }
        else cout << max((ll)0,(ll) get(1,n,1,x,y) - get(1,n,1,x-1,x-1)) << "\n";
    }
}
 
int main()
{
    //freopen("chiadat.inp","r",stdin);
    //freopen("chiadat.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--) solve();
}
