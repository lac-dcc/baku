#include <bits/stdc++.h>
 
using namespace std;
 
long long n,m;
vector<bool> vis;
vector<long long> pat;
long long x,y,w;
long long j;
 
struct node
{
    long long idx;
    long long cost;
    node(){};
    node(long long _idx, long long _cost)
    {
        idx=_idx;
        cost=_cost;
    }
    bool operator<(const node &tmp)const
    {
        return cost>tmp.cost;
    }
};
 
int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    cin>>n>>m;
    vector<pair<long long,long long>>v[n+1];
    for(j=0;j<m;j++)
    {
        cin>>x>>y>>w;
        v[x].push_back({y,w});
    }
    priority_queue<node>Q;
    Q.push(node(1,0));
    for(int i=0;i<=n;i++)
    {
        vis.push_back(false);
        pat.push_back(1e15);
    }
    pat[1]=0;
    while(!Q.empty())
    {
        node teme=Q.top();
        Q.pop();
        if(vis[teme.idx])continue;
        vis[teme.idx]=1;
        for(auto g:v[teme.idx])
        {
            if(!vis[g.first] && teme.cost+g.second<pat[g.first])
            {
                Q.push(node(g.first,teme.cost+g.second));
                pat[g.first]=teme.cost+g.second;
            }
        }
    }
    for(long long i=1;i<=n;i++)
    {
        cout<<pat[i]<< " ";
    }
    return 0;
}
