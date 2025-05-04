/*
Anshuman Mishra
g++ -std=c++17 a.cpp
 
No accomplishment has been achieved in one day.
Give it your effort and  it will be given to you.
*/
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;typedef long double ld;typedef unsigned long long ull;typedef pair<int,int> pii;typedef pair<ll,ll> pll;typedef map<int,int> mii;typedef map<ll,ll> mll;typedef vector<int> vii;typedef vector<ll> vll;typedef set<ll> setl;typedef unordered_map<ll,ll> umll;
 
#define int long long 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#define v vector
#define um unordered_map
#define sq(x) ((x)*(x))
#define pq priority_queue
#define F first
#define S second
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
 
#define all0(x) (x).begin(),(x).end()
#define all1(x) (x).begin()+1,(x).end()
#define read(vec) for(auto i=0;i<(int)vec.size();++i) cin>>vec[i]
 
 
inline ll nxtl(){ll x;cin>>x;return x;}
inline int nxt(){int x;cin>>x;return x;}
const ll INF = 1e18, MOD = 1e9 + 7;
 
inline int add(int a, int b){ int c = (a%MOD) + (b%MOD); if(c >= MOD) c -= MOD; return c; }
inline int mul(int a, int b){ return ((a%MOD) * 1ll * (b%MOD)) % MOD; }
inline int sub(int a, int b){ int c = (a%MOD) - (b%MOD); if(c < 0) c += MOD; return c; }
 
ll power(ll x,ll y){ll p=MOD;ll res = 1;x=x%p;while(y>0){if (y&1) res=(res*x)%p;y=y>>1;x=(x*x)%p;}  return res;}
ll Inv(ll n){return power(n,MOD-2);}
 
 
 
template<typename T> inline void print(v<T>&a){
    for (auto e:a) cout<<e<<' ';cout<<'\n';
}
 
 
 
 
const int N = 2e5+5;
v<pii> G[N];
int n,m;
 
 
void path(int src){
    pq<pii,v<pii>,greater<pii> > q;
    vll dist(N,INT_MAX),prev(N,-1);
    
    prev[src]=src;
    dist[src] = 0;
    
    q.push({0,src});
    int a,b,wt; 
 
    while(!q.empty()){
        a = q.top().S;
        q.pop();
 
        for (auto e:G[a]){
            //cout<<q.top().F<<" "<<q.top().S<<'\n';
            b = e.F , wt = e.S;
            if (dist[b] > dist[a]+wt){
                dist[b]=dist[a]+wt;
                prev[b]=a;
                q.push({dist[b],b});
            }
        }
    }
 
    //print(prev);
    stack<ll>s;
    if (prev[n]==-1) cout<<"IMPOSSIBLE\n";
    else {
        cout<<dist[n]+1<<"\n";
        int i=n;
        s.push(n);
        while(prev[i]!=i){
            //cout<<prev[i]<<' ';
            s.push(prev[i]);
            i = prev[i];
        }
 
        while(!s.empty()){
            cout<<s.top()<<' ';
            s.pop();
        }
        cout<<'\n';
    }
}
 
 
void Work(){
    cin>>n>>m;
    int a,b,w;
    rep(i,0,m){
        cin>>a>>b;
        G[a].pb({b,1});
        G[b].pb({a,1});
    }
    path(1);
}
 
 
 
signed main()
{
    clock_t begin = clock();
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
    #endif
 
 
    int t=1;
    //cin>>t;
    while(t--) Work();
 
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nTime : "<<double(end-begin)/CLOCKS_PER_SEC*1000<<"ms\n";
    #endif
    return 0;
}
