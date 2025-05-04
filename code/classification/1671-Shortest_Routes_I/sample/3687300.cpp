#include <bits/stdc++.h>
using namespace std;
struct Edge{unsigned long long to; unsigned long long weight;
};
bool operator<(Edge a, Edge b){
    return a.weight>b.weight;
}
 
int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    unsigned long long n,m,a,b,c; cin>>n>>m;
    vector<vector<Edge>> edges(n+1);
    for (unsigned long long i = 0; i < m; ++i) {
        cin>>a>>b>>c;
 
        edges[a].push_back({b,c});
 
    }
    priority_queue<Edge> ed;
    vector<unsigned long long> vis(n+1,1e15);
 
    ed.push({1,0});
    while (!ed.empty()){
        Edge current = ed.top();
        ed.pop();
        if(vis[current.to]<1e15)continue;
        vis[current.to] = current.weight;
        for (Edge e: edges[current.to]) {
            e.weight+=current.weight;
            ed.push(e);
        }
    }
    cout<<vis[1];
    for (unsigned long long i = 2; i < vis.size(); ++i) {
        cout<<" "<<vis[i];
    }cout<<'\n';
 
 
    return 0;
}
