#include <bits/stdc++.h>
#include <vector>
 
#define endl "\n"
#define MAXN 202020
 
using namespace std;
int n, m;
vector<vector<int>>adj;
vector<int> par;
vector<bool> vis;
void bfs(){
vis[1]=true;
queue<int> q;
q.push(1);
while(!q.empty()){
    int k = q.front();
    q.pop();
    for(auto i: adj[k]){
        if(!vis[i]){
            vis[i]=true;
            par[i]=k;
            q.push(i);
        }
    }
}
}
 
int main()
{
    
    cin>>n>>m;
    	adj.resize(n+1);
	vis.resize(n+1);
	par.resize(n+1);
    for (int i = 0; i < m; i++)
    {
        int n1,n2;
        cin>>n1>>n2;
         adj[n1].push_back(n2);
         adj[n2].push_back(n1);   
    }
    	for(int i = 0; i<=n; ++i)
	{
		par[i] = -1;
	}
 
    bfs();
    
    if(par[n] == -1)
	{
		cout <<  "IMPOSSIBLE";
		return 0;
	}
    
    int candidate = n;
	stack<int> stk;
	while(candidate != -1)
	{
		stk.push(candidate);
		candidate = par[candidate];
	}
 
	cout << stk.size() << endl;
 
	while(!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
 
   
       
    return 0;
}


