//0123
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <limits.h>
#include <map>
#include <unordered_map>
#include <utility>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define inf 2e18
#define sor(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define f(i,a,n) for(int i=a;i<n;i++)
#define fe(i,a,n) for(int i=a;i<=n;i++)
#define forr(i,a,b) for(int i=a;i>=b;i--)
#define mxx(a) *max_element(all(a))
#define mnn(a) *min_element(all(a))
#define PYES cout<<"YES"<<endl;
#define PNO cout<<"NO"<<endl;
#define Pyes cout<<"Yes"<<endl;
#define Pno cout<<"No"<<endl;
#define endl "\n"
 
const int mm=1000000000+7;
const int mm1=998244353;
int fact[1000001];
bool prime[1000001];
 
void pre() {
    fact[0]=1;
    for(int i=1;i<=1e6;i++) {
        fact[i]=fact[i-1]*i; fact[i]%=mm;
    }
    memset(prime, true, sizeof(prime)); prime[0]=0; prime[1]=0;
    for (int p=2; p*p<=1000000; p++)
    { if(prime[p] == true)
        { for(int i=p*p;i<=1000000;i+=p) prime[i] = false;}
    }
}
 
void fast(){ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }
int gcd(int a, int b){ if (b == 0) {return a;} return gcd(b, a % b); }
bool isprime(int n){if(n==1) return false; for(int i=2;i<=sqrt(n);i++){if(n%i==0){return false;}} return true;}
int be(int a,int n) { int res=1; while(n>0) { if(n%2==1) {res=(res*(a));} n/=2; a*=a;  } return res;}
int bem(int a,int n,int mod) { int res=1; while(n>0) { if(n%2==1) {res=(res*(a%mod))%mod;} n/=2; a*=a; a%=mod; } return res;}
int ncr(int n,int r) {if(r>n) {return 0;}int t1=fact[n],t2=fact[r]*fact[n-r]; t2%=mm; int t3=be(t2,mm-2); return (t1*t3)%mm;}
bool sbs(pii a,pii b) { return (b.se>a.se); }
 
// Interactive Problem ---- fast hata
// int query(int a,int b) {
//     cout<<"? "<<a<<" "<<b<<endl;
//    // cout.flush();
//     // cout<<a<<endl;
//     int x; cin>>x; return x;
//    // cout.flush();
// }
 
const long long mod=1e9+7;
 
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
 
void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,vector<int>&pathv,bool &cycle,vector<int>&parent,int &start,int &end) {
    vis[node]=1; pathv[node]=1;
    for(auto x:adj[node]) {
        if(vis[x]==1 && x!=parent[node] && pathv[x]==1 && cycle==0) { start=x; end=node; cycle=1; return;}
        if(vis[x]==0 && cycle==0) {parent[x]=node; dfs(x,vis,adj,pathv,cycle,parent,start,end);}
    }
    pathv[node]=0;
}
 
void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++) {
        int x,y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool cycle=0;
    int start=-1,end=-1;
    vector<int>vis(n+1,0),pathv(n+1,0),parent(n+1,-1);
    for(int i=1;i<=n;i++) {
        if(vis[i]==0) dfs(i,vis,adj,pathv,cycle,parent,start,end);
        if(cycle==1) {
            vector<int>ans;
            while(parent[end]!=start) {ans.push_back(end); end=parent[end];}
            ans.push_back(end);
            ans.push_back(start);
            reverse(ans.begin(),ans.end());
            ans.push_back(start);
            cout<<ans.size()<<endl;
            for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
            cout<<endl;
            return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl; return;
}
 
int32_t main () {
    fast();//pre();
    int q; q=1;
    // cin>>q;
    for (int i=1;i<=q;i++)
    {
       // cout << "Case #"<<i<< ": ";
        solve();
    }
    return 0;
}
