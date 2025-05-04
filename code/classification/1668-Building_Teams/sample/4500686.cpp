#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int n, m;
 
bool possible = true;
 
vector <int> adj[100005];
 
int label[100005];
 
void bfs(int n) {
    queue <int> Q;
    Q.push(n);
    label[n] = 1;
    while (Q.size() != 0) {
        int cur = Q.front();
        for (int neigh : adj[cur]) {
            if (not label[neigh]) {
                label[neigh] = (label[cur] % 2) + 1;
                Q.push(neigh);
                continue;
            }
            if (label[neigh] == label[cur]) {
                possible = false;
                return;
            }
        }
        Q.pop();
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        if (not label[i]) {
            bfs(i);
        }
        if (not possible) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << label[i] << " ";
    }
    return 0;
}
