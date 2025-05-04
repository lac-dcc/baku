#include<bits/stdc++.h>
#define int long long
using namespace std;
 
	int32_t main(){ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int edge, node, x, y, cluster = 0;
	cin>>node>>edge;
	
	
	int visited [node+1000];
	//vector<int> matrix [node+1000] = { };
	vector< vector<int> > matrix(node+1000);
	vector<int> v;
	
	for(int i = 0; i < edge; i++){
		cin>>x>>y;
			matrix[x].push_back(y);
			matrix[y].push_back(x);
		}
	
	queue<int> q;
	
	for(int i = 1; i <= node; i++){
		if(visited[i])continue;
		cluster++;
		q.push(i);	v.push_back(i);
		
		while(!q.empty()){
			int x = q.front();
			q.pop();
			if(visited[x]) continue;
			visited[x] = true;
			for(int j = 0; j < matrix[x].size(); j++){
				if(!visited[matrix[x][j]]){
					q.push(matrix[x][j]);
					
				}
			}
		}
	}
 
	
		cout<< cluster-1 <<"\n";
		for(int i = 1; i < v.size(); i++){
			cout<< v[0]<<" "<<v[i] <<"\n";
		}
	
	return 0;
	}
