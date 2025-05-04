#include <bits/stdc++.h>
 
#define MAXN 200100
#define INF 1000000000000000
 
using namespace std;
 
int n, q;
 
typedef long long int lli;
 
lli pref_arr[MAXN];
lli vals[MAXN];
lli maior[4 * MAXN];
lli menor[4 * MAXN];
lli resp[4 * MAXN];
lli lazy[4 * MAXN];
 
void espreguicar(int node, int i, int j) {
    if (lazy[node] != 0) {
        maior[2 * node] += lazy[node];
        maior[2 * node + 1] += lazy[node];
        menor[2 * node] += lazy[node];
        menor[2 * node + 1] += lazy[node];
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
        lazy[node] = 0;
    }
}
 
void update(int node, int i, int j, int st, int ed, int val) {
    if (ed < i || st > j) return;
    if (st <= i && j <= ed) {
        maior[node] += val;
        menor[node] += val;
        lazy[node] += val;
        // cout << "Maior " << i << " " << j << " " << maior[node] << "\n";
        // cout << "Menor " << i << " " << j << " " << menor[node] << "\n";
        // cout << "Resp " << i << " " << j << " " << resp[node] << "\n";
        return;
    }
    espreguicar(node, i, j);
    update(2 * node, i, (i + j) / 2, st, ed, val);
    update(2 * node + 1, (i + j) / 2 + 1, j, st, ed, val);
    maior[node] = max(maior[2 * node], maior[2 * node + 1]);
    menor[node] = min(menor[2 * node], menor[2 * node + 1]);
    resp[node] = max(max(maior[2 * node + 1] - menor[2 * node], 0LL),
                     max(resp[2 * node], resp[2 * node + 1]));
    // cout << "Maior " << i << " " << j << " " << maior[node] << "\n";
    // cout << "Menor " << i << " " << j << " " << menor[node] << "\n";
    // cout << "Resp " << i << " " << j << " " << resp[node] << "\n";
}
 
pair<lli, pair<lli, lli>> query(int node, int i, int j, int st, int ed) {
    if (ed < i || st > j) return make_pair(0, make_pair(INF, -INF));
    if (st <= i && j <= ed) {
        return make_pair(resp[node], make_pair(menor[node], maior[node]));
    }
    espreguicar(node, i, j);
    auto q1 = query(2 * node, i, (i + j) / 2, st, ed);
    auto q2 = query(2 * node + 1, (i + j) / 2 + 1, j, st, ed);
    return make_pair(
        max(max(q2.second.second - q1.second.first, 0LL), max(q1.first, q2.first)),
        make_pair(min(q1.second.first, q2.second.first), max(q1.second.second, q2.second.second)));
}
 
void build(int node, int i, int j) {
    if (i == j) {
        maior[node] = pref_arr[i];
        menor[node] = pref_arr[i];
        resp[node] = 0LL;
        return;
    }
    build(2 * node, i, (i + j) / 2);
    build(2 * node + 1, (i + j) / 2 + 1, j);
    maior[node] = max(maior[2 * node], maior[2 * node + 1]);
    menor[node] = min(menor[2 * node], menor[2 * node + 1]);
    resp[node] = max(max(maior[2 * node + 1] - menor[2 * node], 0LL),
                     max(resp[2 * node], resp[2 * node + 1]));
}
 
int main() {
    cin >> n >> q;
    int curr_v;
    for (int i = 1; i <= n; i++) {
        cin >> curr_v;
        vals[i] = curr_v;
        pref_arr[i] = pref_arr[i - 1] + curr_v;
    }
    build(1, 0, n);
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        update(1, 0, n, a, n, b - vals[a]);
        vals[a] = b;
        cout << resp[1] << "\n";
    }
}
