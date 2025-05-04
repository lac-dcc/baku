#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long 
#define ri int
const int MAXN=2e5+7;
int siz[MAXN],n;
vector<int> g[MAXN];
void dfs(int u){
    siz[u]=1;
    for(auto v:g[u]) dfs(v),siz[u]+=siz[v];
}
int main(){
    scanf("%d",&n);
    for(ri i=2,x;i<=n;++i) scanf("%d",&x),g[x].push_back(i);
    dfs(1);
    for(ri i=1;i<=n;++i) printf("%d ",siz[i]-1);
    
}
