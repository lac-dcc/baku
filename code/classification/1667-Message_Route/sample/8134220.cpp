#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n,m;cin>>n>>m;
	vector<vector<int>> graph(n+1);
	while(m--){
		int u,v;cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	queue<int> q;
	unordered_map<int,int> visit;
	vector<int> parent(n+1,-1);
	q.push(1);
	visit[1]=1;
	parent[1]=0;
	while(!q.empty()){
		int u= q.front();q.pop();
		if(u==n){break;}
		for(int v:graph[u]){
			if(!visit[v]){q.push(v);visit[v]=1;parent[v]=u;}
		}
	}
	if(parent[n]== -1){
		cout<<"IMPOSSIBLE";
	}
	else{
		vector<int> res;
		int index=n;
		while(parent[index]!= -1){
			res.push_back(index);
			index=parent[index];
		}
		reverse(res.begin(),res.end());
		//res.push_front(index);
		cout<<res.size()<<"\n";
		for(int x:res)cout<<x<<" ";
	}
}
