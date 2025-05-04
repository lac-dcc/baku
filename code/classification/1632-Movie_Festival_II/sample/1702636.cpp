//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp << " " <<
#define nl << "\n"
 
signed main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, k; cin >> n >> k;
    vector<pair<int, int>> a;
    for(int i=0; i<n; ++i){
        int x, y; cin >> x >> y;
        a.emplace_back(y, x);
    }
    sort(a.begin(), a.end());
    multiset<int> last_visit;
    for(int i=0; i<k; ++i) last_visit.insert(1);
    int curr = 0, ans = 0;
    for(auto i : a){
    	auto f = last_visit.lower_bound(-i.second);
    	if(f==last_visit.end()) continue;
    	++ans;
    	last_visit.erase(f);
    	last_visit.insert(-i.first);
    }
    cout << ans << "\n";
}
