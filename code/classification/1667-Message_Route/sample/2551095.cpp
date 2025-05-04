#include <bits/stdc++.h>
using namespace std;
vector<int> graphs[100002];
bool vis[100002];
int steps[100002]={0};
int previousStep[100002];
vector<int> soln;
queue<pair<int,int>> q;
void bfs(int x,int y){
	steps[1]=1;
	previousStep[1]=0;
	q.push(make_pair(x,0));
	vis[x]=true;
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		for( auto child : graphs[u.first]){
			if(child!=u.second && !vis[child]){
				q.push(make_pair(child,u.first));
				vis[child]=true;
				//  if(!steps[child] || steps[child] > steps[u.first] + 1)
                steps[child] = steps[u.first] + 1;
                previousStep[child]=u.first;
                
			}
		}
	}
	if(vis[y]){
	cout<<steps[y]<<"\n";
	int kid=y;
	while(previousStep[kid]!=0){
	    soln.push_back(previousStep[kid]);
	    kid=previousStep[kid];
	}
	for(int i=soln.size()-1;i>=0;i--){
	    cout<<soln[i]<<" ";
	}
	cout<<y;
	}
	else
	cout<<"IMPOSSIBLE";
}
 
int main() {
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		graphs[a].push_back(b);
		graphs[b].push_back(a);
	}
	bfs(1,n);
	return 0;
}
