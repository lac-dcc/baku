#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll INF = INT64_MAX;
const ll NINF = INT64_MIN;
#define endl "\n"
const ll N = 1e9+7;
 
ll lcm(ll a, ll b) 
{ 
    return a / __gcd(a, b) * b; 
}
 
ll binpow(ll a, ll b,ll mod)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
ll fun(ll node,vector <ll> *graph,vector <ll> &vis,vector <ll> &downPath)
{
    ll ans = 0;
    for(auto it : graph[node])
    {
        if(!vis[it])
        {
            vis[it] = 1;
            ll x = fun(it,graph,vis,downPath);
            ans = max(ans,1 + x);
        }
    }
    return downPath[node] = ans;
}
 
bool comp(const pair<ll,ll> &a,const pair<ll,ll> &b)
{
    if(a.first==b.first)
        return a.second < b.second;
    return a.first < b.first;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin >> t;
    while(t--)
    {    
        ll a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,q=0,u=0,v=0,w=0,x=0,y=0,z=0,sum=0,res=0,ans=0,rem=0,ct=0,maxim=0,minim=0;
        string p,r,s,str;
        // cin >> n;
        //ll arr[n];
        // for(ll i = 0; i < n; ++i)
        // {
        //     cin >> arr[i];
        // }
 
        // ---------------- PREFIX SUM ---------------------------
        // ll hsh[n];
        // hsh[0]=arr[0]; 
        // for(ll i = 1; i < n; ++i)
        // {
        //      hsh[i]=hsh[i-1]+arr[i];
        // }
 
        // ---------------- SUFFIX SUM ---------------------------
        // hsh[n-1]=arr[n-1]; 
        // for(ll i = n-1; i >= 0; --i)
        // {
        //      hsh[i]=hsh[i+1]+arr[i];
        // }
 
        // ----------------UNDIRECTED GRAPH INPUT ---------------------------
        cin >> n;
        m = n - 1;
        vector <ll> graph[n+1];
        for(ll i = 0; i < m; ++i)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // ----------------DIRECTED GRAPH INPUT ---------------------------
        // cin >> n >> m;
        // vector <ll> graph[n+1];
        // for(ll i = 0; i < m; ++i)
        // {
        //     cin >> u >> v;
        //     graph[u].push_back(v);
        // }
 
        // ---------------- DFS TAVERSAL ---------------------------
        vector <ll> downPath(n+1,0);
        //ll vis1[n+1] = {0};
	vector<ll> vis1(n + 1, 0);
        //ll vis[n+1] = {0};
	vector<ll> vis(n + 1, 0);
        vis1[1] = 1;
        fun(1,graph,vis1,downPath);
        queue <ll> qu;
        qu.push(1);
        vis[1] = 1;
        while(!qu.empty())
        {
            ll node = qu.front();
            qu.pop();
            vector <ll> vec;
            for(auto it : graph[node])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    vec.push_back(downPath[it]);
                    qu.push(it);
                }
            }
            sort(vec.rbegin(), vec.rend());
            if(vec.size()>1)
            {
                sum = vec[0] + vec[1];
                maxim = max(maxim,sum + 2);
            }
            else if(vec.size()==1)
                maxim = max(maxim,vec[0]+1);
        }
        cout << maxim << endl;
    }
    return 0;
}
