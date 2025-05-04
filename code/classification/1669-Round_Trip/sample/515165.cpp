#include <bits/stdc++.h> // This is all in one include library
using namespace std;
//------------------------------------------------
#define db(a) {cerr<<"\033[1;31m"<<"Debug: "<<"\033[0m"; cerr<<#a<<"\033[1;31m"<<" : "<<"\033[0m"<<a<<'\n'; cout.flush(); cerr.flush();}
#define dbiter(...) dbgIter(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbgIter(const char *sdbg, T a, T b) {cerr<<"\033[1;31m"<<"Debug: "<<"\033[0m"; cerr<<sdbg; cerr<<"\033[1;31m"<<" = "<<"\033[0m"; cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n"; cout.flush(); cerr.flush();}
#define endl '\n'  // WARNING: REMOVE this is working on interactive programs
#define ulimit(_i, _startLimit, _endLimit) for(int32_t _i = (_startLimit), _i ## ztempEnd = (_endLimit) ; _i <= _i##ztempEnd; ++_i)
#define dlimit(_i, _startLimit, _endLimit) for(int32_t _i = (_startLimit), _i ## ztempEnd = (_endLimit) ; _i >= _i##ztempEnd; --_i)
#define IN(type, arr, starti, endi) { type(ztempzi, starti, endi) cin>>arr[ztempzi]; }
#define OUT(type, arr, starti, endi, sep) { type(ztempzo, starti, endi) cout<<arr[ztempzo]<<sep; }
#define uall(arr_name) begin(arr_name),end(arr_name)
#define uiter(arr_name, iter_start, iter_end) next(begin(arr_name),iter_start),next(begin(arr_name),iter_end)
#define dall(arr_name) rbegin(arr_name),rend(arr_name)
#define diter(arr_name, iter_start, iter_end) make_reverse_iterator(next(begin(arr_name),iter_end)),make_reverse_iterator(next(begin(arr_name),iter_start))
#define gett(_tup, _n) get<_n>(_tup)
#define short int16_t
#define int int32_t
#define long int64_t     // WARNING: REMOVE this when using `long double`
#define int128 __int128  // WARNING: Only works with few compilers
template<typename T, typename S> inline auto min(const T a, const S b) { return ((a < b) ? a : b); }
template<typename T, typename S> inline auto max(const T a, const S b) { return ((a > b) ? a : b); }
template<typename T, typename S> inline bool contains(const T &container1, const S &value1) { return container1.find(value1) != container1.end(); }
template<typename T> using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;
template<typename T> using max_heap = priority_queue<T>;
template<typename T, typename U> std::vector<T> MatrixVector(int n, U v){ return std::vector<T>(n, v);}
template<typename T, class... Args> auto MatrixVector(int n, Args... args){auto val = MatrixVector<T>(args...); return std::vector<decltype(val)>(n, move(val));}
// auto matrixM = MatrixVector<int32_t>(9,8,7,6,5)  // dimention = 9*8*7*6, default value=5
 
//------------------------------------------------
 
/* 
• Directed Unweighted Graph
• This is struct can be used as Directed as well as Un-Directed Graph.
*/
struct Graph{
    struct GraphNode{
        int vertex, link;
        GraphNode(int v1, int l1): vertex{v1}, link{l1} {}
    };
    vector<GraphNode> adj;
    vector<int> head;
    const int vertices;
 
    inline Graph(const int &t_vertices, const int &t_edges=-1): vertices{t_vertices} {
        head.resize(t_vertices, -1);
        adj.reserve((0 <= t_edges) ? t_edges : t_vertices);
    }
 
    /* Adds an edge v1 ---> v2 . Call the function `add_edge(v2, v1)` to make the graph undirected */
    inline void add_edge(const int &v1, const int &v2){
        adj.emplace_back(v2, head[v1]);
        head[v1] = adj.size() - 1;
    }
 
    struct GraphIter{
        const Graph &t;
        int i;
 
        inline GraphIter(const Graph &t1): t{t1}, i{-1} {}
        inline GraphIter(const Graph &t1, const int &vertex1): t(t1), i{t.head[vertex1]} { }
        inline GraphIter& operator ++(){ i = t.adj[i].link; return *this; }
        inline const Graph::GraphNode& operator*(){ return t.adj[i]; }
        inline bool operator!=(const GraphIter &t1){ return i != t1.i; }  // (((&t)==(&t1.t)) && (i!=t1.i))
 
        inline GraphIter& begin() {return *this;}
        inline GraphIter end() {return GraphIter(this->t);}
    };
    // NOTE: highly suggested to be used in range based for loops only
    inline GraphIter edge_iterator(const int &vertex) const { return GraphIter(*this, vertex); }
};
 
struct CycleData{
    vector<bool> visited;
    vector<int> parent;
    int cycle_depth, cycle_head, cycle_tail;
    CycleData(const int &vertices){
        cycle_depth = 0;
        cycle_head = cycle_tail = -1;
        visited.resize(vertices, false);
        parent.resize(vertices, -1);
    }
};
 
/* Acyclic Graph are Bipartite Graph */
bool detect_cycle(const Graph &g, CycleData &cd, const int &v, const int &parent){
    ++cd.cycle_depth;
    if(cd.visited[v]) {
        cd.cycle_head = v;
        cd.cycle_tail = parent;
        return true;
    }
    cd.visited[v] = true;
    cd.parent[v] = parent;
    for(const Graph::GraphNode &i: g.edge_iterator(v)){
        if(i.vertex == parent) continue;
        if(detect_cycle(g, cd, i.vertex, v)) return true;
    }
    --cd.cycle_depth;
    return false;
}
 
pair<CycleData, bool> find_cycle(const Graph &g, const int &v_low, const int &v_high) {
    CycleData cd(g.vertices);
    for(int i = v_low; i <= v_high; ++i){
        if(cd.visited[i]) continue;
        if(detect_cycle(g, cd, i, -1)) return make_pair(cd, true);
    }
    cd.cycle_tail = cd.cycle_depth = -1;
    return make_pair(cd, false);
}
 
void solve(){
    int n,m;
    cin>>n>>m;
 
    Graph g(n+1, m);
    int a,b;
    ulimit(i,1,m){
        cin>>a>>b;
        g.add_edge(a,b);
        g.add_edge(b,a);
    }
 
    pair<CycleData, bool> result = find_cycle(g, 1, n);
    if(result.second == false) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        const CycleData &cd = result.first;
        // db(cd.cycle_depth); db(cd.cycle_head); db(cd.cycle_tail);
        // OUT(ulimit, cd.parent, 0, g.vertices-1, ' '); cout << endl;
        vector<int> cycle_arr; 
        cycle_arr.reserve(result.first.cycle_depth);
        cycle_arr.push_back(cd.cycle_head);
        for(int curr_v = cd.cycle_tail;
                curr_v != cycle_arr[0];
                curr_v = cd.parent[curr_v]) 
        {
            cycle_arr.push_back(curr_v);
        }
        cycle_arr.push_back(cycle_arr[0]);
 
        cout << cycle_arr.size() << endl;
        OUT(ulimit, cycle_arr, 0, cycle_arr.size()-1, ' ');
        cout << endl;
    }
 
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout.precision(20); cout << fixed;
 
    int T = 1;
    while (T--)
        solve();
 
    return 0;
}
