#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long
 
priority_queue<pair<ll,pair<ll,ll>>>pq;
vector<pair<ll,ll>>adj[100005];
ll dist[2][100005],vis[2][100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,st,ed,m,pep;
    cin >> n >> m;
    for(int i=1;i<=n;i++)dist[0][i]=dist[1][i]=1e15;
    dist[0][1]=dist[1][1]=0;
    for(int i=1;i<=m;i++){
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
    }
    pq.push({0,{1,0}});
    while(!pq.empty()){
        ll now=pq.top().s.f;
        ll nowdist=-pq.top().f;
        ll tick=pq.top().s.s;
        pq.pop();
        if(vis[tick][now])continue;
        vis[tick][now]=1;
        for(auto cost:adj[now]){
            ll nxt=cost.f;
            ll pc=cost.s;
            if(tick==0){
                if(nowdist+(pc/2)<dist[1][nxt]){
                    pq.push({-(nowdist+(pc/2)),{nxt,1}});
                    dist[1][nxt]=nowdist+(pc/2);
                }
            }
            if(nowdist+pc<dist[tick][nxt]){
                pq.push({-(nowdist+pc),{nxt,tick}});
                dist[tick][nxt]=nowdist+pc;
            }
        }
    }
    cout << dist[1][n];
    return 0;
}
