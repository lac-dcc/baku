#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
int d[200001];
int d2[200001];
vector<int> adj[200001];
 
int dfs(int a, int b, int c){
	d[a]=c;
	int ans=0;
	for(auto i: adj[a]){
		if(i!=b){
			int temp=dfs(i, a, c+1);
			if(d[temp]>d[ans]) ans=temp;
		}
	}
	if(ans==0) return a;
	else return ans;
}
 
int dfs2(int a, int b, int c){
	d2[a]=c;
	int ans=0;
	for(auto i: adj[a]){
		if(i!=b){
			int temp=dfs2(i, a, c+1);
			if(d2[temp]>d2[ans]) ans=temp;
		}
	}
	if(ans==0) return a;
	else return ans;
}
 
int main(){
	int x;
	cin>>x;
	for(int i=0; i<x-1; i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int a=dfs(1, -1, 0);
	int b=dfs(a, -1, 0);
	int c=dfs2(b, -1, 0);
	for(int i=1; i<=x; i++){
		cout<<max(d[i], d2[i])<<" ";
	}
}
