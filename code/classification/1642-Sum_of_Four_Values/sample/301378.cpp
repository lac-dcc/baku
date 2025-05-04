#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#define FAST ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX = 2e5 + 2;
 
int main() {
	FAST;
	int n, x; cin >> n >> x;
	int a[MAX];
	vector<pair<int, P>> b;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			b.push_back({ a[i] + a[j], {i + 1, j + 1} });
 
	sort(b.begin(), b.end());
	for (int i = 0; i< int(b.size())-1; i++) {
		int k = b[i].first;
	//	if (k > x / 2) break;
		auto it = lower_bound(b.begin()+i+1, b.end(), make_pair(x - k, make_pair( 0,0 )));
		while (k + it->first == x) {
			int q, r,y, z;
			y = b[i].second.first, z = b[i].second.second;
			q = it->second.first, r = it->second.second;
			if (y == q || y == r || z == q || z == r) {
				it++;
				continue;
			}
			cout << y << " " << z << " ";
			cout << q << " " << r << '\n';
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
}