#include<bits/stdc++.h>
using namespace std;
 
 
 
 
int team[100005];
int f=1;
vector<vector<int>> adj;
 
void dfs(int u,int x){
	team[u]=x;
	int c = (x==1)?2:1;
	for(auto v:adj[u]){
		if(team[v]==0){
			dfs(v,c);
		}
		else if(team[v]==x){
			f=0;
		}
	}
}
 
int main(){
	int n,m;
	cin>>n>>m;
	adj.resize(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(team,0,sizeof(team));
	for(int i=0;i<n;i++){
		if(team[i]==0){
			dfs(i,1);
			if(f==0){
				break;
			}
		}
	}
	if(f==0){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		for(int i=0;i<n;i++){
			cout<<team[i]<<" ";
		}
		cout<<endl;
	}
}
