#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T, class C = less<T>>
using rbtree = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;
using Trie = trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;
#define vec vector
#define int long long
 
signed main() { cin.tie(0) -> sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	vec<vec<int>> v(n + 1, vec<int>(n + 1, 1e18));
	for(int i = 1; i <= n; i++) v[i][i] = 0;
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a][b] = v[b][a] = min({v[a][b], v[b][a], c});
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			//if(i == k) continue;
			for(int j = 1; j <= n; j++) {
				//if(j == k) continue;
				if(v[i][j] > v[i][k] + v[k][j]) {
					v[i][j] = v[i][k] + v[k][j];
					v[j][i] = v[i][j];
				}
			}
		}
	}
	while(q--) {
		int a, b;
		cin >> a >> b;
		cout << (v[a][b] == 1e18? -1 : v[a][b]) << '\n';
	}
}
