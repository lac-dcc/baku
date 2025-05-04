#include<bits/stdc++.h>
 
using namespace std;
 
 
int n;
 
vector<vector<int>> p;
 
vector<int> subs(n);
 
bool visited[1000000];
long long total[1000000];
 
long long dfs(int node){
	visited[node] = true;
	total[node] = 0;
	for (auto el : p[node]){
		if(!visited[el]){
			total[node] += 1 + dfs(el);
		}
	}
	return total[node];
}
 
 
int main(){
	cin>>n;
	p.resize(n);
	for(int i = 0; i <n-1;i++){
		int a;
		cin>>a; a--;
		p[a].push_back(i+1);
	}
	dfs(0);
	for(int i = 0; i < n; i++){
		cout<<total[i]<<" ";
	}
	return 0;
}
