#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
vector<int>vec[200005];
int dist[200005],dist2[200005];
void dfs(int node,int parent)
{
    dist[node]=dist[parent]+1;
    for(auto i:vec[node]){
        if(i!=parent){
            dfs(i,node);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1,0);
    int maxx=0,maxnode=1;
    for(int i=1;i<=n;i++){
        if(dist[i]>maxx){
            maxnode=i;
            maxx=dist[i];
        }
        dist[i]=0;
    }
    dfs(maxnode,0);
    maxx=0,maxnode=maxnode;
    for(int i=1;i<=n;i++){
        dist2[i]=dist[i];
        if(dist[i]>maxx){
            maxnode=i;
            maxx=dist[i];
        }
        dist[i]=0;
    }
    dfs(maxnode,0);
    for(int i=1;i<=n;i++){
        cout<<max(dist[i],dist2[i])-1<<" ";
    }
    cout<<endl;
    return 0;
}
