#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define endl '\n'
#define typ pair<ll,pair<int,bool>>
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>>> adj(n+1);
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    priority_queue<typ,vector<typ>,greater<typ>> q;
    vector<vector<ll>> dis(n+1,vector<ll>(2,1e18));
    q.push({0,{1,1}});
    dis[1][1] = 0;
    dis[1][0] = 0;
    while(q.size()){
        typ cur = q.top();      q.pop();
        if(cur.first > dis[cur.second.first][cur.second.second]) continue;
        for(auto ch : adj[cur.second.first]){
            if(cur.first + ch.second < dis[ch.first][cur.second.second]){
                dis[ch.first][cur.second.second] = cur.first + ch.second;
                q.push({cur.first + ch.second,{ch.first,cur.second.second}});
            }
            if(cur.second.second && cur.first + ch.second/2 < dis[ch.first][0]){
                dis[ch.first][0] = cur.first + ch.second/2;
                q.push({cur.first + ch.second/2,{ch.first,0}});
            }
        }
    }
    cout<<dis[n][0]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
