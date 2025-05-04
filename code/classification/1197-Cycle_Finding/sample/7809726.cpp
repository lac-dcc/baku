#include <bits/stdc++.h>
using namespace std;
 
vector<vector<long long>> edges(5005, vector<long long>(3));
vector<long long> dp(2505, 1e18), p(2505);
 
int main(){
    int n, m; cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    int ptr=-1;
    dp[1]=0;
    for(int iteration=0; iteration<n && ptr; iteration++){
        ptr=0;
        for(int i=0; i<m; i++){
            long long u=edges[i][0], v=edges[i][1], cost=edges[i][2];
            if(dp[v]>cost+dp[u]){
                dp[v]=cost+dp[u];
                p[v]=u;
                ptr=v;
            }
        }
    }
    
    if(!ptr){
        cout<<"NO";
        return 0;
    }
    for(int i=0; i<n; i++) ptr=p[ptr];
    
    vector<int> cycle;
    
    cycle.push_back(ptr);
    for(int v=p[ptr]; v!=ptr; v=p[v]){
        //cout<<v<<' '<<ptr<<'\n';
        cycle.push_back(v);
    }
    cycle.push_back(ptr);
    reverse(cycle.begin(), cycle.end());
    
    cout<<"YES\n";
    for(int i: cycle){
        cout<<i<<' ';
    }
    return 0;
}
