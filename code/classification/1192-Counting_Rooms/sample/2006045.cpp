#include<bits/stdc++.h>
using namespace std;
char maps[1005][1005];
int n,m,ans=0;
bool vis[1005][1005];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool check(int a,int b){
	return a>=0&&b>=0&&a<n&&b<m&&maps[a][b]=='.';
}
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int f=x+dx[i],s=y+dy[i];
		if(check(f,s)){
			maps[f][s]='#';
			dfs(f,s);
		}
	}
}
int main(){
	std::ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>maps[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j]&&maps[i][j]=='.'){
				ans++;
				dfs(i,j);
			}
		}
	}
	cout<<ans<<'\n';
}
