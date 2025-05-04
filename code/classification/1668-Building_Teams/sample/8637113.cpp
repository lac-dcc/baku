#include <bits/stdc++.h>
using namespace std;
enum Color{BLANK=0LL, WHITE, BLACK};
int main(){
    int64_t n, m; scanf("%lld%lld", &n, &m);
    vector<int64_t> adj[n];
    Color nodeColors[n];
    fill_n(nodeColors, n, Color::BLANK);
    while(m--){
        int64_t a,b; scanf("%lld%lld", &a, &b);
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    for(int64_t node = 0; node < n; ++node){
        if(nodeColors[node] == Color::BLANK){
            queue<pair<int64_t, Color>> q;
            q.push({node, Color::WHITE});
            while(not q.empty()){
                auto [currNode, color] = q.front(); q.pop();
                if(nodeColors[currNode] not_eq Color::BLANK){
                    if(nodeColors[currNode] not_eq color) printf("IMPOSSIBLE"), exit(0);
                    continue;
                }
                nodeColors[currNode] = color;
                for(int64_t neighbor: adj[currNode]){
                    q.push({neighbor, color == Color::WHITE ? Color::BLACK : Color::WHITE});
                }
            }
        }
    }
    for(int64_t node = 0; node < n; ++node) printf("%lld ", (int64_t)nodeColors[node]);
}