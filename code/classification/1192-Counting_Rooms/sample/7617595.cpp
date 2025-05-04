#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e3+5;
// int adjMat[N][N];
vector<string> graph;
bool visited[N][N];
int n, m;
 
void init_code(){
    #ifndef PRACHAW
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
 
bool isValid(int i, int j){
	return (i>=0 && i<n && j>=0 && j<m);
}
 
void bfs(int i, int j){
	// here s = (i,j)
	if(!isValid(i,j)) return;
	if(visited[i][j]) return;
	if(graph[i][j] == '#') return;
 
	visited[i][j] = true;
 
	bfs(i, j-1);
	bfs(i, j+1);
	bfs(i-1, j);
	bfs(i+1, j);
}
 
int main()
{
    
 
    cin>>n>>m;
 
    for (int i = 0; i < n; ++i)
    {
    	string x;
    	cin>>x;
    	graph.push_back(x);
    }
 
    int countRoom = 0;
 
    for(int i = 0; i<n; i++){
    	for(int j = 0; j<m; j++){
    		if(graph[i][j] == '#') continue;
     		if(visited[i][j]) continue;
     		bfs(i,j);
     		countRoom++;
    	}
    }
 
    cout<<countRoom<<endl;
 
    return 0;
}
