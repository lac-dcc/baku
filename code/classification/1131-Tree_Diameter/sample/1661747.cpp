#include <bits/stdc++.h>
using namespace std;
 
vector<int>graph[200005];
vector<bool>visited(200005 , false);
int value;
int level1 = 0;
void dfs(int a , int level)
{
    visited[a] = true;
    for(auto x:graph[a])
    {
        if(!visited[x])
        {
            dfs(x , level+1);
        }
    }
    if(level>level1)
    {
        value = a;
        level1 = level;
    }
}
 
 
 
 
 
void solve()
{
    int n;
    cin>>n;
    for(int i=1 ; i<n ; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0);
    //cout<<value<<endl;
    for(int i=1 ; i<=n ; i++)
    {
        visited[i] = false;
    }
    level1 = 0;
    dfs(value,0);
    cout<<level1<<endl;
    return;
}
 
 
 
int main()
{
 
 
    int tests=1;
    //cin>>tests;
 
    while(tests--)
    {
        solve();
    }
}
