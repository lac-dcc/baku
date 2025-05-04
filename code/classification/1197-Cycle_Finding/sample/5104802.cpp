#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
 
vector<vector<pair<int, int>>> G;
vector<long long> D;
vector<bool> V;
vector<int> P;
vector<int> C;
 
void ft(int x) {
    cout << x+1 << " ";
    if(!V[x]) exit(0);
    V[x] = 0;
    ft(C[x]);
}
 
void bt(int x) {
    if(V[x]) ft(x);
    V[x] = 1;
    C[P[x]] = x;
    bt(P[x]);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    int el[m][3]; for(auto &x : el) cin >> x[0] >> x[1] >> x[2];
    D.resize(n, inf); D[0] = 0; G.resize(n);
    P.resize(n); V.resize(n, 0); C.resize(n);
    for(auto x : el) G[--x[0]].push_back(make_pair(--x[1], x[2]));
 
    for(int i = 0; i < n; i++)
        for(auto x : el) if(D[x[0]]+x[2] < D[x[1]]) P[x[1]] = x[0], D[x[1]] = D[x[0]]+x[2];
    for(auto x : el)
        if(D[x[0]]+x[2] < D[x[1]]) cout << "YES\n", bt(x[0]);
 
    cout << "NO";
}
