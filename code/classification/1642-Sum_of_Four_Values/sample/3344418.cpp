/*#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
 
int main() {
    freopen("/Users/longhair/Downloads/test_input.txt", "r", stdin);
    freopen("/Users/longhair/Downloads/test_output.txt", "w", stdout);
 
    long long total_numbers, target;
    vector< pair<long long, long long> > numbers;
    unordered_map< long long, vector< pair<long long, long long> > > two_sum;
    set<long long> s;
    scanf("%lld %lld", &total_numbers, &target);
 
    for (int i = 0; i < total_numbers; i++) {
        long long num;
        scanf("%lld", &num);
        pair<long long, long long> a(num, i + 1);
        numbers.push_back(a);
    }
 
    sort(numbers.begin(), numbers.end());
 
    for (int i = 0; i < total_numbers; i++) {
        for (int j = i + 1; j < total_numbers; j++) {
            long long sum = numbers[i].first + numbers[j].first;
            s.insert(sum);
            pair<long long, long long> a(numbers[i].second, numbers[j].second);
            two_sum[sum].push_back(a);
        }
    }
 
    for (auto n : s) {
        long long x = target - n;
        if (s.find(x) != s.end()) {
            for (auto a : two_sum[n]) {
                for (auto b : two_sum[x]) {
                    int p = a.first;
                    int q = a.second;
                    int r = b.first;
                    int s = b.second;
                    if (p != r && p != s && q != r && q != s) {
                        cout << p << ' ' << q << ' ' << r << ' ' << s << endl;
                        return 0;
                    }
                }
            }
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
 
    return 0;
}*/
 
#include <bits/stdc++.h> // see /general/running-code-locally
using namespace std;
 
using ll = long long;
 
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash { /// use most bits rather than just the lowest ones
	const uint64_t C = ll(2e18*acos((long double)-1))+71; // large odd number
	const int RANDOM = rng();
	ll operator()(ll x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
		return __builtin_bswap64((x^RANDOM)*C); }
};
 
template<class K,class V> using ht = gp_hash_table<K,V,chash>;
 
int main() {
	setIO();
 
	int n, x; cin >> n >> x;
 
	vi v(n);
 
	for(int i = 0; i < n; i++) cin >> v[i];
 
	ht<int, pi> hm;
 
	for(int i = n - 1; i >= 0; i--) {
		for(int j = i - 1; j >= 0; j--) {
			int idx = x - v[i] - v[j];
			if(hm.find(idx) != hm.end()) {
				cout << i + 1 << " " << j + 1 << " " << hm[idx].f + 1 << " " << hm[idx].s + 1;
				return 0;
			}
		}
 
		for(int j = i + 1; j < n; j++) hm[v[i] + v[j]] = {i, j};
	}
 
	cout << "IMPOSSIBLE\n";
}