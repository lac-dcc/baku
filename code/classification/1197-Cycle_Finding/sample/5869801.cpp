#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
 
using namespace std;
 
struct DATA{
	int u,v,w;
};
 
const int N = 2.5e3+2;
vector<DATA> g;
ll dist[N];
int prv[N];
bool vis[N];
 
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,u,v,w; cin >> n >> m;
	while(m--){
		cin >> u >> v >> w;
		g.push_back({u,v,w});
	}
//	for(int i=1;i<=n;i++) dist[i]=1e18;
	for(int i=0;i<n;i++){
		for(auto&e:g){
			int u=e.u, v=e.v, w=e.w;
//			if(dist[u]==1e18) continue;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
				prv[v]=u;
				if(i==n-1){
					vector<int> ans;
					int k=u;
					while(!vis[k]){
						vis[k]=1;
						k=prv[k];
					}
					ans.push_back(k);
					u=prv[k];
					while(k^u){
						ans.push_back(u);
						u=prv[u];
					}
					ans.push_back(u);
					reverse(ans.begin(), ans.end());
					cout << "YES\n";
					for(auto&e:ans) cout << e << " ";
					return 0;
				}
			}
		}
	}
	cout << "NO";
	
	return 0;
}
