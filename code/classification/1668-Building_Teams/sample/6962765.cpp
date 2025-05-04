#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 1e5 + 5;
 
int n, m;
int color[MAXN];
vector<int> vec[MAXN];
 
void dfs(int idx, int val) {
    color[idx] = val;
    for (int a : vec[idx]) {
        if (color[a] == color[idx]) {
            cout << "IMPOSSIBLE" << '\n';
            exit(0);
        }
        else if (!color[a]) {
            if (color[idx] == 1) dfs(a, 2);
            else dfs(a, 1);
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
 
    for (int i = 1; i <= n; i++) {
        if (!color[i]) dfs(i, 1);
    }
 
    for (int i = 1; i <= n; i++) {
        cout << color[i] << ' ';
    }
    cout << '\n';
 
    return 0;
}
