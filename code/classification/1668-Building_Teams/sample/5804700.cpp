//In the name of Allah, The Most Gracious and The Most Merciful
#include<bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define debug(...) void(0);
#else
#include "debug.hpp"
#endif
#define gcd __gcd
#define ll long long
#define test cout<<"PASS"
using namespace std;
////////////////////////////////////////////////////
////////////////////////////////////////////////////
void iAmFirst() {
    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
        //freopen("./output.txt", "w", stdout);
        freopen("./error.txt", "w",stderr);
    #endif
}
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
//MATHS
////////////////////////////////////////////////////
/*void sieve()
{
    for(int i=1;i<zoz;i++)store[i]=i;
    for(int i=4;i<zoz;i+=2)store[i]=2;
    for(int i=3;i*i<zoz;i++)
    {
        if(store[i]==i)
        {
             for(int j=i*i;j<zoz;j+=i)
             {
                if(store[j]==j)store[j]=i;
             }
        }
    }
}*/
////////////////////////////////////////////////////
bool isPrime(int n)
{
    if(n==2)return true;
    if(n<=1)return false;
    if(n<=3)return true;
    if(n%2==0 || n%3==0)return false;
    for(int i=5;i*i<=n;i=i+6)
    if(n%i==0 || n%(i+2)==0)return false;
    return true;
}
////////////////////////////////////////////////////
int gcdE(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdE(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
////////////////////////////////////////////////////
int fast_power(int a,int b)
{
    if(b==0){return 1;}
    if(b%2==0){return fast_power(a,b/2)*fast_power(a,b/2);}
    return fast_power(a,b-1)*a;
}
////////////////////////////////////////////////////
////////////////////////////////////////////////////
 
void solution()
{
          ll n,m;
          cin>>n>>m;
          vector<vector<ll>> v(n+1);
          vector<ll> vis(n+1);
          for(ll i=0;i<m;i++)
          {
            ll a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
          }  
         queue<ll> q;
        //debug(v);
         for(ll i=1;i<n;i++)
         {
            if(vis[i]==0)
            {
                q.push(i);
                vis[i]=1;
                while(!q.empty())
                {
                    ll x=q.front();
                    
                    
                    q.pop();
                    for(auto u:v[x])
                    {
                        if(vis[u]==vis[x])
                        {
                            cout<<"IMPOSSIBLE";
                            return;
                        }
                        if(vis[u]==0)
                        {
                            vis[u]=3-vis[x];
                            q.push(u);
                        }
                    }
                }
            }
         }
         for(ll i=1;i<=n;i++)
         {
            cout<<vis[i]<<" ";
         }
 
}
////////////////////////////////////////////////////
////////////////////////////////////////////////////
int32_t main()
{
    fast();
    iAmFirst();
    int t;
    t=1;
  //  cin>>t;
    while(t--)
    {
        solution();
        cout<<"\n";
    }
}
