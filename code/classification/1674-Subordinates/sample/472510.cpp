#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define db double
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define endl "\n"
#define mp make_pair
#define f first
#define s second
ll power(ll x, ll y){ ll ans = 1;x %= MOD;while(y){if(y&1)ans = (x * ans) % MOD;x = (x * x) % MOD;y >>= 1;}return ans;}
ll modInverse(ll a, ll m){ll m0 = m;ll y = 0, x = 1;if (m == 1) return 0;while (a > 1){ ll q = a / m;ll t = m;m = a % m,a = t;t = y;y = x - q * y;x = t;}if(x < 0) x += m0;return x;}
using namespace std;
 
void dfs(vector<vector<int> >& v, vector<int>& output, int si, vector<bool>& visited) {
    if(visited[si])
        return;
    //cout<< si << endl;
    visited[si] = true;
     for(int i : v[si]) {
        dfs(v, output, i, visited);
        output[si] += (output[i] + 1);
    }
}
 
void solve() {
    ll n;
    cin >> n;
    vector<vector<int> > v(n + 1, vector<int>());
    for(int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        v[x].pb(i);
    }
    vector<int> output(n + 1);
    vector<bool> visited(n + 1, 0);
    dfs(v, output, 1, visited);
 
    for(int i = 1; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;
}
 
int main() {
    fastio;
    solve();
}
