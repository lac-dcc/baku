#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array
const int N=4e4+5;
const int M=1e9+7;
 
 
int32_t main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
int n;
cin>>n;
 
vector<vector<int>>g(n+1);
if(n==1){
    cout<<0;
    return 0;
}
for(int i=0;i<n-1;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
}
 
vector<int>d(n+1);
int rnod1,rnod2;
int mx=0;
function<void(int,int)> dfs=[&](int u,int p){
    
    for(auto v:g[u]){
        if(v==p)
        continue;
        d[v]=d[u]+1;
        if(d[v]>mx){
            rnod1=v;
            mx=d[v];
        }
        dfs(v,u);
    }
};
 
d[1]=0;
dfs(1,0);
 
rnod2=rnod1;
d[rnod1]=0;
mx=0;
dfs(rnod1,0);
 
vector<int>ans(n+1,0);
d[rnod1]=0;
dfs(rnod1,0);
for(int i=1;i<=n;i++)
ans[i]=max(ans[i],d[i]);
d[rnod2]=0;
dfs(rnod2,0);
for(int i=1;i<=n;i++)
ans[i]=max(ans[i],d[i]);
for(int i=1;i<=n;i++)
cout<<ans[i]<<" ";
}
 
 
 
 
 
 
 
 
