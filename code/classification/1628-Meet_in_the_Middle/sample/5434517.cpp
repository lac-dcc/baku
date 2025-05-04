#include<bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
    #define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
    #define eprintf(...) 42
#endif
 
//order statistic tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<
    T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update
>;
#define pb push_back
#define mp make_pair
#define ins insert
#define popb pop_back
#define popf pop_front
#define ft front
#define bk back
#define fr first
#define sc second
using ll = long long;
using ld = long double;
using db = double;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<ld,ld>;
using str = string;
const int NAX = (int)1e5 + 1;
const int MOD = (int)1e9 + 7;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<ll>a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
    }
    unordered_map<ll,int>has;
    function<vector<ll>(int l, int r, int k)>Conquer = [&](int l, int r, int k){
		const int b = r - l;
		vector<ll>ans;
		for (int i = 0; i < (1 << b); ++i){
			ll sum = 0;
			for (int j = 0; j < b; j++){
				if ((1 << j) & i){
					sum+=a[j + l];
				}
			}
			//cout<<sum<<endl;
			ans.pb(sum);
		}
		return ans;
    };
    vector<ll>left=Conquer(0,n/2,1);
    vector<ll>right=Conquer(n/2, n, 2);
    sort(left.begin(), left.end());
    long long ans = 0;
    sort(right.begin(), right.end());
    for (ll i: left) {
		auto low_iterator = lower_bound(right.begin(), right.end(), x - i);
		auto high_iterator = upper_bound(right.begin(), right.end(), x - i);
		int start_index = low_iterator - right.begin();
		int end_index = high_iterator - right.begin();
		ans += end_index - start_index;
	}
 
    cout<<ans;
    return 0;
}
