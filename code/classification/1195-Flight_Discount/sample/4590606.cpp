#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
struct E{
    int v, w, c;
};
struct cmp{
    bool operator()(E a, E b){
        return a.w > b.w;
    }
};
array<array<bool, 2>, 100004> vis;
array<vector<E>, 100004> G;
int run(int s, int t){
    E e;
    priority_queue<E, vector<E>, cmp> Q;
    Q.push({s, 0, 0});
    while(!Q.empty()){
        e = Q.top();
        Q.pop();
        if(vis[e.v][e.c]) continue;
        if(e.v == t) return e.w;
        vis[e.v][e.c] = 1;
        for(auto [v, w, c] : G[e.v]){
            if(!(e.c & c)) Q.push({v, e.w + w, c | e.c});
        }
    }
}
signed main(){
    int n, m, a, b, c;
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> c;
        G[a].pb({b, c, 0});
        G[a].pb({b, c / 2, 1});
    }
    cout << run(1, n);
    return 0;
}
