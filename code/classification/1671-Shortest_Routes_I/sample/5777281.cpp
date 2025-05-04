#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> dijkstra(vector<vector<ll>> &vec,ll vertices, ll edges) 
{
    unordered_map<ll,vector<pair<ll,ll>>> adj;
    ll i;
    for(i=0;i<edges;i++)
    {
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
 
    }
    vector<ll> dis(vertices+1);
    for(i=0;i<=vertices;i++)
    {
    dis[i]=1e15;
    }
    set<pair<ll,ll>> st;
    dis[1]=0;
    st.insert(make_pair(0,1));
    while(!st.empty())
    {
        auto top=*(st.begin());
        ll nodeDistance=top.first;
        ll topNode=top.second;
        st.erase(st.begin());
        for(auto x:adj[topNode])
        {
          if((nodeDistance+x.second)<dis[x.first])
          {
            auto record=st.find({dis[x.first],x.first});
            if(record!=st.end())
            {
                st.erase(record);
            }
            dis[x.first]=nodeDistance+x.second;
            st.insert({dis[x.first],x.first});
          }  
        }
    }
    return dis;
}
int main()
{
    ll m,n,i;
    cin>>n>>m;
    vector<vector<ll>> vec;
    for(i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        vec.push_back({u,v,w});
    }
    vector<ll> ans=dijkstra(vec,n,m);
    for(i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}