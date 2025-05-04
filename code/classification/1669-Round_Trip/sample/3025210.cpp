#include<bits/stdc++.h>
using namespace std;
int a,b;
vector<int>v[100001];
bool vis[100001];
int par[100001];
bool have=0;
vector<int>ans;
void dfs(int now,int pre){
	if(have)return;
	for(auto i:v[now]){
		if(vis[i]==0){
			vis[i]=1;
			par[i]=now;
			dfs(i,now); 
		}else if(vis[i]==1&&pre!=i&&!have){
			int parent=i;
			int j=now;
			ans.push_back(i);
			have=1;
			while(i!=j){
				ans.push_back(j);
				j=par[j];
			}
			ans.push_back(i);
			break;
		}
	}
	if(have)return;
}
 
 
int main(){
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		vis[i]=0;
		par[i]=i;
	}
	for(int i=0;i<b;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=a;i++){
		if(vis[i]==0){
			vis[i]=1;
			par[i]=i;
			dfs(i,-1);
		}
	}
	
	if(have==0){
		cout<<"IMPOSSIBLE";
	}else {
		cout<<ans.size()<<endl;
		for(auto i:ans)cout<<i<<" ";
	}
	
	
}
