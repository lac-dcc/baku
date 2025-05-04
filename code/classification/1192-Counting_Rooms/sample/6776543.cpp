#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
 
const int N = 1e3 + 9;
vector<string> g;
bool visited[N][N];
int n, m;
vector<pii> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
 
bool isValid(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
}
 
void dfs(int i, int j) {
    if (!isValid(i, j)) return;
    if (visited[i][j]) return;
    if (g[i][j] == '#') return;
 
    visited[i][j] = true;
 
    for (pii d : direction) {
        dfs(i + d.first, j + d.second);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        g.push_back(str);
    }
 
    int cnt = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') continue;
            if (visited[i][j]) continue;
            dfs(i, j);
            cnt++;
        }
    }
 
    cout << cnt << "\n";
}
