#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
 
#define ll long long
#define oo 1e18
#define endl '\n'
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
 
//#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
//#define ordered_multiset tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
//#define trie trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>
 
//using namespace __gnu_pbds;
using namespace std;
 
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
 
const int N = 2e5 + 10, mod = 1e9 + 7;
vector<pair<pair<int, int>, ll> > a;
vector<ll> dp;
int n;
 
ll seg[N * 10];
 
void update(int i, ll val, int p = 1, int L = 1, int R = n) {
    if (L > i || R < i) return;
    if (L >= i && R <= i) {
        seg[p] = val;
        return;
    }
 
    int mid = (L + R) / 2;
    update(i, val, p * 2, L, mid);
    update(i, val, p * 2 + 1, mid + 1, R);
    seg[p] = max(seg[p * 2], seg[p * 2 + 1]);
}
 
ll query(int i, int j, int p = 1, int L = 1, int R = n) {
    if (L > j || R < i) return 0;
    if (L >= i && R <= j) return seg[p];
 
    int mid = (L + R) / 2;
    ll c1 = query(i, j, p * 2, L, mid);
    ll c2 = query(i, j, p * 2 + 1, mid + 1, R);
    return max(c1, c2);
}
 
void testCase() {
    cin >> n;
    a.resize(n);
    map<int, int> Map;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first.second >> a[i].first.first >> a[i].second;
        Map[a[i].first.first];
        Map[a[i].first.second];
    }
 
    sort(all(a));
    int cnt = 1;
    for (auto &x: Map) {
        x.second = cnt++;
    }
 
    n = cnt;
    dp.resize(n);
 
    for (auto p: a) {
        ll q = query(1, Map[p.first.second] - 1) + p.second;
        if (q > dp[Map[p.first.first]]) {
            dp[Map[p.first.first]] = q;
            update(Map[p.first.first], q);
        }
    }
 
    cout << query(1, n) << endl;
 
}
 
int main() {
    FASTIO
    int T = 1;
//    cin >> T;
    for (int i = 0; i < T; i++) {
        testCase();
    }
    return 0;
}
