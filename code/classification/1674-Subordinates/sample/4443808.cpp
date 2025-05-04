#include<bits/stdc++.h>
using namespace std;
 
const int SZ = 200005;
int n, m, x;
vector<int> adj[SZ];
int S[SZ];
 
void dfs(int u,int l, int p)
{
	S[u] = 1;
	
	for (int v: adj[u]) {
		if (v != p) {
			dfs(v, l+1, u);
			S[u] += S[v];
		}
	}	
}
 
int main() {
    cin >> n;
    
    for(int i = 2; i <=n ; i++) {
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(1, 0, 0);
    for(int i = 1; i <= n ; i++) {
        cout << S[i] - 1 << " ";
    }
}
 
 
 
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
 
 
 
// void dfs(ll node,vector<ll> &ans,vector<vector<ll>> adj,int par){
//     ans[node]=1;
//     for(auto child:adj[node]){
//         if(child != par){
//             dfs(child,ans,adj,node);
//             ans[node]+=ans[child];
//         }
//     } 
// }
 
// int main(){
//     ll n;
//     cin>>n;
//     vector<vector<ll>> v(n+1);
//     for(int i=2;i<n+1;i++){
//         ll x;
//         cin>>x;
//         v[x].push_back(i);
//         v[i].push_back(x);
//     }
 
//     vector<ll> ans(n+1,-1);
//     dfs(1,ans,v,0);
//     for(int i=1;i<=n;i++){
//         cout<<ans[i]-1<<" ";
//     }cout<<endl;
//     return 0;
// }
