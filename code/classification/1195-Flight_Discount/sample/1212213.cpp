#pragma GCC optimze("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007
#define md 998244353
#define trace(...)
#define ll long long int
#define ld long double
#define fi first
#define se second
#define fr(i,a,b) for(ll i=a;i<=b;i++)
#define frr(i,b,a) for(ll i=b;i>=a;i--)
#define mem(a) memset(a, 0, sizeof(a))
#define vpi std::vector<pair<int,int>>
#define pii pair<int,int>
#define pll pair<ll,ll> 
#define pb push_back
#define sall(v) sort(v.begin(),v.end())
#define all(v) (v.begin(),v.end())
#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))
#define minf -10000000
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
ll power(ll x, ll y,ll p) { 
    ll res = 1;      // Initialize result 
    x = x % p;  // Update x if it is more than or equal to p 
    while (y > 0) {  
        if (y & 1) // If y is odd, multiply x with result
            res = (res*x) % p;  
        y = y>>1; // y = y/2 // y must be even now
        x = (x*x) % p;   
    } 
    return res; 
}
ll power(ll x, ll y) { 
    ll res = 1;      // Initialize result 
    while (y > 0) {    
        if (y & 1)// If y is odd, multiply x with result 
            res = (res*x) ;  
        y = y>>1; // y = y/2 // y must be even now 
        x = (x*x);   
    } 
    return res; 
}
 
ll max3(ll a,ll b,ll c){
    return max(a,max(b,c));
}
ll min3(ll a,ll b,ll c){
    return min(a,min(b,c));
}
bool isPrime(ll n) { // Corner cases 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (ll i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
}
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
const int nax=1e5+10;
vector<pll> A[nax];
vector<pll> B[nax];
vector<ll> dist1(nax);
vector<ll> dist2(nax); 
void solve(){
    int n,m;cin>>n>>m;
    vector<pair<pll,ll>> edges(m);
    fr(i,1,n){
        A[i].clear();B[i].clear();
        dist2[i]=dist1[i]=1e18;
    }
    ll a,b,c;
    fr(i,0,m-1){
        cin>>a>>b>>c;
        edges[i].first.first=a;
        edges[i].first.second=b;
        edges[i].second=c;
        A[a].pb({b,c});
        B[b].pb({a,c});
    }
    // fr(i,0,m-1)
        // cout<<edges[i].first.first<<" "<<edges[i].first.second<<" "<<edges[i].second<<endl;
     
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,1});
    dist1[1]=0ll;
    pll tp;
    while(!pq.empty()){
        tp=pq.top();pq.pop();
        if(dist1[tp.second]!=tp.first)continue;
        for(auto x:A[tp.second]){
            if(dist1[x.first]>(dist1[tp.second]+x.second)){
                dist1[x.first]=tp.first+x.second;
                pq.push({dist1[x.first],x.first});
            }
        }
    }
    // fr(i,1,n)cout<<dist1[i]<<" ";cout<<endl;
    //now we have dist1 dono
    //now do dist2
    pq.push({0,n});
    dist2[n]=0ll;
    while(!pq.empty()){
        tp=pq.top();pq.pop();
        if(dist2[tp.second]!=tp.first)continue;
        for(auto x:B[tp.second]){
            if(dist2[x.first]>(dist2[tp.second]+x.second)){
                dist2[x.first]=tp.first+x.second;
                pq.push({dist2[x.first],x.first});
            }
        }
    }
    // fr(i,1,n)cout<<dist2[i]<<" ";cout<<endl;
    ll ans=1e18;
    ll x,y,val;
    fr(i,0,m-1){
        x=edges[i].first.first;
        y=edges[i].first.second;
        val=edges[i].second;
        // cout<<x<<" "<<y<<" "<<val<<endl;
        if(dist1[x]!=1e18 && dist2[y]!=1e18)
            ans=min(dist1[x]+dist2[y]+val/2,ans);
    }
    cout<<ans<<endl;
    return;
}
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    cout<<fixed<<setprecision(8);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("test_input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
    #endif
    return 0;
}
