#include<bits/stdc++.h>
using namespace std;
 
ifstream in("input");
 
int num_nodes;
vector<int> graph[200000];
bool visited[200000];
int max_distance[200000];
 
void read(){
	cin>>num_nodes;
	int a,b;
	for(int i=0;i<num_nodes-1;i++){
		cin>>a>>b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
}
 
int furthest;
int maxdistance=-1;
 
void dfs(int node,int depth){
	visited[node]=true;
	if(depth>maxdistance){
		furthest=node;
		maxdistance=depth;
	}
 
	for(int child:graph[node]){
		if(!visited[child])
			dfs(child,depth+1);
	}
	visited[node]=false;
}
 
void setMaxDistance(int node,int depth){
	visited[node]=true;
	max_distance[node]=max(max_distance[node],depth);
	for(int child:graph[node]){
		if(!visited[child])
			setMaxDistance(child,depth+1);
	}
	visited[node]=false;
}
 
int getFurthest(int node){
	maxdistance=-1;
	dfs(node,0);
	return furthest;
}
 
void solve(){
 
	int first=getFurthest(0);
	setMaxDistance(first,0);
	int second=getFurthest(first);
	setMaxDistance(second,0);
 
	for(int i=0;i<num_nodes;i++){
		cout<<max_distance[i]<<" ";
	}
 
}
 
int main(){
	read();
	solve();
	return 0;
}
