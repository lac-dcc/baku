/***From Dust I Have Come, Dust I Will Be***/
//  Once you put your RATINGS to a side, you'll be more AGGRESIVE in SOLVING
// Check for AND property ........
 
 
#include <bits/stdc++.h>
#include <fstream>
#include<chrono>
using namespace std;
using namespace chrono;
 
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define inf INT_MAX
#define ll long long
#define db double
#define ull unsigned long long
#define lld long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define ms(x,y) memset(x,y,sizeof x)
#define all(x)  (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define deb(x) cout<<x<<endl;
#define setBits(x) __builtin_popcountll(x)
#define parity(x) __builtin_parity(x)
#define pp pair<int,int>
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int> >
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#ifndef ONLINE_JUDGE
#define dbg(a) cerr << #a << ": "; _print(a); cerr << endl;
#else
#define dbg(a)
#endif
int setBit (int n, int x) { return n | (1 << x); }
int clearBit (int n, int x) { return n & ~(1 << x); }
int toggleBit (int n, int x) { return n ^ (1 << x); }
bool checkBit (int n, int x) { return (bool)(n & (1 << x)); }
int dx8[]={1,1,0,-1,-1,-1, 0, 1};
int dy8[]={0,1,1, 1, 0,-1,-1,-1};
int dx4[]={1, 0, -1, 0};
int dy4[]={0, 1, 0, -1};
void yes() {cout<<"YES"<<endl;}
void no() {cout<<"NO"<<endl;}
template<typename  T> void amax(T& t1, T t2) { t1=max(t1,t2);}
template<typename  T> void amin(T& t1, T t2) {t1=min(t1,t2);}
 
/////////////////////////////////////////////--JAI SHREE RAM--//////////////////////////////////
 
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fi); cerr << ","; _print(p.se); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
 
ll binpow(ll a, ll b,int m)
{
    ll ans=1;
    a %= m;
    while(b)
    {
        if(b&1)
            ans=(ans*a);
        b/=2;
        a=(a*a);
        ans%=m;
        a%=m;
    }
    return ans;
}
 
 
const int N=2e5+5;
vector<int> g[N];
int dp[N][3];
int n,x,y;
 
void dfs1(int src,int p)
{
    for(auto e:g[src])
    {
        if(e==p) continue;
        dfs1(e,src);
        amax(dp[src][0],1+dp[e][0]);
    }
    return;
}
 
 
void dfs2(int src,int p)
{
    multiset<int> s;
    s.insert(dp[src][1]);
    for(auto e:g[src])
    {
        if(e==p) continue;
        s.insert(1+dp[e][0]);
    }
 
    for(auto e:g[src])
    {
        if(e==p) continue;
 
        auto it=s.find(1+dp[e][0]);
        int cur=*it;
        s.erase(it);
 
        int mx=*(--s.end());
        s.insert(cur);
        dp[e][1]=1+mx;
 
        dfs2(e,src);
    }
    return;
}
 
 
//lo + (hi - lo) / 2;
void JAI_MAHAKAL()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
 
    dfs1(1,1);
    dfs2(1,1);
    dp[1][1]=dp[1][0];
    for(int i=1;i<=n;i++)
    {
        int ans=max(dp[i][0],dp[i][1]);
        cout<<ans<<" ";
    }
    return;
}
 
int32_t main(){
 
    #ifndef ONLINE_JUDGE
        FILE* inp = freopen("input.txt", "r", stdin);
        FILE* err = freopen("error.txt", "w", stderr);
        FILE* out = freopen("output.txt", "w", stdout);
    #endif
 
    FAST;
    // int t;cin>>t;
    // while(t--)
         JAI_MAHAKAL();
     cerr<<"Time elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
 
// DO NOT JUMP BETWEEN PROBLEMS, SOLVE ONE AFTER THE OTHER
