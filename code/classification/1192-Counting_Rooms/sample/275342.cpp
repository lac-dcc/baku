#include <iostream>
#include <stdio.h>
//#define DEBUG
 
using namespace std;
 
 
void dfs(char ** arr, int i, int j);
 
int n, m;
 
int main() {
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//FILE * log = fopen("logs.txt", "w");
 
	
	cin >> n >> m;
 
	char **arr = (char**)malloc(n * sizeof(char *));
	for (int i = 0; i < n; i++)
		arr[i] = (char *)malloc(m * sizeof(char));
 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
 
	int count = 0;
 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != '#') {
				count++;
				dfs(arr, i, j);
			}
		}
	
	cout << count;
 
	return 0;
}
 
void dfs(char ** arr, int i, int j) {
 
	if (arr[i][j] == '#')
		return;
	arr[i][j] = '#';
 
	if (i > 0)
		dfs(arr, i - 1, j);
	
	if (j > 0)
		dfs(arr, i, j - 1);
 
	if (j < m - 1)
		dfs(arr, i, j + 1);
 
	if (i < n - 1)
		dfs(arr, i + 1, j);
 
}
