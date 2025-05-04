#include <iostream>
 
using namespace std;
typedef long long ll;
 
const int N_MAX = 2e5 + 1;
const int INF = 2e9;
int n;
 
int main() {
	cin >> n;
	ll max_sub = -INF;
	ll cnt_sub = 0;
	ll x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt_sub = max(cnt_sub + x, x);
		max_sub = max(max_sub, cnt_sub);
	}
	cout << max_sub << endl;
}