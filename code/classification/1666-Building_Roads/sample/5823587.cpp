#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vp = vector<pii>;
 
int N, M;
const int MAXN = 100005;
array<bool, MAXN> vis;
array<vi, MAXN> adj;
vector<vi> cclist;
void dfscc (int node, vi &cc) {
    vis[node] = true;
    cc.emplace_back(node);
    for(auto x : adj[node]) {
        if (!vis[x]) {
            dfscc(x, cc);
        }
    }
}
int main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a-1].emplace_back(b-1);
        adj[b-1].emplace_back(a-1);
    }
 
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            vi cc;
            dfscc(i, cc);
            cclist.emplace_back(cc);
        }
    }
 
    cout << cclist.size()-1 << "\n";
    for (int i = 0; i < cclist.size()-1; i++) {
        cout << cclist[i][0]+1 << " " << cclist[i+1][0]+1 << "\n";
    }
}
