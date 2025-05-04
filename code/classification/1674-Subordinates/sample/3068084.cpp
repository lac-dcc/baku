#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 200010
using namespace std;
int siz[N];vector<int>g[N];
void dfs(int u)
{
    for(int v:g[u]) dfs(v),siz[u]+=siz[v]+1;
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=2,u;i<=n;i++) scanf("%d",&u),g[u].push_back(i);
    dfs(1);
    for(int i=1;i<=n;i++) printf("%d ",siz[i]);
    return 0;
}
