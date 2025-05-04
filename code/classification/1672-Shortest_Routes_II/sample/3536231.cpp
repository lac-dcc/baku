#define ll long long
#define ull unsigned ll
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define tllll tuple<ll, ll, ll, ll>
#define tlll tuple<ll, ll, ll>
#define tlii tuple<ll, int, int>
#define tiii tuple<int, int, int>
#define MOD 998244353
#define intINF numeric_limits<int>::max()/2
#define INF numeric_limits<ll>::max()/2
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> adjmatrix(n, vector<ll> (n, INF));
    for(int i = 0; i < m; i++)
    {
        int a, b;
        ll c;
        cin>>a>>b>>c;
        a--; b--;
        adjmatrix[a][b] = min(adjmatrix[a][b], c);
        adjmatrix[b][a] = adjmatrix[a][b];
    }
    for(int i = 0; i < n; i++)
    {
        adjmatrix[i][i] = 0;
    }
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                adjmatrix[j][k] = min(adjmatrix[j][k], adjmatrix[j][i]+adjmatrix[i][k]);
                adjmatrix[k][j] = adjmatrix[j][k];
            }
        }
    }
 
    for(int i = 0; i < q; i++)
    {
        int a, b;
        cin>>a>>b;
        a--; b--;
        if(adjmatrix[a][b] == INF)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<adjmatrix[a][b]<<"\n";
        }
    }
 
    return 0;
}
