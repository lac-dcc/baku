#include <bits/stdc++.h>
 
using namespace std;
 
const long long inf = 1e18;
const long long M = 1e9 + 7;
 
long long n, a, b, i, j, k;
vector<vector<long long>> G;
vector<long long> SZ, dep;
 
void dfs(int v, int p, int d){
    dep[v]  = d;
    for(auto to : G[v]){
        if(to == p){
            continue;
        }
        dfs(to, v, d + 1);
        SZ[v] += SZ[to];
    }
}
 
int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
 
    cin >> n;
    G.resize(n + 1);
    SZ.resize(n + 1, 1);
    dep.resize(n + 1);
    for(i = 0; i < n - 1; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
 
    dfs(1, 1, 0);
    long long mx = -1, mxi = -1;
    for(i = 1; i < dep.size(); i++){
        if(mx < dep[i]){
            mx = dep[i];
            mxi = i;
        }
    }
 
    for(i = 1; i < SZ.size(); i++){
        SZ[i] = 1;
        dep[i] = 0;
    }
 
    dfs(mxi, mxi, 0);
    vector<long long> dep1 = dep;
    mx = -1, mxi = -1;
 
    for(i = 1; i < dep.size(); i++){
        if(mx < dep[i]){
            mx = dep[i];
            mxi = i;
        }
    }
 
    dfs(mxi, mxi, 0);
    vector<long long> dep2 = dep;
    for(i = 1; i <= n; i++){
        cout << max(dep1[i], dep2[i]) << " ";
    }
 
    return 0;
}
