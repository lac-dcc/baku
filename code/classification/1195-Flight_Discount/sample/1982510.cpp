#include<bits/stdc++.h>
using namespace std;
#define ll long long
void dij(vector<pair<int, ll>> v[], int i, bool vis[], ll dist[]){
	
	dist[i] = 0;
 
	set<pair<ll, int>> s;
	s.insert(make_pair(0, i));
 
	while(!s.empty()){
		pair<ll, int> x = *(s.begin());
		s.erase(s.begin());
		int src = x.second;
 
		vis[src] = true;
		for(auto it=v[src].begin();it!=v[src].end();it++){
			
			int d = (*it).first;
			ll r = (*it).second;
 
			if(dist[d] > dist[src] + r){
 
				if(dist[d] != LLONG_MAX)
					s.erase(s.find(make_pair(dist[d], d)));
 
				dist[d] = dist[src] + r;
				s.insert(make_pair(dist[d], d));
			}
		}
	}
}
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	//use dijkstra to find all the visited nodes and their distances from  1 ,
	//reverse the edges and find it all for n;
	//now iterate it using normal dfs and visited array
	//visted[*it] = true and visited1[i] = true && visited2[*it] = true)
	//ans = min(ans, dist[1][i] + dist[*it][n] + dist[i][n]/2;
	int n, m;
	cin >> n >> m;
 
	vector<pair<int, ll>> v[n];
	vector<pair<int, ll>> t[n];
 
	int x, y;
	ll a;
	for(int i=0;i<m;++i){
		cin >> x >> y >> a;
		v[x-1].push_back(make_pair(y-1, a));
		t[y-1].push_back(make_pair(x-1, a));
	}
 
	bool vis1[n];
	memset(vis1, false, sizeof(vis1));
 
	ll dist1[n];
	fill(dist1, dist1+n, LLONG_MAX);
 
	dij(v, 0, vis1, dist1);
 
	bool vis2[n];
	memset(vis2, false, sizeof(vis2));
 
	ll dist2[n];
	fill(dist2, dist2+n, LLONG_MAX);
 
	dij(t, n-1, vis2, dist2);
 
	bool vis[n];
	memset(vis, false, sizeof(vis));
 
	
	ll ans = LLONG_MAX;
	for(int i=0;i<n;++i)
		for(auto it=v[i].begin();it!=v[i].end();it++)
			if(vis1[i] == true && vis2[(*it).first] == true){
				ll tmp = dist1[i] + dist2[(*it).first] + floor(((*it).second)/2);
				ans = min(ans, tmp);
			}
 
	cout << ans << endl;
 
return 0;
}
