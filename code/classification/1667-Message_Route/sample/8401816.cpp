#include<bits/stdc++.h>
using namespace std;
 
int bio[100010];
int dp[100010];
vector<int> g[100010];
queue<int> kju;
 
int n, m;
int sol;
int x;
 
int put[100010];
 
int bfs(int x){
	kju.push(x);
	
	while(!kju.empty()){
		x = kju.front();
		bio[x] = 1;
		for(int i : g[x]){
			if(bio[i] == 0){
				kju.push(i);
				bio[i] = 1;
				dp[i] = dp[x] + 1;
			}
		}
		
		kju.pop();
	}
	
	return dp[n-1] + 1;
}
 
int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	sol = bfs(0);
	
	if(sol == 1){
		cout << "IMPOSSIBLE";
		return 0;
	}
	else cout << sol << "\n";
	
	x = n-1;
	
	for(int i = dp[n-1]; i > 0; i--){
		for(int j : g[x]){
			if(dp[j] == i-1){
				put[i-1] = j;
				x = j;
				break;
			}
		}
	}
 
	for(int i = 0; i < sol-1; i++) cout << put[i]+1 << " ";
	cout << n;
 
}
 
