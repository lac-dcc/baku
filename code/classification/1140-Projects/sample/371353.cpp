# include <bits/stdc++.h>
//# pragma GCC optimize("Ofast")
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
# define int long long
 
using namespace std;
 
const int N = 4e5 + 7;
 
vector < pair < int, int > > g[N];
 
int dp[N];
 
int32_t main() {
	speed;
	int n, cnt = 1;
	cin >> n;
 
	vector < int > c, a(n), b(n), p(n);
	vector < pair < int, pair < int, int > > > vc;
	map < int, int > mp;
 
	for ( int i = 0; i < n; i++ ) {
		cin >> a[i] >> b[i] >> p[i];
		c.push_back(a[i]);
		c.push_back(b[i]);
	}
	sort( c.begin(), c.end() );
	mp[c[0]] = cnt++;
 
	for ( int i = 1; i < 2 * n; i++ ) {
		
		if ( c[i] == c[i - 1] ) {
			continue;
		}
		mp[ c[i] ] = cnt++;
	}
	for ( int i = 0; i < n; i++ ) {
		a[i] = mp[a[i]];
		b[i] = mp[b[i]];
 
		g[ a[i] ].push_back( { b[i], p[i] } );		
	}	
	for ( int i = 1; i < N; i++ ) {
		
		for ( auto p: g[i] ) {
			int t = p.first, x = p.second;
 
			dp[t] = max( dp[t], dp[i - 1] + x );
		}
		dp[i] = max( dp[i], dp[ i - 1] );
	}
	cout << dp[N - 1];
}			 			
