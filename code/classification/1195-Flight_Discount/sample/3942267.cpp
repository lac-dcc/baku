#include <bits/stdc++.h>
 
using namespace std;
 
#define read(type) readInt<type>()
#define ll long long
#define nl "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pii>
#define vll vector<pll>
#define vvi vector<vi>
#define vvl vector<vl>
#define sl set <ll>
#define msl multiset <ll>
#define mll map <ll,ll>
#define all(x) (x).begin(),(x).end()
#define FOR(i,n) for(i=0;i<(n);i++)
#define FORFOR(i,j,n) FOR(i,n)  FOR(j,n)
#define FORtri(i,j,n) FOR(i,n)  for(j=0;j<(i+1);j++)
#define FOR1(i,n) for(i=1;i<=(n);i++)
#define FORrev(i,n) for(i=(n-1);i>=0;i--)
#define rep(i,a,b) for(i=(a);i<(b);i++)
#define rrep(i,a,b) for(i=(a);i>=(b);i--)
#define geta(a,n) for(ll i=0;i<n;i++)cin>>a[i];
#define i1(x) cin>>x
#define i2(x1,x2) cin>>x1>>x2
#define i3(x1,x2,x3) cin>>x1>>x2>>x3
#define i4(x1,x2,x3,x4) cin>>x1>>x2>>x3>>x4
#define o1(x) cout<<x<<nl
#define o2(x1,x2) cout<<x1<<" "<<x2<<nl
#define o3(x1,x2,x3) cout<<x1<<" "<<x2<<" "<<x3<<nl
#define o4(x1,x2,x3,x4) cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<nl
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
const ll mod = 1e9 + 7;
const ll infinity = 1e18;
const int maxn = 1e5+5;
 
vll g[maxn],f[maxn];
ll distg[maxn],distf[maxn];
// int visit[maxn];
 
int n,m;
 
 
// vi g[maxn];
//Grid Graph
// vi vis[maxn];
//Parent Vectors for Grid Graph
// vi par[maxn];
 
 
 
//Adjacency List
int vis[maxn];
// int par[maxn];
// int n,m;
 
 
void dijkstrag(int start){
    int i;
    FOR1(i,n){
        distg[i] = infinity;
        vis[i] = 0;
    }
    distg[start]=0;
    priority_queue<pair<ll,ll>> pq;
    pair<ll,ll> tem;
    pq.push({0,start});
    while(!pq.empty()){
        tem = pq.top();
        pq.pop();
        if(vis[tem.second]) continue;
        vis[tem.second] = 1;
        for(auto &x:g[tem.second]){
            if((distg[x.first]>(distg[tem.second]+x.second))){
                distg[x.first]=(distg[tem.second]+x.second);
                pq.push({-distg[x.first],x.first});
            }
        }
    }
 
}
 
void dijkstraf(int start){
    int i;
    FOR1(i,n){
        distf[i] = infinity;
        vis[i] = 0;
    }
    distf[start]=0;
    priority_queue<pair<ll,ll>> pq;
    pair<ll,ll> tem;
    pq.push({0,start});
    while(!pq.empty()){
        tem = pq.top();
        pq.pop();
        if(vis[tem.second]) continue;
        vis[tem.second] = 1;
        for(auto &x:f[tem.second]){
            if((distf[x.first]>(distf[tem.second]+x.second))){
                distf[x.first]=(distf[tem.second]+x.second);
                pq.push({-distf[x.first],x.first});
            }
        }
    }
 
}
 
 
 
 
 
 
// void printit(int i, int j){
//     vi a;
//     int tem;
//     // o2(i,j);
//     while(para[i][j]!=-1){
//         a.pb(para[i][j]);
//         tem = para[i][j];
//         i-=di[tem];
//         j-=dj[tem];
//     }
//     reverse(all(a));
//     int sizi = a.size();
//     cout<<sizi<<nl;
//     FOR(i,sizi){
//         cout<<pa[a[i]];
//     }
//     // cout<<nl;
// }
 
 
void solve(){
    ll i,j,c,a,b,q;
    i2(n,m);
    // memset(visa,-1,sizeof(visa));
    // memset(vism,-1,sizeof(vism));
    // memset(dist,-1,sizeof(dist));
    // FOR(i,n){
    // FOR1(i,n){
    //     // g[i][i] = 0;
    //     distf[i] = infinity;
    //     distg[i] = infinity;
    // }
    // distg[1]=0;
    // distf[n]=0;
    FOR(j,m){
        i3(a,b,c);
        g[a].pb({b,c});
        f[b].pb({a,c});
        // dist[a].pb({b,c});
        // g[a][b] = min(g[a][b],c);
        // g[b][a] = min(g[b][a],c);
        // dist[a][b] = min(dist[a][b],c);
        // dist[b][a] = min(dist[b][a],c);
        // g[b].pb(a);
    }
    dijkstrag(1);
    dijkstraf(n);
    ll sum=infinity,tem;
    FOR1(i,n){
        for(auto &x:g[i]){
            tem= (distg[i] + distf[x.first] + (x.second)/2);
            sum = min(sum,tem);
        }
    }
    // cout<<nl<<nl;
    // FOR1(i,n){
    //     cout<<distg[i]<<" ";
    // }
    // cout<<nl;
    // cout<<nl<<nl;
    // FOR1(i,n){
    //     cout<<distf[i]<<" ";
    // }
    // cout<<nl;
    o1(sum);
 
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        
        solve();
        
    }
    
    
    return 0;
}
