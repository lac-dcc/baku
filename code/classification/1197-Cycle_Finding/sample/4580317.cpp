#include<bits/stdc++.h>
using namespace std;
int start = -1,end1 = -1;
void dfs(int node,vector<long long>&value,vector<int>&cur,vector<int>&parent,vector<vector<pair<int,int>>>&adj) {
	cur[node] = 1;
	for(pair<int,int> i:adj[node]) {
 
		if(parent[i.first]!=0) {
			if(cur[i.first]) {
				long long ff = value[node]-value[i.first]+i.second;
				if(ff<0) {
					start = node;
					end1 = i.first;
				}
			}
			continue;
		}
		value[i.first] = value[node] + i.second;
		parent[i.first] = node;
		dfs(i.first,value,cur,parent,adj);
	}
	cur[node] = 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<vector<int>>adj(m,vector<int>(3));
	for(int i =0 ; i<m; i++) {
		int x,y,z;
		cin>>adj[i][0]>>adj[i][1]>>adj[i][2];
	}
	vector<int>parent(n+1);
	vector<long long> value(n+1,1e18);
	value[1] = 0LL;
	for(int i=1; i<=n-1; i++) {
		for(int j = 0; j<m; j++) {
			if(value[adj[j][1]]>value[adj[j][0]] + adj[j][2]) {
				value[adj[j][1]]=value[adj[j][0]] + adj[j][2];
				parent[adj[j][1]] = adj[j][0];
			}
		}
	}
	int C = -1;
	for(int j = 0; j<m; j++) {
		if(value[adj[j][1]]>value[adj[j][0]] + adj[j][2]) {
			if(parent[adj[j][1]]==0) {
				parent[adj[j][1]] = adj[j][0];
			}
			C=adj[j][1];
			break;
		}
	}
	if(C==-1) {
		cout<<"NO";
		return 0;
	}
//	for(int i =1;i<=n;i++) {
//		cout<<parent[i]<<" ";
//	}
//	cout<<endl;
	vector<int>cycle;
//	cout<<C<<endl;
	for(int i =0;i<n;i++) {
		C = parent[C];
	}
//	cout<<C<<endl;
	for(int i=C;;i = parent[i]) {
		cycle.push_back(i);
		if(i==C&&cycle.size()>1) {
			break;
		}
	}
	reverse(cycle.begin(),cycle.end());
	cout<<"YES"<<endl;
	for(int i:cycle) {
		cout<<i<<" ";
	}
}
