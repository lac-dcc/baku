#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define int long long
const int mod=0e9+7;
int nodes,edges;
vector<bool> vis;
vector<vector<int>> ad;
void dfs(int n)
{   
    vis[n]=true;
    // for(auto i:vis)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<"\n";
    for(auto i:ad[n])
    {
        if(!vis[i])
        {   
            //cout<<"vissited"<<i+1<<" ";
            dfs(i);
        }
    }
    // for(auto i:vis)
    // {
    //     cout<<i<<' ';
    // }
    cout<<"\n";
}
 
int32_t main() 
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>nodes>>edges;
    vis.resize(nodes+1,false);
    ad.resize(nodes+1);
    int count=0;
    
    for(int i=0;i<edges;i++)
    {
        int x,y;
        cin>>x>>y;
        ad[x].push_back(y);
        ad[y].push_back(x);
    }
    // for(auto i:ad)
    // {
    //     for(auto j:i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    vector<int> ans;
    for(int i=1;i<=nodes;i++)
    {
        if(!vis[i])
        {   
            //cout<<"start"<<i+1<<" ";
            dfs(i);
            ans.push_back(i);
            //cout<<i+1<<" \n";
            // for(auto i:vis)
            // {
            //     cout<<i<<' ';
            // }
            // cout<<"\n";
            count++;
        }
    }
    cout<<count-1<<"\n";
    int len=ans.size();
    for(int i=0;i<len-1;i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<"\n";
    }
    return 0;
}
