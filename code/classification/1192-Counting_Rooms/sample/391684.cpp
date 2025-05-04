#include <bits/stdc++.h>
 
using namespace std;
int n, m;
const int N=1010;
char a[N][N];
int room[N][N];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int k=1;
queue<pair<int, int> > q;
 
void bfs (int x, int y, int k) {
	room[x][y]=k;
	q.push(make_pair(x, y));
	
	while (q.size()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
 
		for (int i = 0; i < 4; i++) {
			int X = x+dx[i];
			int Y = y+dy[i];
			if (room[X][Y]==0) {
				room[X][Y]=k;
				q.push(make_pair(X, Y));
			}
		}
	}
}
int main () {
	cin >> n >> m;
	memset(room, -1, sizeof(room));
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j]=='.') room[i][j]=0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (room[i][j]==0) {
				bfs(i, j, k);
				k++;
			}
		}
	}
	cout << k-1 << endl;
 
 
 
 
 
 
 
 
return 0;
}
 
