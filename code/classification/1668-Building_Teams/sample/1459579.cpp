#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <stack>
#include <queue>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, 
            null_type, 
            less<int>, 
            rb_tree_tag, 
            tree_order_statistics_node_update> ordered_set;
typedef tree<int, 
            null_type, 
            less_equal<int>, 
            rb_tree_tag, 
            tree_order_statistics_node_update> ordered_multiset; // less_equal changes lower_bound to upper_bound
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
 
#define PB push_back
#define POP pop_back
#define loop(i, a, b) for (int i = a; i <= b; i++)
 
bool bipartiteness_check(int i, int n, vi adj[], vector<bool> &visited, vector<bool> &color) {
    queue<int> q;
    
    q.push(i);
    visited[i] = color[i] = true;
    
    while (q.size() > 0) {
        int curr = q.front();
        q.pop();
        
        for (auto neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                color[neighbor] = !(color[curr]);
            }
            else if (color[neighbor] == color[curr]) {
                return false;
            }
        }
    }
    return true;
}
 
void building_teams() {
    int n, m;
    cin >> n >> m;
    
    vi adj[n];
    int a, b;
    loop(i, 1, m) {
        cin >> a >> b;
        adj[a-1].PB(b-1);
        adj[b-1].PB(a-1);
    }
    
    vector<bool> visited(n, false), color(n, false);
    
    loop(i, 0, n-1) {
        if (!visited[i]) {
            if (!(bipartiteness_check(i, n, adj, visited, color))) {
                cout << "IMPOSSIBLE" << '\n';
                return;
            }
        }
    }
    for (auto x : color) {
        cout << (int) x + 1<< " ";
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    building_teams();
 
    return 0;
}
