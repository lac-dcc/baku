#include <bits/stdc++.h>
 
using namespace std;
 
#define LL long long
#define ULL unsigned LL
#define LD long double
 
const int N = 2e5 + 2137;
LL dp[2*N + 1];
vector<pair<int, int>> ev[2*N];
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int a[n], b[n], p[n];
	map<int, int> M;
	for(int i=0; i<n; i++) {
		cin>>a[i]>>b[i]>>p[i];
		M[a[i]] = 1, M[b[i]] = 1;
	}
	int kt = 1;
	for(auto it = M.begin(); it != M.end(); ++it) {
		it->second = kt++;
	}
	for(int i=0; i<n; i++) {
		a[i] = M[a[i]];
		b[i] = M[b[i]];
		ev[b[i]].push_back({a[i], i});
		//cerr<<a[i]<<" - "<<b[i]<<"\n";
	}
	for(int i=1; i<=kt; i++) {
		dp[i] = dp[i-1];
		for(auto x : ev[i]) {
			dp[i] = max(dp[i], dp[x.first-1]+p[x.second]);
		}
	}
	cout<<dp[kt];
}
