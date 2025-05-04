#include <bits/stdc++.h>
using namespace std;                       
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define sc second
#define all(v) v.begin(),v.end()
#define piii pair<int, pair<int, int>>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
unordered_map <int, vector <int>> graph;
vector <int> cot;
const ll M = 1e9 + 7;
int dfs(int src){
    int cnt = 1;
    for(auto j : graph[src]){
        cnt += dfs(j);
    }
    return cot[src] = cnt;
}
void solve(){
    int n;
    cin>>n;
    int x;
    for(int i=1;i<=n-1;i++){
        cin>>x;
        graph[x].push_back(i+1);
    }
    cot.resize(n+1);   
    dfs(1);
    for(int i=1;i<=n;i++){
        cout<<cot[i]-1<<" ";
    }
    cout<<endl;
    
    
}
 
int main(){
    // clock_t time_req;
    // time_req = clock();
    fastio;
    int te;
    //cin>>te;
    te = 1;
    while(te--){
        solve();
    }
    // time_req = clock()-time_req;
    // cout<<"Time taken: "<<(float)time_req/CLOCKS_PER_SEC<<"s"<<endl;
    return 0;
}
