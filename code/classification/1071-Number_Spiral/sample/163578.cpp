#include <bits/stdc++.h>
#define tam 1000005
 
using namespace std;
 
typedef long long ll;
typedef vector <int> vi;
typedef vector <ll> vl;
typedef pair <ll, ll> dl;
typedef pair <ll, int> ii;
typedef pair <ii, ll> iil;
typedef vector <ii> vii;
typedef vector <vi> graph;
 
bool comp(char a, char b) {
	return a > b;
}
 
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
	int t;
	cin >> t;
	ll y, x;
	while (t--) {
		cin >> y >> x;
		ll num;
		if (x > y) {
			if (x & 1) {
				num = x * x;
				num -= (y - 1);
			} else {
				num = (x * x) - (x * x - (x - 1) * (x - 1)) + 1;
				num += (y - 1);
			}
		} else if (y > x) {
			if (!(y & 1)) {
				num = y * y;
				num -= (x - 1);
			} else {
				num = (y * y) - (y * y - (y - 1) * (y - 1)) + 1;
				num += (x - 1);
			}
		} else {
			if (x & 1) {
				num = x * x;
				num -= (y - 1);
			} else {
				num = y * y;
				num -= (x - 1);
			}
		}
		cout << num << "\n";
	}
	return 0;
}
