#include <bits/stdc++.h>
#define ll long long 
#define w(t) int t;cin>>t;while(t--)
#define MOD 1000000007
using namespace std;
int R,C;
char a[1005][1005];
bool vis[1005][1005]={0};
 
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool isValid(int i,int j){
	if(i<1||j<1||i>R||j>C)
	return false;
	if(vis[i][j]==1 || a[i][j]=='#')
	return false;
	
	return true;
}
void dfs(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		if(isValid(x+dx[i],y+dy[i]))
		dfs(x+dx[i],y+dy[i]);
	}
}
 
int main(){
	cin>>R>>C;
for(int i=1;i<=R;i++){
	for(int j=1;j<=C;j++){
		cin>>a[i][j];
	}
  }
  int cnt=0;
  for(int i=1;i<=R;i++){
	for(int j=1;j<=C;j++){
	if(a[i][j]=='.' && vis[i][j]==0){
		cnt++;
		dfs(i,j);
	}
	}
  }
  cout<<cnt<<endl;
 
 
 
return 0;
}
