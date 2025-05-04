#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define all(x) x.begin(),x.end()
using namespace std;
using pii=pair<int,int>;
typedef long long ll;
const int mx=1e5+1;
int n,m;
vector<int>adj[mx];
vector<int>colour;
vector<int>parent;
int cy_start,cy_end;
bool dfs(int x,int par){
	colour[x]=1;
	for(auto u : adj[x]){
		if(u==par)continue;
		if(colour[u]==0){
			parent[u]=x;
			if(dfs(u,parent[u]))return true;}
		else if(colour[u]==1){
		cy_start=u;
		cy_end=x;
		return true;}}
	colour[x]=2;
	return false;}
void find_cycle(){
	colour.assign(n+1,0);
	parent.assign(n+1,-1);
	cy_start=-1;
	for(int i=1;i<=n;i++){
		if(colour[i]==0&&(dfs(i,parent[i]))){
			break;}}
		if(cy_start==-1){
			cout<<"IMPOSSIBLE"<<endl;
		}
	else{
		vector<int>cycle;
		for(int i=cy_end;i!=cy_start;i=parent[i]){
			cycle.push_back(i);}
			cycle.push_back(cy_start);
			reverse(cycle.begin(),cycle.end());
			cout<<cycle.size()+1<<endl;
			for(auto i : cycle)cout<<i<<" ";
			cout<<cycle[0];}}
int main(){
	IOS;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);}
	find_cycle();}
