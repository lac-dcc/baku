// CALL ME DADDY
//                 SUNO MERI DIL KI BAAT:
 
//   | CHINTI CHADI PAHAD PAR..........ANGREZON KA ZAMANA THA....... |
//   | DP KI BANDOOK THI............AUR EXPERT PAR NISHANA THA...... |
 
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define vll vector<ll>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
 
 const int N = 1e5+5;
 void solve(){
             int n,m;cin>>n>>m;
             int trial;
             vector<int> adj[N];
             vector<int> ans;
             vector<int> vis(n+1,0);
             vector<int> dis(n+1,0);
             for(int i=0;i<m;i++)
             {
                 int a,b;cin>>a>>b;
                 adj[a].pb(b);
                 adj[b].pb(a);
             }
             queue<int> q;
             q.push(1);
             vis[1] = 1;
             while(!q.empty())
             {
                 int curr = q.front();
                 q.pop();
                 if(curr==n) break;
                 for(auto child : adj[curr])
                 {
                     if(!vis[child])
                     {
                         vis[child]=1;
                         dis[child] = curr;
                         q.push(child);
                     }
                 }
             }
             if(vis[n]==0)
             {
                 cout<<"IMPOSSIBLE"<<endl;
             }
             else
             {
                 ans.pb(n);
                 trial = n;
                 while(trial!=1)
                 {
                     trial = dis[trial];
                     ans.pb(trial);
                 }
                 cout<<ans.size()<<endl;
                 reverse(all(ans));
                 for(auto i:ans)
                 {
                     cout<<i<<" ";
                 }
 
             }
    }
 
int main(){
    fast;
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    ll testcase = 1;
    //cin >> testcase;
    while (testcase--){
        solve();
    }
    return 0;
}
