#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9 + 7;
 
typedef long long ll;
typedef long double ld;
typedef vector<long long> vi;
 
#define ALL(a) (a).begin(), (a).end()
#define PB push_back
#define MP make_pair
#define tr(container, it)\
    for (typeof (container.begin()) it = container.begin(); it != container.end(); ++it)
#define endl '\n'
 
vector<vector<char>> grid;
 
void dfs(int i, int j) {
    grid[i][j] = '#';
    if (i > 0 && grid[i-1][j] == '.') {
        dfs(i-1, j);
    }
    if (j > 0 && grid[i][j-1] == '.') {
        dfs(i, j-1);
    }
    if (i < grid.size()-1 && grid[i+1][j] == '.') {
        dfs(i+1, j);
    }
    if (j < grid[0].size()-1 && grid[i][j+1] == '.') {
        dfs(i, j+1);
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    //cin >> t; //comment if one test case
 
    int n, k, m;
 
    while (t--) {
        cin >> n >> m;
        grid.clear();
        grid.resize(n, vector<char> (m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#') {
                    continue;
                }
                else {
                    ans += 1;
                    dfs(i, j);
                }
            }
        }
        cout << ans << endl;
    }
 
    return 0;
}
