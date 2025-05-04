#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using ll = long long;
using namespace __gnu_pbds;
using namespace std;
const ll N = 1e5 + 7, K = 1e5+7, M = 1e9 + 7, OO = 1e18;
 
int dx[]{0, 1, 0, -1, 1, 1, -1, -1};
int dy[]{1, 0, -1, 0, 1, -1, -1, 1};
char di[]{'R', 'D', 'L', 'U'};
ll frq[N];
template<class T> struct V: vector<T>{using vector<T>::vector;
    void sort()            {std::sort(this->begin(), this->end());}
    void sort_dsc()     {std::sort(this->rbegin(), this->rend());}
    template<typename CMP>
    void sort_cst(CMP cmp) { std::sort(this->begin(), this->end(), cmp); }
    T sum()             {T sum = 0; for(auto& i: *this) sum += i; return sum;}
    void reverse()        {std::reverse(this->begin(), this->end());}
    void freqs()         {for(auto& i: *this) frq[i]++;}
    void freqsn()         {for(auto& i: *this) frq[i]--;}
    T max()             {return *std::max_element(this->begin(), this->end());}
    map<T, V<int>> indices()        {int n=this->size(); map<T, V<int>> ii; for(int i=0; i<n; i++) ii[(*this)[i]].push_back(i); return ii;}
    V<T> prefix_sums()     {int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]+(*this)[i]; return ps;}
    V<T> prefix_xr()     {int n=this->size(); V<T> ps(n+1,0); for(int i=0; i<n; i++) ps[i+1] = ps[i]^(*this)[i]; return ps;}
    friend ostream& operator<<(ostream& out, const V<T>& v) {for(auto& i: v) out << i << ' '; return out;}
    friend istream& operator>>(istream& in, V<T>& v) {for(auto& i: v) in >> i; return in;}
};
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* clang-format off */
namespace _DEBUG_UTIL_ { void print(const char *x) {} void print(bool x) { cerr << (x ? "T" : "F"); } void print(char x) { cerr << '\'' << x << '\''; } void print(signed short int x) { cerr << x; } void print(unsigned short int x) { cerr << x; } void print(signed int x) { cerr << x; } void print(unsigned int x) { cerr << x; } void print(signed long int x) { cerr << x; } void print(unsigned long int x) { cerr << x; } void print(signed long long int x) { cerr << x; } void print(unsigned long long int x) { cerr << x; } void print(float x) { cerr << x; } void print(double x) { cerr << x; } void print(long double x) { cerr << x; } void print(string x) { cerr << '\"' << x << '\"'; } template <size_t N> void print(bitset<N> x) { cerr << x; } void print(vector<bool> x) { int f = 0; cerr << '{'; for (bool i : x) { cerr << (f++ ? "," : ""); cerr << (i ? "T" : "F"); } cerr << "}"; } /* Template Datatypes Declarations */ template <typename T> void print(T x); template <typename T> void print(vector<vector<T>> mat); template <typename T, size_t N> void print(T (&arr)[N]); template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]); template <typename F, typename S> void print(pair<F, S> x); template <typename T> void print(priority_queue<T> pq); template <typename T> void print(priority_queue<T, vector<T>, greater<T>> pq); template <typename T> void print(stack<T> st); template <typename T> void print(queue<T> q); /* Template Datatypes Definitions */ template <typename T> void print(T x) { int f = 0; cerr << '{'; for (auto i : x) cerr << (f++ ? "," : ""), print(i); cerr << "}"; } template <typename T> void print(vector<vector<T>> mat) { int f = 0; cerr << "{\n"; for (auto i : mat) cerr << (f++ ? ",\n" : ""), print(i); cerr << "}\n"; } template <typename T, size_t N> void print(T (&arr)[N]) { int f = 0; cerr << '{'; for (auto &i : arr) cerr << (f++ ? "," : ""), print(i); cerr << "}"; } template <typename T, size_t N, size_t M> void print(T (&mat)[N][M]) { int f = 0; cerr << "{\n"; for (auto &i : mat) cerr << (f++ ? ",\n" : ""), print(i); cerr << "}\n"; } template <typename F, typename S> void print(pair<F, S> x) { cerr << '('; print(x.first); cerr << ','; print(x.second); cerr << ')'; } template <typename T> void print(priority_queue<T> pq) { int f = 0; cerr << '{'; while (!pq.empty()) cerr << (f++ ? "," : ""), print(pq.top()), pq.pop(); cerr << "}"; } template <typename T> void print(priority_queue<T, vector<T>, greater<T>> pq) { int f = 0; cerr << '{'; while (!pq.empty()) cerr << (f++ ? "," : ""), print(pq.top()), pq.pop(); cerr << "}"; } template <typename T> void print(stack<T> st) { int f = 0; cerr << '{'; while (!st.empty()) cerr << (f++ ? "," : ""), print(st.top()), st.pop(); cerr << "}"; } template <typename T> void print(queue<T> q) { int f = 0; cerr << '{'; while (!q.empty()) cerr << (f++ ? "," : ""), print(q.front()), q.pop(); cerr << "}"; } /* Printer */ template <typename T> void printer(const char *name, T &&head) { cerr << name << " = "; print(head); cerr << "]\n"; } template <typename T, typename... V> void printer(const char *names, T &&head, V &&...tail) { int bracket = 0, i = 0; while (names[i] != ',' or bracket != 0) { if (names[i] == '(') bracket++; else if (names[i] == ')') bracket--; i++; } cerr.write(names, i) << " = "; print(head); cerr << " ||"; printer(names + i + 1, tail...); } /* PrinterArr */ template <typename T> void printerArr(const char *name, T arr[], int N) { cerr << name << " : {"; for (int i = 0; i < N; i++) { cerr << (i ? "," : ""), print(arr[i]); } cerr << "}]\n"; } }
#ifndef ONLINE_JUDGE
#define debug(...) cerr << __LINE__ << ": [", _DEBUG_UTIL_::printer(#__VA_ARGS__, __VA_ARGS__) 
#define debugArr(arr, n) cerr << __LINE__ << ": [", _DEBUG_UTIL_::printerArr(#arr, arr, n) 
#else
#define debug(x...)
#define debugArr(arr, n)
#endif
/* clang-format on */
 
/*
* sucess is my only option - failure is not
*/
 
struct edge
{
    ll u, w;
};
template <typename Graph>
V<V<ll>> dijkstra(ll src, Graph &adj)
{
    V<V<ll>>dist(adj.size(), V<ll>(2, OO));
    priority_queue<tuple<ll, ll, bool>>pq;
    dist[src][0] = dist[src][1] = 0;
    pq.push({0, src, 0});
    while (pq.size())
    {
        auto e = pq.top();
        pq.pop();
        ll d, u;
        bool f;
        tie(d, u, f) = e;
        d = -d;
        if (d != dist[u][f]) continue;
        for (auto v : adj[u])
        {
            if (dist[v.u][f] > d + v.w) 
            {
                dist[v.u][f] = d + v.w;
                pq.push({-dist[v.u][f], v.u, f});
            }
            if (!f)
            {
                if (dist[v.u][1] <= d + v.w / 2) continue;
                dist[v.u][1] = d + v.w / 2;
                pq.push({-dist[v.u][1], v.u, 1});
            }
        }
    }
    return (dist);
}
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // ll tt; cin >> tt; while (tt--)
    {
        ll n, m, u, v, w, l;
        V<V<edge>>adj;
        V<ll>ans;
 
        cin >> n >> m;
        adj.resize(n + 1);
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            // adj[v].push_back({u, w});
        }
        auto dist = dijkstra(1, adj);
        
        cout << dist[n][1];
        // cout << (tt ? "\n" : "");
    }
}
