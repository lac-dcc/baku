#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt,sse,sse2,sse3,sse4,mmx")
 
#define loop(n) for(int $i = 0; $i < n; $i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
 
#define int ll
 
using namespace std;
 
typedef long long ll;
 
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<int, int, int, int, int> iiiii;
 
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<iiii> viiii;
typedef vector<iiiii> viiiii;
 
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<viii> vviii;
typedef vector<viiii> vviiii;
typedef vector<viiiii> vviiiii;
 
template<typename T>
ostream & operator<<(ostream &os, const vector<T> &v)
{
    for(auto &x:v) cout << x << ' ';
    return os;
}
 
const int INF = 1e9+7;
 
int n, m;
vvii graph;
 
int32_t main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    cin >> n >> m;
    graph.resize(n);
    loop(m)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({b,c});
    }
 
    priority_queue<ii, vii, greater<ii>> pq;
    vi dist(n, -1);
    pq.push({0,0});
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if(dist[u] != -1) continue;
        dist[u] = d;
        for(auto [v, w]:graph[u])
        {
            if(dist[v] == -1)
            {
                pq.push({d+w, v});
            }
        }
    }
 
    cout << dist;
}
