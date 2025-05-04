#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
vector <ll> adj[100001];
bool visited[100001];
ll check[100001];
bool kt = true;
void bfs(int k){
 
	check[k] = 1;
	queue <int> q;
	q.push(k);
	visited[k] = true;
	while (!q.empty()){
		int v = q.front();
		q.pop();
		for (int x : adj[v]){
				if (check[x] == 0){
					if (check[v] == 1)
						check[x] = 2;
					else check[x] = 1;
				}else{
					if (check[x] == check[v]){
						kt = false;
						break;
					}
				}
				if (!visited[x]){	
				q.push(x);
				visited[x] = true;		
			}
		}
		if (!kt)
			break;
	}
}
int main(){
	fast
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
	
	for (int i = 1; i <= n; i++){
		if (kt){
			if (!visited[i]){
				bfs(i);
			}
		}
		else break;
	}
	if (!kt){
		cout <<"IMPOSSIBLE";
	}else{
		for (int i = 1;i <= n; i++)
			cout << check[i] <<" ";
		}
}
