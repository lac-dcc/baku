#include <bits/stdc++.h>
using namespace std;
 
const int nax = 2e6+4;
vector<int>adj[nax];
 
int dp[nax];
 
void dfs(int i) {
    int cnt=0;
    for(auto x: adj[i]) {
        dfs(x);
        cnt += 1 + dp[x];
    }
    dp[i]=cnt;
}
 
int main() {
    int n;
    cin >> n;
    int x;
    for(int i=2;i<=n;i++) {
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}
