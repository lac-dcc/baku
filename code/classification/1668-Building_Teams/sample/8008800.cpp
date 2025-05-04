// Author : Nguyễn Cửu Chí Bảo
#include <bits/stdc++.h>
 
#define fi first;
#define sec second;
#define TASK "LOL"
#define input_file TASK".inp"
#define output_file TASK".out"
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long us;
 
const int N = 2e5 + 5;
vector<int>dt[N];
int a[N],n,m;
bool team[N];
bool visited[N];
bool possible;
void DFS(int u,int y = 0){
	for(auto it : dt[u]){
		if(it != y){
		if(!visited[it]){
			team[it]=!team[u];
			visited[it]=true;
			DFS(it,u);
		}
		else 
		if(team[it]==team[u])possible = false;
 
	}
		}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
	freopen(input_file, "r", stdin);
	freopen(output_file, "w", stdout);
	#endif
	cin>>n>>m;
	possible = true; 
	for(int i = 1; i <= m; i ++){
		int x,y;
		cin>>x>>y;
		dt[x].push_back(y);
		dt[y].push_back(x);	
}
for(int i = 1; i <= n; i ++){
	if(!visited[i]){
		visited[i]=true;
		DFS(i);
	}
}
// for(int i = 1; i <= n; i ++){
// 	cout<<team[i]<< " ";
// }
// cout<<endl;
if(!possible){cout<<"IMPOSSIBLE"<<endl;}
else {
	for(int i = 1; i <= n; i ++){
		cout<<(team[i] ? 2 : 1)<< " ";
	}
}
}
