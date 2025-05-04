# include<bits/stdc++.h>
using namespace std;
vector<int> adj[100005];
bool  bag[100005],vis[100005] , ok=true;
int n , m , t=0;
void dfs(int x , bool c){
	vis[x]=true;
	bag[x]=c;
	for(auto &y:adj[x]){
		if(!vis[y]) dfs(y,!c);
		else if(bag[y]==c)  ok=false;
	}
}
int main(){
	cin>>n>>m;
	for(int i=0 , k , l ; i<m ; i++){
		cin>>k>>l;
		adj[k].push_back(l);
		adj[l].push_back(k);
	}
	for( int i=1 ; i<=n ; i++) if(vis[i]==0) dfs(i,t);
	if(!ok) cout<<"IMPOSSIBLE";
	else{
			for(int i=1 ; i<=n ; i++){
		if(bag[i]==0) cout<<2<<" ";
		else cout<<1<<" ";
	}
	}
}
