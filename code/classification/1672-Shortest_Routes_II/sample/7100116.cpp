#include <bits/stdc++.h>
using namespace std;
    
int main()
{
    int n, m, q; cin>>n>>m>>q;
    vector<vector<long long>> dist(n, vector<long long>(n, INT64_MAX));
    for(int i=0; i<n; i++) dist[i][i]=0;
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if(a==b) continue;
        a--; b--;
        dist[a][b]=min(dist[a][b], 1LL*c);
        dist[b][a]=dist[a][b];
    }
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][k] != INT64_MAX && dist[k][j] != INT64_MAX)
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--)
    {
        int x, y; cin>>x>>y;
        x--; y--;
        cout<<(dist[x][y] == INT64_MAX ? -1 : dist[x][y])<<endl;
    }
    return 0;
}
