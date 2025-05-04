#include<bits/stdc++.h>
using namespace std;
typedef double dl;
#define ll long long int
#define endl "\n" 
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pi 3.1415926536
#define Setpre(n) cout<<fixed<<setprecision(n)
#define in insert
#define all(v) v.begin(),v.end()
#define vecsort(v) sort(v.begin(),v.end())
#define rvecsort(v) sort(v.begin(),v.end(),greater <>())
#define min_elem(v) *min_element(v.begin(),v.end())
#define max_elem(v) *max_element(v.begin(),v.end())
#define vec_sum(v) accumulate(v.begin(),v.end(),0)
#define vec_elem_count(v,x) count(v.begin(),v.end(),x)
#define rev(v) reverse(v.begin(),v.end())
#define vi std :: vector<int>
#define vll std :: vector<ll>
#define vvi std :: vector<vi>
#define vpi std :: vector<pair<int,int>>
#define mii std :: map<int,int>
#define umii std :: unordered_map<int,int>
#define out(i) cout<<i<<endl
 
struct edge{
    public:
    int u;
    int v;
    int w;
    edge(int a, int b, int c)
    {
        u=a;
        v=b;
        w=c;
    }
};
 
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<edge> edges;
    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        edges.push_back(edge(a,b,c));
    }
 
    vll relaxant(n+1,-1);
    int x=-1;
 
    vector<ll> dist(n+1,0);
    for(ll i=1;i<=(n-1);i++)    
    {
        for(auto it:edges)
        {//u->v, with weight w
            if(((dist[it.u]+it.w) < dist[it.v]) && dist[it.u]!=LLONG_MAX)
                {
                    dist[it.v]=dist[it.u]+it.w;
                    relaxant[it.v]=it.u;
                }
        }
    }
 
    
    for(auto it:edges)
    {
            if(((dist[it.u]+it.w) < dist[it.v]) && dist[it.u]!=LLONG_MAX)
            
                    {
                    relaxant[it.v]=it.u;
                        x=it.v;
                    }
            
    }
 
    if(x!=-1)
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
        {
            x=relaxant[x];            
        }
 
        vll cycle;
        for(int k=x;;k=relaxant[k])
        {
            cycle.pb(k);
            if(k==x && cycle.size()>1)break;
        }
        reverse(cycle.begin(),cycle.end());
        for(auto it: cycle)
        {
            cout<<it<<" ";
        }
    }
    else cout<<"NO"<<endl;
 
 
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
        solve();
 
    
return 0;
}
 
 
 
