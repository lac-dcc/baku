#include <bits/stdc++.h>
 
using namespace std;
int n, m;
const long long inf = 1e18;
long long d[2555], c[2555];
int a[5555];
int b[5555];
long long w[5555];
int p[5555];
void ford_bellman() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int u = a[j];
            int v = b[j];
            long long c = max(d[u] + w[j], -inf);
            if(c < d[v]) {
                d[v] = c;
                p[v] = u;
            }
        }
    }
}
int u[5555];
void restore(int x) {
    vector<int> path, ans;
    for(int i = 0; i <= n; i++) {
        u[i] = -1;
    }
    while(true) {
        if(x == 0) break;
        if(u[x] != -1) {
            for(int i = u[x]; i < path.size(); i++) {
                ans.push_back(path[i]);
            }
            reverse(ans.begin(), ans.end());
            break;
        }
        u[x] = path.size();
        path.push_back(x);
        x = p[x];
    }
    cout << "YES" << "\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << ans[0] << "\n";
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> w[i];
    }
    ford_bellman();
    for(int i = 1; i <= n; i++) {
        c[i] = d[i];
    }
    ford_bellman();
    for(int i = 1; i <= n; i++) {
        if(c[i] != d[i]) {
            d[i] = -inf;
        }
    }
    ford_bellman();
    for(int i = 1; i <= n; i++) {
        if(c[i] != d[i] || d[i] == -inf) {
            restore(i);
            return 0;
        }
    }
    cout << "NO\n";
}
