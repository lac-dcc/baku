#include <bits/stdc++.h>
#define ll long long
#define int long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;
bool flag = true;
vector<vector<ll>>adj;
vector<ll>color;
void bfs(ll st){
    int cur_col;
    queue<ll>q;
    q.push(st);
    while(!q.empty()){
        int p = q.front();
        cur_col = color[p];
        q.pop();
        for(auto &it : adj[p]){
            if(color[it] == -1){
                color[it] = (cur_col + 1) % 2;
                q.push(it);
            }
            else if(color[it] == cur_col)flag = false;
        }
    }
}
void solve()
{
    ll n,m;cin >> n >> m;
    adj = vector<vector<ll>>(n + 1);
    color = vector<ll>(n + 1,-1);
    for(int i = 0,x,y;i < m;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1;i <= n;i++){
        if(color[i] == -1){
            color[i] = 0;
            bfs(i);
        }
    }
    if(flag){
        for(int i = 1;i <= n;i++)cout << color[i] + 1 << ' ';
    }
    else cout << "IMPOSSIBLE";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ll t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
        cout << "\n";
    }
}
