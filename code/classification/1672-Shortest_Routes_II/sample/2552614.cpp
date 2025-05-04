#include <bits/stdc++.h>
using namespace std;
 
const int64_t lmax = 1e18;
const int mxn = 500 + 10;
vector <vector <int64_t>> adj(mxn, vector<int64_t> (mxn, lmax));
 
void solve()
{
    int n,m, q;
    cin >> n >> m >> q;
    for(int i =0; i < m;i++){
        int a,b;
        int64_t c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }
    for(int i =0;i<n;i++) adj[i][i] = 0;
    for(int k =0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        cout << (adj[a][b] >= lmax ? -1 : adj[a][b]) << "\n";
    }
}
 
int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    for(int case_num = 1; case_num <= tt; case_num++){
        //cout << "Case #" << case_num << ": ";
        solve();
        cout << "\n";
    }
 
    return 0;
}
 
