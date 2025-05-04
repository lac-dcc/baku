#include <bits/stdc++.h>
using namespace std;
 
int n, m;
vector<int> edges[100005];
int vis[100005];
int p[100005];
 
void dfs(int tr, int pr)
{
    vis[tr] = 1;
 
    for (int x : edges[tr])
    {
        if ( x == pr)
            continue;
 
        if (!vis[x])
        {
            p[x] = tr;
            dfs(x,tr);
        }
 
        if (vis[x] == 1)
        {
            vector<int> ans;
            ans.push_back(x);
 
            int j = tr;
            while  (j != x)
            {
                ans.push_back(j);
                j=p[j];
            }
 
            ans.push_back(x);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << endl;
            for(int i=0; i<ans.size(); ++i)
                cout << ans[i] << " ";
 
            exit(0);
        }
    }
 
    vis[tr] = 2;
}
 
 
 
int main()
{
   cin >> n >> m;
   for (int i=0; i<m; ++i)
   {
       int a,b;
       cin >> a >> b;
 
       edges[a].push_back(b);
       edges[b].push_back(a);
   }
 
   for (int i =1; i<=n; ++i)
   {
       if (! vis[i])
        dfs(i,-1);
   }
 
   cout << "IMPOSSIBLE" ;
}
