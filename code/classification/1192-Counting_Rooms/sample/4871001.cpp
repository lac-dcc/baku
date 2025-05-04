#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir={{0,1},{-1,0},{1,0},{0,-1}};
void _solve(vector<string>& v,int x,int y,vector<vector<int>>& vis){
	if(x<0 || y<0 || x>=v.size() || y>=v[0].size() || v[x][y]=='#' || vis[x][y]){
		return;
	}
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		_solve(v,x+dir[i][0],y+dir[i][1],vis);
	}
	return;
}
 
int main(){
int x,y;
cin>>x>>y;
vector<string> v(x);
for(int i=0;i<x;i++){
	cin>>v[i];
}
vector<vector<int>> vis(x,vector<int>(y,0));
 
int ans=0;
for(int i=0;i<x;i++){
	for(int j=0;j<y;j++){
		if(vis[i][j]==0 && v[i][j]=='.'){
			_solve(v,i,j,vis);
			ans++;
		}
	}
}
cout<<ans<<"\n";
return 0;
}
