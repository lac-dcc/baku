#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define double long double
#define inf LLONG_MAX
#define mod 1000000007
#define vi vector<int>
#define pi pair<int,int>
#define PB push_back
#define F first
#define S second
#define forn for(int i=0;i<n;i++)
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
int n,m;
 
int INF = 1e16;
vector<vector<pair<int, int>>> adj(100001),temp(100001);
vector<int> d,d2,p;
 
void dijkstra(int s) {
    d.assign(n, INF);
    p.assign(n, -1);
 
    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;
 
        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
 
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
 
void dijkstra2(int s) {
    d2.assign(n, INF);
    p.assign(n, -1);
 
    d2[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d2[v])
            continue;
 
        for (auto edge : temp[v]) {
            int to = edge.first;
            int len = edge.second;
 
            if (d2[v] + len < d2[to]) {
                d2[to] = d2[v] + len;
                p[to] = v;
                q.push({d2[to], to});
            }
        }
    }
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	cout << fixed << setprecision(6);
 
	cin>>n>>m;
	while(m--)
	{
		int a,b,w;
		cin>>a>>b>>w;
		a--,b--;
		adj[a].push_back({b,w});
	}
	dijkstra(0);
	for(int i=0;i<n;i++)
	{
		for(auto c:adj[i])
		{
			temp[c.first].push_back({i,c.second});
		}
	}
	dijkstra2(n-1);
	int ans=INF;
	for(int i=0;i<n;i++)
	{
		if(d[i]!=INF)
		for(auto c:adj[i])
		{
			if(d2[c.first]!=INF)
			{
				ans=min(ans,d[i]+d2[c.first]+c.second/2);
			}
		}
	}
	cout<<ans;
}
 
