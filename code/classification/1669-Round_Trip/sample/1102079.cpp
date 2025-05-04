#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define V vector
int n,m;
V<V<int>>road;
V<int>vis,ans;
int cntt=0;
int cycle=-1,flg=0;
// void dfs(int x,vector<int>res){
// 	cntt++;
// 	if(cntt>1000){
// 		cout<<"exit";
// 		exit(0);
// 	}
// 	cout<<vis[x]<<" "<<x<<"\n";
// 	if(vis[x]==0){
// 		int cnt=0;
// 		for(int i=0;i<res.size();i++){
// 			if(res[i]==x){
// 				cnt++;
// 			}
// 			if(cnt)ans.push_back(res[i]);
// 		}
// 	}
// 	vis[x]=0;
// 	for(int i:road[x]){
// 		if(ans.size()>0){
// 			return ;
// 		}
// 		if(vis[i]==1)continue;
// 		res.push_back(i);
// 		dfs(i,res);
// 	}
// 	vis[x]=1;
// }
bool dfs(int node,int p){
	vis[node]=1;
	for(int i:road[node]){
		if(!vis[i]){
			bool x=dfs(i,node);
			// cout<<x<<" ";
			if(x){
				ans.push_back(i);
				if(i==cycle){
					cout<<ans.size()<<"\n";
					for(int j:ans){
						cout<<j<<" ";
					}
					flg=1;
				}
				return 1;
			}
		}
		else if(i!=p){
			// cout<<i<<" ";
			cycle=i;
			ans.push_back(i);
			return 1;
		}
	}
	return 0;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	road.resize(n+1);
	vis.resize(n+1,0);
	for(int i=0;i<m;i++){
		int x;
		int y;
		cin>>x>>y;
		road[x].push_back(y);
		road[y].push_back(x);
	}
	V<int>res;
	for(int i=n;i>0;i--){
		if(cycle==-1&&!vis[i]){
			dfs(i,-1);
		}
	}
	if(cycle==-1){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	if(!flg){
		ans.push_back(ans[0]);
		cout<<ans.size()<<"\n";
		for(int i:ans)cout<<i<<" ";
	}
}
