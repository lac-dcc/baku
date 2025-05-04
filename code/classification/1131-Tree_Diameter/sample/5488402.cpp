#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
int n;
 
const int N = 2e5 + 5;
 
vector <int> g[N];
 
pair <int, int> bfs(int start)
{
    queue <pair <int, int>> q;
    q.push({start, 0});
    vector <bool> viz(N, false);
    pair <int, int> u;
    while(!q.empty())
    {
        u = q.front();
        viz[u.first] = true;
        q.pop();
        for(auto v:g[u.first])
        {
            if(!viz[v])
            q.push({v, u.second + 1});
        }
    }
    return u;
}
 
signed main()
{
    cin >> n;
    for(int i = 1; i <= n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    pair <int, int> tmp1 = bfs(1);
    pair <int, int> tmp2 = bfs(tmp1.first);
    cout << tmp2.second;
    return 0;
}
