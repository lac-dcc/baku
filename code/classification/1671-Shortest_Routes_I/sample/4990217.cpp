#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define fori(n, i) for (int i=0; i<n; i++)
#define all(x) x.begin(),x.end()
 
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vii = vector<ii>;
using vvii = vector<vector<ii>>;
void fillArray(vi& arr, int len);
 
void fillArray(vi& arr, int len){
    int a;
    fori(len,i){
        cin >> a;
        arr.push_back(a);
    }
}
 
//// Building teams
//vector<vi> frndGraph = vector<vi>(1e5+1);
//vi in_time(1e5);
//vi out_time(1e5);
//vi colors(1e5);
//int t=1;
//bool impossible = false;
//
//void DFS(int u, bool color){
//    if(in_time[u]) {
//        if(color && colors[u] == 2)
//            impossible = true;
//        if(!color && colors[u] == 1)
//            impossible = true;
//        return;
//    }
//    if(color)
//        colors[u] = 1;
//    else
//        colors[u] = 2;
//    in_time[u]=t++;
//    for(auto &v : frndGraph[u]) DFS(v, !color);
//    out_time[u]=t++;
//}
//
//signed main() {
//    int n,m;
//    int u,v;
//    cin >> n;
//    cin >> m;
//    fori(m, i){
//        cin >> u >> v;
//        --u,--v;
//        frndGraph[u].push_back(v);
//        frndGraph[v].push_back(u);
//    }
//    fori(n, i){
//        if(!in_time[i])
//            DFS(i, true);
//    }
//    cout << endl;
//    if(impossible)
//        cout << "IMPOSSIBLE";
//    else{
//        fori(n, i){
//            cout << colors[i] << " ";
//        }
//    }
//    return 0;
//}
 
//// Shortest routes I
 
const int maxn = 1e5+5;
vvii connections;
const int inf = 1e14;
int n;
 
vector<int> dijkstra(int source) {
    set<ii> s; // set of {dist_to_source, vertex}
    vi distances(n, inf); // equiv. use double
// or any other big number
    distances[source] = 0;
    s.insert({0,source});
    while(!s.empty()) {
        auto [du,u] = *s.begin();
        s.erase(s.begin());
        if(du>distances[u]) continue;
        for(auto& [v, w] : connections[u]) {
            if(distances[v] > distances[u] + w) {
                distances[v] = distances[u] + w;
                s.insert({distances[v],v});
            }
        }
    }
    return distances;
}
 
signed main() {
    int m;
    int a,b,c;
    vi distances;
    cin >> n >> m;
    connections.resize(n);
    fori(m, i){
        cin >> a >> b >> c;
        --a, --b;
        connections[a].push_back({b,c});
        //connections[b].push_back({a,c});
    }
    distances = dijkstra(0);
    cout << endl;
    fori(n, i){
        cout << distances[i] << " ";
    }
}
