#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int MAX_N = 1e5 + 5;
 
ll d[MAX_N];
bool visited[MAX_N];
vector <pair <int, int>> near[MAX_N];
priority_queue <pair <ll, int>> heap;
 
inline int read_int() {
    char c;
    while (!isdigit(c = getchar_unlocked()));
    int x = c - 48;
    while (isdigit(c = getchar_unlocked()))
        x = (x << 1) + (x << 3) + c - 48;
    return x;
}
 
inline void write_int(ll x) {
    if (x > 9)
        write_int(x / 10);
    putchar_unlocked(x%10 + 48);
}
 
int main() {
    int n = read_int(), m = read_int();
    while (m--) {
        int u = read_int(), v = read_int(), c = read_int();
        near[u].emplace_back(make_pair(v, c));
    }
 
    for (int i = 2; i <= n; ++i)
        d[i] = 1e18;
 
    heap.emplace(make_pair(0, 1));
 
    while (!heap.empty()) {
        int u = heap.top().second;
        heap.pop();
 
        if (visited[u])
            continue;
 
        visited[u] = true;
 
        for (auto x: near[u]) {
            int v = x.first, w = x.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                heap.emplace(make_pair(-d[v], v));
            }
        }
    }
 
    for (int u = 1; u <= n; ++u) {
        write_int(d[u]);
        putchar(' ');
    }
}
