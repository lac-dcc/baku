#include<bits/stdc++.h>
using namespace std;
#define in(x) int x; cin>>x;
#define sin(s) string s; cin>>s;
#define ll long long 
#define lin(x) ll x; cin>>x;
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define pb push_back
#define re(i,n) for(int i=0; i<n; i++)
#define pe(i,a,b) for(int i=a; i<=b; i++)
#define rre(i,n) for(int i=n-1; i>-1; i--) 
#define mp make_pair
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define endl "\n"
#define pi 3.1415926536 
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
//#define mod 998244353
//#define inf LLONG_MAX
#define ninf -INT_MAX
#define inf 100000000000000000
#define MOD 1000000007
#define x first
#define y second
     
     
    // /*ll sum(ll arr[], int mid, int w, ll n)
    // {
    //         ll sum=0;
    //         re(i,w)
    //         {
    //                 sum+=min(abs(mid-arr[i]),n-abs(mid-arr[i]));
    //         }
    //         return sum;
    // }*/
    // /*vi v;
    // void SieveOfEratosthenes(int n)   
    // {   
    //         bool prime[n+1];   
    //         memset(prime, true, sizeof(prime));   
    //         for (int p=2; p*p<=n; p++)   
    //         {    
    //                 if (prime[p] == true)   
    //                 {   
    //                         for (int i=p*p; i<=n; i += p)   
    //                         prime[i] = false;   
    //                 }   
    //         }   
    //         for (int p=2; p<=n; p++)   
    //                 if (prime[p])   
    //                 {
    //                         v.pb(p); 
    //                         //cout<<p<<endl;
    //                 } 
    // } */
     
     
     
     
     
    // ll gcdExtended(ll a, ll b, ll *x, ll *y)  
    // {  
    //     // Base Case  
    //             if (a == 0)  
    //             {  
    //                 *x = 0;  
    //                 *y = 1;  
    //                 return b;  
    //             }  
              
    //             ll x1, y1; // To store results of recursive call  
    //             ll gcd = gcdExtended(b%a, a, &x1, &y1);  
              
    //             // Update x and y using results of  
    //             // recursive call  
    //             *x = y1 - (b/a) * x1;  
    //             *y = x1;  
              
    //             return gcd;  
    // } 
     
    // string tobin(ll n)
    // {
    //         string s = "";
    //         while(n)
    //         {
    //                 if(n%2)
    //                 {
    //                         s+="1";
    //                         n/=2;
    //                 }
    //                 else
    //                 {
    //                         s+="0";
    //                         n/=2;
    //                 }
    //         }
    //         int m = s.length();
    //         re(i,61-m)
    //                 s+="0";
    //         return s;
    // }
     
    // // int bfs(int node, vi adj[], int n)
    // // {
    // //         int cnt=0;
    // //         int vis[n+1]={};
    // //         vis[node]=1;
    // //         queue <int> q;
    // //         q.push(node);
    // //         while(q.size())
    // //         {
    // //                 int u = q.front();
    // //                 q.pop();
    // //                 cnt++;
    // //                 re(i,adj[u].size()) 
    // //                 { 
    // //                         if(!vis[adj[u][i]]) 
    // //                         { 
    // //                                 vis[adj[u][i]]=1;  
    // //                                 q.push(adj[u][i]);      
    // //                         } 
    // //                 } 
    // //         }
    // //         //cout<<"cnt "<<cnt<<endl;
    // //         return cnt;
    // // }      
     
    // // int ncr(int n, int k)   
    // // {   
    // //         int C[n + 1][k + 1];   
    // //         int i, j;   
    // //         for (i = 0; i <= n; i++)   
    // //         {   
    // //                 for (j = 0; j <= min(i, k); j++)   
    // //                 {   
    // //                         if (j == 0 || j == i)   
    // //                                 C[i][j] = 1;   
    // //                         else  
    // //                                 C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%MOD;   
    // //                 }   
    // //         }   
    // //         return C[n][k];   
    // // } 
     
     
     
    // bool isprime(int n)
    // {
    //         pe(i,2,sqrt(n))
    //         {
    //                 if(n%i==0)
    //                         return false;
    //         }
    //         return true;
    // }
    bool compare(const pair<int,int> &i, const pair<int,int> &j) 
    { 
        if(i.x==j.x)
            return i.y>j.y;
        return i.x<j.x;
    }
     
    // int modpowIter(ll a, ll b)   
    // {   
    //         ll ans=1;  
    //         while(b != 0)   
    //         {  
    //                 if(b%2 == 1) 
    //                 ans=(ans*a)%MOD;  
    //                 a=(a*a)%MOD;  
    //                 b /= 2;   
    //         }  
    //         return ans;  
    // } 
     
    // ll p(ll a, ll b)
    // { 
    //         long long x=1, y=a; 
    //         while (b > 0) 
    //         { 
    //                 if (b%2 == 1) 
    //                 { 
    //                         x = (x*y) % MOD; 
    //                 } 
    //                 y = (y*y) % MOD; 
    //                 b /= 2; 
    //         } 
    //         return x % MOD; 
    // } 
     
    // ll inv(ll a){ 
    //         return p(a, MOD-2); 
    // } 
     
    // #define MAXN 10000001 
    // int spf[MAXN]; 
    // void sieve()   
    // {   
    //         spf[1] = 1;   
    //         for (int i=2; i<MAXN; i++)   
    //                 spf[i] = i;   
    //         for (int i=4; i<MAXN; i+=2)   
    //                 spf[i] = 2;   
    //         for (int i=3; i*i<MAXN; i++)   
    //         {   
    //                 if (spf[i] == i)   
    //                 {   
    //                         for (int j=i*i; j<MAXN; j+=i)   
    //                                 if (spf[j]==j)   
    //                                         spf[j] = i;   
    //                 }   
    //         }   
    // } 
 
// int parent[200005];
// int size[200005];
// int find_set(int v) {
//     if (v == parent[v])
//         return v;
//     return parent[v] = find_set(parent[v]);
// }
// void make_set(int v) {
//     parent[v] = v;
//     size[v] = 1;
// }
 
// bool union_sets(int a, int b) 
// {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) 
//     {
//         if (size[a] < size[b])
//             swap(a, b);
//         parent[b] = a;
//         size[a] += size[b];
//         return true;
//     }
//     return false;
// }
 
int main()
{
    FAST
    in(n)
    vi adj[n+1];
    re(i,n-1)
    {
        in(a)
        in(b)
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int last;
    queue <int> q;
    q.push(1);
    //int vis[n+1]={};
    vector<int> vis(n + 1, 0);
    //int par[n+1]={};
    vector<int> par(n + 1, 0);
    //int dist[n+1]={};
    vector<int> dist(n + 1, 0);
    dist[1]=0;
    vis[1]=1;
    par[1]=-1;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        last = u;
        for(auto x: adj[u])
        {
            if(!vis[x])
            {
                vis[x]=1;
                par[x]=u;
                dist[x]=dist[u]+1;
                q.push(x);
            }
        }
    }
    //cout<<last<<" "<<par[last]<<endl;
    //last=par[last];
    int half = dist[last];
    //memset(dist,0,sizeof(dist));
    dist.assign(dist.size(), 0);
    //memset(vis,0,sizeof(vis));
    vis.assign(vis.size(), 0);
    vis[last]=1;
    q.push(last);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        last = u;
        for(auto x: adj[u])
        {
            if(!vis[x])
            {
                vis[x]=1;
                par[x]=u;
                dist[x]=dist[u]+1;
                q.push(x);
            }
        }
    }
    //cout<<last<<endl;
    //cout<<dist[last]<<" "<<half<<endl;
    cout<<dist[last]<<endl;
    return 0;
}
            
 
 
        
