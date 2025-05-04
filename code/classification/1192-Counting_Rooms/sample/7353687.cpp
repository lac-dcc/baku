#include <bits/stdc++.h>
using namespace std;
const int MAX = 1007;
 
int n, m, v[MAX][MAX], count;
char grid[MAX][MAX];
int pos_x[4] = {1, 0, -1, 0};
int pos_y[4] = {0, -1, 0, 1};
 
void dfs(int x, int y) {
	v[x][y]=1;
	for (int i=0; i<4; i++) {
		int a = x+pos_x[i], b = y+pos_y[i];
		if (v[a][b]!=1) {
			dfs(a, b);
		}
	}
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    for (int i=1; i<n+1; i++){
    	for (int j=1; j<m+1; j++) {
    	    cin >> grid[i][j];	
		}
	}
	
	for (int i=0; i<n+2; i++) {
		grid[i][0] = '#';
		grid[i][m+1] = '#';
	}
	
	for (int i=0; i<m+2; i++) {
		grid[0][i] = '#';
		grid[n+1][i] = '#';
	}
	
//	for (int i=0; i<n+2; i++) {
//		for (int j=0; j<m+2; j++) {
//			cout << grid[i][j];
//		}
//		cout << "\n";
//	}
//	
	
	for (int i=0; i<n+2; i++) {
		for (int j=0; j<m+2; j++) {
			if (grid[i][j]=='#') {
				v[i][j]=1;
			} else {
				v[i][j]=0;
			}	
		}
	}
	
//	for (int i=0; i<n+2; i++) {
//		for (int j=0; j<m+2; j++) {
//			cout << v[i][j];
//		}
//		cout << "\n";
//	}
	
	
	int count=0;
	for (int i=1; i<n+1; i++) {
		for (int j=1; j<m+1; j++) {
			if (v[i][j]==0) {
				count+=1;
				dfs(i, j);
			}
			
		}
	}
	cout << count;
    return 0;
}
 


