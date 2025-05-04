#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define fuk ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
char a[1000][1000];
bool visited[1000][1000];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
bool isSafe(int x,int y,int row,int col){
	if(x<0 || x>row-1 || y<0 || y>col-1)return false;
	return true;
}
void dfs(int x,int y,int row,int col){
	visited[x][y]=true;
	for(int i=0;i<4;++i){
		if(isSafe(x+dx[i],y+dy[i],row,col) && a[x+dx[i]][y+dy[i]]=='.' && !visited[x+dx[i]][y+dy[i]]){
			dfs(x+dx[i],y+dy[i],row,col);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>a[i][j];
		}
	}
	lli ans=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(a[i][j]=='.' && !visited[i][j]){
				dfs(i,j,n,m);
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
