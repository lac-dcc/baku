#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const long long N = 505, INF = 1e15;
int n, m, q;
int SZ, pos[N], heap[N];
long long f[N], g[N][N];
int far[N][N];
 
void Enter() {
    cin >> n >> m >> q;
    int u, v, c;
    for(int i=1; i<=m; ++i) {
        cin >> u >> v >> c;
        if (far[u][v]) far[u][v] = min(far[u][v], c);
        else far[u][v] = c;
        far[v][u] = far[u][v];
    }
}
 
void push(int u) {
    int i = pos[u], j;
    if (!i) i = pos[u] = ++SZ;
    while (i > 1) {
        j = i>>1;
        if (f[heap[j]] <= f[u]) break;
        heap[i] = heap[j]; pos[heap[i]] = i;
        i = j;
    }
    heap[i] = u; pos[u] = i;
}
 
int pop() {
    int result = heap[1]; pos[heap[1]] = 0;
    int u = heap[SZ--];
    int i = 1, j;
    while (i<<1 <= SZ) {
        int j = i<<1;
        if (j < SZ && f[heap[j]] > f[heap[j+1]]) ++j;
        if (f[heap[j]] >= f[u]) break;
        heap[i] = heap[j]; pos[heap[i]] = i;
        i = j;
    }
    if (SZ) heap[i] = u, pos[u] = i;
    return result;
}
 
void Dijkstra(int x) {
    fill(f+1, f+n+1, INF);
    f[x] = 0;
    push(x);
    while (SZ) {
        int u = pop();
        for(int i=1; i<=n; ++i) {
            if (far[u][i] && f[i] > f[u] + far[u][i]) {
                f[i] = f[u] + far[u][i];
                push(i);
            }
        }
    }
    for(int i=1; i<=n; ++i) if (f[i] == INF) f[i] = -1;
}
 
void Process() {
    for(int i=1; i<=n; ++i) {
        Dijkstra(i);
        copy(f, f+n+1, g[i]);
    }
    int u, v;
    while (q--) {
        cin >> u >> v;
        cout << g[u][v] << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    Enter();
    Process();
}
