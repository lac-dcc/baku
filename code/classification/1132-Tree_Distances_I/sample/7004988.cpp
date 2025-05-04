#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")
// #pragma GCC target("sse4.2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1000000007
#define mod1 998244353
#define fr(i, a, b) for (ll i = a; i <= b; i++)
#define rev(i, a, b) for (ll i = a; i >= b; i--)
#define ub upper_bound
#define lb lower_bound
using namespace std;
 
const ll INF = 1e18;
const ll N = 2e5 + 10;
vector<ll>g[N];
ll h1[N+5] = {0};
ll s1[N+5] = {0};
 
void dfs1(ll node,ll parent){
      for(auto x: g[node]){
            if(x!=parent){
                  dfs1(x,node);
                  s1[node] = max(s1[node],s1[x]);
            }
      }
      s1[node]++; 
}
 
void dfs2(ll node,ll parent){
      ll smaxh = 0; ll maxh = 0;
      for(auto x: g[node]){  
            if(x==parent)
                   continue;          
            maxh = max(maxh,s1[x]);
      }
      ll ct = 0;
      for(auto x: g[node]){
            if(x==parent)
                  continue;
            if(maxh == s1[x])
                  ct++;
            else
                  smaxh = max(smaxh,s1[x]);
      }
      if(ct >= 2){
            smaxh = maxh;
      }
      for(auto x: g[node]){
            if(x==parent)
                  continue;
            if(s1[x] == maxh)
                  h1[x] = 1 + max(h1[node],1 + smaxh);
            else
                  h1[x] = 1 + max(h1[node],1 + maxh);
            dfs2(x,node);
      }
 
}
 
void solve()
{
         ll n; cin >> n;
         fr(i,1,n-1){
                  ll x; ll y;
                  cin >> x >> y;
                  g[x].pb(y);
                  g[y].pb(x);                  
         }
         dfs1(1,-1);         
         dfs2(1,-1);
 
         fr(i,1,n){
                  cout << max(h1[i],s1[i]) - 1 << " ";
         }
 
}
 
 
int main()
{
            #ifndef ONLINE_JUDGE
                        freopen("Input.txt", "r", stdin);
                        freopen("Output.txt", "w", stdout);
            #endif
            ios_base::sync_with_stdio(false);
            cin.tie(0);
            cout.tie(0);
            ll tt;
            tt = 1;
            fr(i, 1, tt)
            {
                    solve();
            }
}         
