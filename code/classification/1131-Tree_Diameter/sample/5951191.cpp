#include<bits/stdc++.h>
 
using namespace std;
 
vector<int> vc[200001];
int n,a,b,dp[100001],ans = -1;
 
int dfs(int u, int pa)
{
    priority_queue<int> pq;
    pq.push(0);
    pq.push(0);
    for(auto x:vc[u]){
        if(x==pa) continue;
        pq.push(dfs(x,u));
    }
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    ans = max(ans,a+b);
    return a+1;
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin>>n;
    for(int i = 1; i<n; ++i){
        cin>>a>>b;
        vc[a].push_back(b);
        vc[b].push_back(a);
    }
    dfs(1,-1);
    cout<<ans;
}
