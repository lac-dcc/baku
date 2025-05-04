#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define vpi vector<pair<int, int>>
 
#define loop(i, x, n) for(int i = x; i < n; i++)
#define print_array(a, n) loop(i, 0, n) { cout << a[i] << " "; } cout << '\n';
#define input_array(arr, n) loop(i, 0, n) { cin >> arr[i]; }
#define loopIt(itr, v) for(auto itr = v.begin(); itr != v.end(); itr++)
#define loopRIt(itr, v) for(auto itr = v.rbegin(); itr != v.rend(); itr++)
#define loopAuto(it, v) for(auto it: v)
#define init(arr, value) memset(arr, value, sizeof arr)
#define print(value) cout << value << " ";
#define println(value) cout << value << '\n';
 
#define all(x) x.begin(), x.end()
#define iota(v, x) iota(v.begin(), v.end(), x)
#define count_ones(x) __builtin_popcount(x)
 
#define F first
#define S second
#define ln "\n"
#define Y "Yes"
#define N "No" 
#define MOD 1000000007
 
void solve()
{
    int n;
 
    cin >> n;
 
    vvi adj(n);
 
    loop (i, 1, n) {
        int u;
 
        cin >> u;
 
        u--;
 
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
 
    vi subtreeSize (n, 0);
 
    // subtreeSize[0] = n - 1;
 
    // function<void(int, int)> dfs = [&] (int node, int parent) {
    //     for (auto child: adj[node]) {
    //         if (child != parent) {
    //            dfs(child, node);
    //            subtreeSize[node] += subtreeSize[child];
    //         }
    //     }
 
 
    //     subtreeSize[node]++; // for itself
    //     // return subtreeSize[node];
 
    //       cout << node << " " << subtreeSize[node] << endl;
    // };
 
    function <int(int, int)> dfs = [&] (int node, int parent) {
        for (auto child: adj[node]) {
            if (child == parent) continue;
   
            subtreeSize[node] += dfs(child, node);
        }
 
        subtreeSize[node]++;
        
        return subtreeSize[node];
    };
 
    dfs(0, -1);
    
    for (auto ele: subtreeSize) {
        cout << (ele - 1) << " ";
    }
 
    cout << ln;
}
 
signed main()
{
    ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
 
    int t = 1;
 
    // cin >> t;
 
    while (t--) solve();
  
    return 0;
}
