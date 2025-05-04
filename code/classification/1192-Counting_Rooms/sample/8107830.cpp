#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);
using namespace std;
 
void sol()
{
    int n, m, cnt = 0; cin >> n >> m;
 
    int vis[1001][1001] ={};
    string s[n];
 
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
 
    int dir[4] = {-1, 0, 1, 0};
    int dic[4] = {0, 1, 0, -1};
 
    function<void(int, int)> dfs=[&](int row, int col) 
    {
        vis[row][col] = 1;
 
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + dir[i];
            int ncol = col + dic[i];
 
            if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0 
            && s[nrow][ncol]=='.' && !vis[nrow][ncol])
            {
                dfs(nrow, ncol);
            }
        }
    };
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && s[i][j]=='.')
            {
                dfs(i, j); cnt++;
            }
        }
    }
    cout << cnt;
}
 
signed main()
{
    fastio()
 
    int t;
    t=1;
    // cin>>t;
    while(t--) sol();
    return 0;
}
