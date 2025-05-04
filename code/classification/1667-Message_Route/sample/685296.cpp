#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 1e5;
int n, m;
vector<int> adj[mxN], ans;
int p[mxN];
 
int main()
{
	
	ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
 
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b,--a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    memset(p, 0xc0, sizeof(p));
 
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
 
        for (auto nd : adj[x])
        {
            if (p[nd] < 0)
            {
                p[nd] = x;
                q.push(nd);
            }
        }
    }
 
    if (p[n - 1] < 0)
        cout << "IMPOSSIBLE";
    else
    {
        int u = n - 1;
        while (u)
        {
            ans.push_back(u);
            u = p[u];
        }
 
        ans.push_back(0);
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<"\n";
        for (auto it : ans)
            cout << it + 1 << " ";
    }
}
