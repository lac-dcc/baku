#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF (1LL<<62)
#define N 2000006
 
vector<int>adj[N];
int color[N];
int flag = 1;
 
void dfs( int u, int c )
{
    if( color[u] )
    {
        if( color[u] != c )
        {
            flag = 0;
            return;
        }
        return;
    }
 
    color[u] = c;
    for( int v: adj[u] )
    {
        dfs(v, ((c==1) ? 2 : 1));
        //dfs( v, 3 - c );
    }
}
 
int main()
{
    int n, m;
    cin>> n>> m;
 
    for( int i = 0; i < m; i++ )
    {
        int u,v;
        cin>> u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for( int i = 1; i <= n; i++ )
    {
        if( !color[i] )
        {
            dfs( i, 1 );
        }
    }
 
    if( flag )
    {
        for( int i = 1; i<= n; i++ )
        {
            cout<< color[i] << " ";
        }
        cout<< "\n";
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
}
 
 
 
