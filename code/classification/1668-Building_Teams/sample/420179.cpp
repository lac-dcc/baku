#include <bits/stdc++.h>
using namespace std;
bool visited[100001];
bool possible=1;
int main(){
	//ifstream cin("test_input.txt");
	//ofstream cout("test_out.txt");
	//1->black 2->gray 3->white
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	vector <int> adjList[100001];
	int color[100001];
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			visited[i]=1;
			queue <int> q;
			q.push(i);
			color[i]=1;
			while(!q.empty()){
				int next=q.front();
				q.pop();
				int nextnext=1;
				if(color[next]==1){
					nextnext=3;
					//cout<<"next: "<<next<<endl;
				}
				if(color[next]==3){
					nextnext=1;
					//cout<<"next1: "<<next<<endl;
				}
				for(int j=0;j<adjList[next].size();j++){
					if(color[adjList[next][j]]==3&&nextnext==1){
						possible=0;
						//cout<<"check: "<<i<<endl;
					}
					else if(color[adjList[next][j]]==1&&nextnext==3){
						possible=0;
						//cout<<"check: "<<i<<endl;
					}else{
						color[adjList[next][j]]=nextnext;
						//cout<<"add "<<adjList[next][j]<<" "<<nextnext;
					}
					if(!visited[adjList[next][j]]){
						visited[adjList[next][j]]=1;
						q.push(adjList[next][j]);
					}
					
				}
			}
		}
	}
	if(!possible){
		cout<<"IMPOSSIBLE";
	}else{
		for(int i=1;i<=n;i++){
			if(color[i]==1){
				cout<<1<<" ";
			}
			else if(color[i]==3){
				cout<<2<<" ";
			}
		}
	}
	for(int i=1;i<=n;i++){
		//cout<<color[i]<<endl;
	}
	//cout<<endl;
	//cout<<color[3];
}
