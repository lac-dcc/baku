#include <bits/stdc++.h>
 
using namespace std;
 
const int sz = 1e3;
int n, m;
vector<string> matrix(sz);
bool e(int i, int j){
	return (i >= 0 && i < n && j >= 0 && j < m && matrix[i][j] == '.');
}
 
void dfs(int i, int j){
	matrix[i][j] = '#';
	if(e(i+1,j)) dfs(i+1,j);
	if(e(i-1,j)) dfs(i-1, j);
	if(e(i,j-1)) dfs(i,j-1);
	if(e(i,j+1)) dfs(i, j+1);
}
 
int main(){
	//int n, m;
	cin >> n >> m;
 
	int cnt = 0;
	//vector<vector<int>> visited(n, vector<int>(m, 0));
	//vector<vector<char>> matrix(n, vector<char>(m,'+'));
 
	for(int i = 0; i < n; i++){
		cin >> matrix[i];
	}
 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(e(i,j)){
				dfs(i,j);
				cnt += 1;
			}
		}
	}
 
	cout << cnt;
	return 0;
}
 
 
 
 
 
