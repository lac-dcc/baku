 
#include<bits/stdc++.h>
#define ll long long int
#define str(x) (x).begin()
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define MOD 1000000007
#define INF (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
 
struct edge{
    ll to;
    ll weight;
    bool operator>(const edge& other)const{
        return weight>other.weight;
    }
};
vector<bool> vis;
 
int main() {
   fast_io;
   ll n,m;
   cin >>n>>m;
    vector<vector<edge>> adj=vector<vector<edge>>(n+1);
    vis=vector<bool>(n+1,0);
    while (m--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
        
    }
    vector<ll> d=vector<ll>(n+1,INF);
    d[1]=0;
    priority_queue<edge,vector<edge>,greater<edge>> c;
    c.push({1,0});
    while (!c.empty())
    {
        edge curr=c.top();
        c.pop();
        if(!vis[curr.to])
        {   vis[curr.to]=1;
            for(auto ege:adj[curr.to])
            {
                int t=ege.to;
                ll w=ege.weight;
                if(d[curr.to]+w<d[t]){
                    d[t]=d[curr.to]+w;
                    c.push({t,d[t]});
                }
 
 
 
            }
            
            
            
            }
        /* code */
    }
    for(int i=1;i<n+1;i++)
        cout<<d[i]<<" ";
    
   return 0;
}
