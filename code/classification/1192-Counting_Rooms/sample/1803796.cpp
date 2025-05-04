#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
 
using namespace std;
 
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
 
signed main(){
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		char c;cin >> c;
    		if(c=='.') grid[i][j] = 1;
    		else if(c=='#') grid[i][j] = 0;
		}
	}
	
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j]) continue;
			else if(grid[i][j]==0) continue;
			
			vis[i][j] = true;
			ans++;
			stack<pair<int,int>> s;
			s.push(mp(i,j));
			while(!s.empty()){
				int x = s.top().fi;
				int y = s.top().se;
				s.pop();
				for(int i=0;i<4;i++){
					int xx = x+dx[i];
					int yy = y+dy[i];
					if(xx<0 or yy<0 or xx>=n or yy>=m or grid[xx][yy]!=1) continue;
					if(vis[xx][yy]) continue;
					else{
						vis[xx][yy] = true;
						s.push(mp(xx,yy));
					}
				}
			}
		}
	}
	
	cout << ans << endl;
return 0;
}
 
