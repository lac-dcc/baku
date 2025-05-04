#include<bits/stdc++.h>
using namespace std;
 
void myfunc(vector<vector<int>> &grph, int node, vector<bool> &visit)
{
    for(int child : grph[node])
    {
        if (visit[child] == false)
        {
            visit[child] = true;
            myfunc(grph, child, visit);
        }
    }
}
 
 
int main()
{
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> grph(n + 1);
    vector<bool> visit(n + 1, false);
 
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
 
        grph[x].push_back(y);
        grph[y].push_back(x);
    }
 
    int prev = -1;
    
    vector<pair<int, int >> ans;
 
    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == false)
        {
            myfunc(grph, i, visit);
 
            if(prev != -1)
            {
                // cout << prev << " " << i <<"\n";
                ans.push_back({prev, i});
            }
            prev = i;
        }            
    }
    
    cout << ans.size() << "\n";
    
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].first <<" "<<ans[i].second << "\n";
 
    return 0;
}
