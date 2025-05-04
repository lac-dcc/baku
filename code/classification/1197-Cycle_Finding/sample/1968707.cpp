#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
 
const int mxN=2.5e3;
int n, m, p[mxN];
ll ans[mxN];
vector<ar<ll, 2>> adj[mxN];
vector<int> adj2[mxN];
ll d[mxN];
bool vis[mxN], vis2[mxN];
 
void dfs(int u) {
	vis[u]=1;
	for(int v : adj2[u])
		if(!vis[v])
			dfs(v);
}
 
void dfs2(int u) {
	vis2[u]=1;
	for(ar<ll, 2> v : adj[u])
		if(!vis2[v[1]])
			dfs2(v[1]);
}
 
int main() {
	cin >> n >> m;
	for(int i=0; i<m; ++i) {
		int a, b, c;
		cin >> a >> b >> c, --a, --b;
		adj[a].push_back({c, b});
		adj2[b].push_back(a);
	}
	//dfs(n-1);
	//dfs2(0);
	//memset(d, 0xc0, sizeof(d));
	//d[0]=0;
	for(int i=0; i<5*n; ++i) {
		bool ch=0;
		for(int j=0; j<n; ++j)
			for(ar<ll, 2> a : adj[j]) {
				//d[a[1]]=max(d[a[1]], d[j]+a[0]);
				//if(a[1]==n-1)
					//cout << j << " " << d[j]+a[0] << endl;
				if(d[j]+a[0]<d[a[1]]) {
					//if(vis[a[1]]&&vis2[a[1]])
						ch=1;
					d[a[1]]=d[j]+a[0];
					p[a[1]]=j;
					//cout << a[1] << " " << d[a[1]] << endl;
					if(i==n-1) {
						cout <<  "YES\n";
						while(!vis[j]) {
							vis[j]=1;
							j=p[j];
						}
						int u=j;
						vector<int> ans;
						//cout << u;
						ans.push_back(u);
						u=p[u];
						while(u^j) {
							//cout << " " << u;
							ans.push_back(u);
							u=p[u];
						}
						//cout << " " << u;
						ans.push_back(u);
						reverse(ans.begin(), ans.end());
						for(int a : ans)
							cout << a+1 << " ";
						return 0;
					}
				}
			}
		//if(i>=n-1&&ch) {
			//cout << -1;
			//return 0;
		//}
		//ans[i]=d[n-1];
	}
	//if(n>1&&ans[n-2]<ans[n-1])
		//cout << -1;
	//else
		//cout << ans[n-1];
	//cout << d[n-1];
	cout << "NO";
}
