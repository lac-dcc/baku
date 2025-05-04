#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e2 + 1, mxx = 1e6 + 1,M=1e9+7;
#define ll long long
#define ar array
// int di[4] = {1, 0, -1, 0};
// int dj[4] = {0, 1, 0, -1};
// char dc[4] = {'D', 'R', 'U', 'L'};
int n, m, a, b, si, sj;
// int p[mxn];
// vector<int>adj[mxn];
// bool vis[mxn];
// int flag = 0;
// string s[mxn], path[mxn];
int dp[mxx],c[mxn];
// void dfs(int i, int pi=-1){
//     p[i]=pi;
//     vis[i]=1;
//     for(int k:adj[i]){
//         if(k==pi) continue;
//         if(vis[k])
//         {
//             vector<int> ans;
//             //ans.push_back(i);
//             while(k^i){
//                 ans.push_back(i);
//                 i = p[i];
//             }
//             reverse(ans.begin(), ans.end());
//             ans.push_back(k);
//             ans.push_back(ans[0]);
//             cout<<ans.size()<<endl;
//             for(int k:ans){
//                 cout<<k+1<<" ";
//             }
//             exit(0);
//         }
//         dfs(k,i);
//     }
// }
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    dp[0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            // cout<<dp[i];
            if(c[j]<=i){
                dp[i] = (dp[i] + dp[i - c[j]])%M;
                // cout<<dp[i]<<" "<<i<<endl;
            }
        }
    }
    cout<<dp[m];
    return 0;
}