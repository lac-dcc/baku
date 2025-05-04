#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int maxn=1005;
 
const int xp[]={1, 0, -1, 0};
const int yp[]={0, 1, 0, -1};
 
bool a[maxn][maxn];
bool bio[maxn][maxn];
int n, m;
 
void dfs(int x, int y){
	bio[x][y]=1;
	int xs, ys;
	for(int i=0; i<4; i++){
		xs=x+xp[i];
		ys=y+yp[i];
		if(xs>-1 && ys>-1 && xs<n && ys<m && a[xs][ys] && !bio[xs][ys]){
			dfs(xs, ys);
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	string s;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<m; j++){
			if(s[j]=='.'){
				a[i][j]=1;
			}
		}
	}
	int br=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j] && !bio[i][j]){
				dfs(i, j);
				br++;
			}
		}
	}
	cout << br << '\n';
	return 0;
}
