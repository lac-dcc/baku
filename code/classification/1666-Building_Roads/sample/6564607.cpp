#include <bits/stdc++.h>
 
typedef long long ll;
using namespace std;
#define FASTIO ios::sync_with_stdio(false), cin.tie(0);
#define LL_MAX 9,223,372,036,854,775,807;
#define LL_MIN -9,223,372,036,854,775,807;
//ifstream cin("...txt"); ofstream cout("...txt");
//^at beginning if old usaco problem with file
//INT_MAX and INT_MIN give min and max numbers
//it is possible to do for(int i : set s)cout << i << " ";
//.end() points to random element after the last element
 
int n, m;
vector<bool> vis(100001, false);
vector<vector<int>> vec(100001);
 
void dfs(int k)
{
    vis[k] = true;
    for(int i = 0; i < vec[k].size(); i++){
        if(vis[vec[k][i]]){
            continue;
        }
        dfs(vec[k][i]);
    }
}
void solve(){
    int in1, in2; cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> in1 >> in2;
        vec[in1].emplace_back(in2);
        vec[in2].emplace_back(in1);
    }
    int cnt = 0;
    vector<int> comps;
    for(int i = 1; i <= n; i++){
        if(vis[i]){
            continue;
        }
        cnt++;
        dfs(i);
        comps.emplace_back(i);
    }
    cout << cnt-1 << "\n";
    for(int i : comps){
        if(i == 1)continue;
        cout << "1 " << i << "\n";
    }
}
 
int main(){
    FASTIO;
    //int t; cin >> t; while(t--)
    solve();
}
