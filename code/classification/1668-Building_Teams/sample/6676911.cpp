#include <iostream>
#include <vector>
 
using namespace std;
 
#define fast() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ull unsigned long long
#define endl '\n'
 
 
 
 
vector<vector<int>>adj(100001);
bool vis[100001];
int color[100001];
 
bool DFS(int node , int c){
	vis[node] = true;
	color[node] = c;
	
	for(int child : adj[node])
	{
		if(vis[child] == false){
			bool res = DFS(child , c ^ 1);
			if(res == false) return false;
		}
		else{
			if(color[node] == color[child]) return false;
		}
	}
	
	return true;
}
 
int main()
{
    fast()
	int a , b , n , m;
	cin>>n>>m;
	
	for (int i = 1; i <= m; i++) 
    cin>>a>>b , adj[a].push_back(b) , adj[b].push_back(a);
	
	bool possible = true;
	
	for (int i = 1; i <= n; i++)
	if(vis[i] == false)
	{
		possible = DFS(i , 0);
		if(possible == false) break;
	}
	
	if(!possible) 
    cout<<"IMPOSSIBLE";
	else
	for (int i = 1; i <= n; i++)
    cout<<color[i] + 1<<" ";
}
