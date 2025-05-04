//Dinar Perseüs
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define fo(i,n) for (int i = 0; i < n; i++)
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define ce cout<<'\n'
#define pu push_back
#define po pop_back
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define in insert
#define f  first
#define s  second
#define dbg1(x) cerr<<'#'<<#x<<" = "<<x<<'\n'
#define dbg2(x,y) cerr<<'#'<<#x<<" = "<<x<<"    &    #"<<#y<<" = "<<y<<'\n'
#define dbg3(x,y,z) cerr<<'#'<<#x<<" = "<<x<<"    &    #"<<#y<<" = "<<y<<"    &    #"<<#z<<" = "<<z<<'\n'
#define all(x)    x.begin(),x.end()
//using namespace __gnu_pbds;
using namespace std;
//template<class T> using  oset= tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
const int mod= 1e9+7;
 
//vector<vector<int>> dp(1000+1,vector<int>(100000+1,-1));
//int dp[1000+1][100000+1];
 
// int knapsack(int *c,int *v,int n,int r){
//     if (r==0||n==0)return 0;
//     if (dp[n][r]!=-1)return dp[n][r];
//     if (r>=c[n-1])
//     {
//         return dp[n][r]=max(v[n-1]+knapsack(c,v,n-1,r-c[n-1]),knapsack(c,v,n-1,r));
//     }else
//     {
//         return dp[n][r]=knapsack(c,v,n-1,r);
//     }
// }
 
 
 
 
class graph
{
    int v;
    list<pair<int,int>> *adj;
    
public:
    graph(int v){
        this->v=v;
        adj=new list<pair<int,int>>[v];
    }
 
    void addedge(int u, int v,int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
 
    void showv(int u){
        cout<<u<<"\t: ";
        for(auto x:adj[u])cout<<x.first<<" ";
        cout<<"\n";
    }
 
    void showg(){
        for(int i=0;i<v;i++)showv(i);
    }
 
    void topo(int u,vector<bool>& visited,vector<int>& t){
        visited[u]=true;
 
        for(auto x:adj[u]){
            if (!visited[x.f])
            {
                topo(x.f,visited,t);
            }
            
        }
        t.push_back(u);    
 
    }
 
    void toposort(vector<int>& t){
        vector<bool> visited(v,false);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                topo(i,visited,t);
            }
        }
        reverse(t.begin(),t.end());
        
    }
 
    void ssspDijkstra(vector<ll>& d,int source){
        d.resize(v,1e18);
        d[source]=0;
 
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        pq.push({0,source});
 
        while (pq.size())
        {
            pll u=pq.top();
            pq.pop();
            if (d[u.s]==u.f)
            {
                for(auto a:adj[u.second]){
                    if (u.f+a.s<d[a.f])
                    {
                        d[a.f]=u.f+a.s;
                        pq.push({d[a.f],a.f});
                    }
                    
                }
                
                
            }
            
 
        }
        
 
    }
 
    void msspDijkstra(vector<vector<long long int>>& c){
        c.resize(v);
        for (int i = 0; i < v; i++)
        {
            ssspDijkstra(c[i],i);
        }
        
    }
 
    
 
 
 
};
 
 
 
 
 
 
bool doub_comp (double a,double b) {
    return (abs(a-b)<0.000000001);
}
bool comp(pii x,pii y) {
    return (x.s<y.s);
}
 
// ll bipow(ll a,ll n){
//     if (n==0)return 1;
//     ll tem=bipow(a,n>>1);
//     if (n&1)return (((tem*tem)%mod)*a)%mod;
//     else return (tem*tem)%mod;
// }
 
ll bipow(ll a,ll n,ll m){
    
    if (n==0)return 1;
    ll tem=bipow(a,n>>1,m);
    if (n&1)return ((tem*tem)%m*a)%m;
    else return (tem*tem)%m;
}
 
ll min(ll a,ll b) {
    if(a<b) return a;
    else return b;
}
ll max(ll a,ll b) {
    if(a>b) return a;
    else return b;
}
 
 
 
void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<vl> g(n,vl (n,1e18));
 
    fo(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        if (g[x-1][y-1]>z)
        {
            g[y-1][x-1]=g[x-1][y-1]=z;
        }
    }
    fo(i,n)g[i][i]=0;
 
    fo(k,n)fo(i,n)fo(j,n){
 
        g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        
    }
 
    fo(i,q){
        int x,y;
        cin>>x>>y;
        if (g[x-1][y-1]>=1e18)
        {
            cout<<-1;
        }else
        {
            cout<<g[x-1][y-1];
        }
        ce;
        
    }
 
 
 
    
 
    
    
    
    
 
    
 
 
    
    
}
 
int main(int argc, char const *argv[])
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
//clock_t z = clock();
    int t=1;
    //cin>>t;
    while (t--)solve();
//cerr<<"Run Time : "<<((double)(clock()-z)/CLOCKS_PER_SEC);
    return 0;
 
}
 
    
