	#include <bits/stdc++.h> 
using namespace std;
 
/*
*** This is the template for cp competition.
 
*/
#define ull unsigned long long
#define ll long long
#define v vector
#define printv(X) for(auto x:X) cout<<x<<','; cout<<endl;
 
template<typename... Args>
void print(Args&&... args) {
    std::ostringstream oss;
    ((oss << args << " "), ...);
    std::cout << oss.str() << std::endl;
}
const ll INF = LLONG_MAX-1;
 
int n,m;
 
v<ll> dijkstra(int rt,v<v<pair<int,int>>>& adj){
	v<bool> visited(n+1,0);
	set<pair<ll,ll>> st;
	v<ll>d1(n+1,0);
 
	for(int i=1;i<=n;i++)
	{ if(i==rt) continue;
		st.insert({INF,i});
		d1[i] = INF;
	}
	st.insert({0,rt});
	d1[rt]= 0;
	while(st.size()>0){
	auto it = st.begin();
	ll d = it->first, x = it->second;
	st.erase(it);
	if(visited[x]) continue;
	visited[x] = true;
	if(d1[x] == INF) continue;
	for(auto nxt:adj[x])
	{ int nx = nxt.first,nw = nxt.second;
		if(d1[nx]>d1[x]+nw){
			st.erase({d1[nx],nx});
			d1[nx] = d1[x]+nw;
			st.insert({d1[nx],nx});
		}
	}
	}
	return d1;
}
v<v<pair<int,int>>> adj;
v<v<pair<int,int>>> adj2;
 
int main(){
cin>>n>>m;
adj.resize(n+1,{});
adj2.resize(n+1,{});
for(int i=0;i<m;i++){
	int a,b,c; cin>>a>>b>>c;
	adj[a].push_back({b,c}); 
	adj2[b].push_back({a,c});
}
//
v<ll> d1 = dijkstra(1,adj);
v<ll> d2 = dijkstra(n,adj2);
ll result = INF;
for(int i=1;i<=n;i++){
	for(auto e:adj[i]){
	int to = e.first, w = e.second;
	if(d1[i]!=INF && d2[to]!=INF)
		result=min(result,(ll)(w/2+d1[i]+d2[to]));//i know why my friend
	}
}
cout<<result<<endl;
 
return 0;
}
