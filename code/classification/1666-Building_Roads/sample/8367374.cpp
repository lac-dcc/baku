#include<bits/stdc++.h>
using namespace std;
 
 
struct dsu
{
    int v[100005],sz[100005];
    int find(int x)
    {
        if(v[x]!=x)
        {
            v[x]=find(v[x]);
        }
        return v[x];
    }
    void unite(int x, int y)
    {
        if(find(x)!=find(y))
        {
            if(sz[x]<sz[y])swap(x,y);
            v[v[y]]=v[x];
            sz[x]+=sz[y];
        }
        return;
 
    }
 
 
}d;
 
 
 
 
 
set<int> ans;
 
int main()
{
 
 
 
    int n, m,a,b;
    cin>>n>>m;
    for(int i = 1; i<=n; ++i)
    {
        d.v[i]=i;
    }
 
 
    for(int i=0; i<m; ++i)
    {
        cin>>a>>b;
        d.unite(a,b);
    }
    for(int i = 1; i<=n; ++i)
    {
        ans.insert(d.find(i));
    }
    cout<<ans.size()-1<<'\n';
    for(auto i =++ans.begin(); i!=ans.end(); ++i)
    {
        cout<<*ans.begin()<<' '<<*i<<'\n';
    }
 
 
 
    return 0;
}
