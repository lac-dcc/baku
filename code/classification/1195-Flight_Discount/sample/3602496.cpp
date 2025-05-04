#include <iostream>
#include <vector>
#include <queue>
#define maxn 100010
using namespace std;
int n,m;
vector <pair<int,int>> adj[maxn];
long long dp[2][maxn];
bool dau[2][maxn];
typedef pair<long long,pair<int,int>> iii;
priority_queue<iii,vector<iii>,greater<iii>> pq;
 
void xuly()
{
    for (int i=1; i<=n; i++)
        dp[0][i]=dp[1][i]=1e18;
    dp[0][1]=dp[1][1]=0ll;
    pq.push({dp[0][1],{0,1}});
    pq.push({dp[1][1],{1,1}});
    while (!pq.empty())
    {
        long long du=pq.top().first;
        int tu=pq.top().second.first;
        int u=pq.top().second.second;
        pq.pop();
        if (dau[tu][u]) continue;
        dau[tu][u]=true;
        for (int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i].first;
            int w=adj[u][i].second;
            if (!dau[tu][v])
            {
                long long cost=du+1ll*w;
                if (dp[tu][v]>cost)
                {
                    dp[tu][v]=cost;
                    pq.push({dp[tu][v],{tu,v}});
                }
            }
            if (tu==0&&!dau[1][v])
            {
                long long cost=du+(1ll*(w/2));
                if (dp[1][v]>cost)
                {
                    dp[1][v]=cost;
                    pq.push({dp[1][v],{1,v}});
                }
            }
        }
    }
    long long ans=min(dp[0][n],dp[1][n]);
    cout<<ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int u,v,w; cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    xuly();
}
