#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " - "; print (x); cerr << '\n';
#else
#define debug (x)
#endif
#define mod (1000000007)
#define int long long
#define nline '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);freopen("err.txt","w+", stderr);
#define vi vector<int>
#define pb(x) push_back(x)
#define po() pop_back()
#define pf(x) push_front(x)
#define Fi(x,y) for(int i=x; i<y; ++i)
#define Fj(x,y) for(int j=x; j<y; ++j)
#define Fk(x,y) for(int k=x; k<y; ++k)
#define Fr(x,y) for(int i=x; i>=y; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
 
template <class T> void print ( T v ) {	cerr << v << " ";}
template <class T> void print ( vector<T> &v ) {cerr << '[' << ' '; for ( auto &x : v ) cerr << x << ' '; cerr << ']'; cerr << nline;}
template <class T> void print ( set<T> &v ) {cerr << '[' << ' '; for ( auto &x : v ) cerr << x << ' '; cerr << ']'; cerr << nline;}
template <class T> void print ( pair<T, T> &v ) {cerr << "[ " << v.first <<  ' ' << v.second << " ]" <<  nline;}
template <class T> void print ( map<T, T> &v ) {cerr << nline; for ( auto &i : v ) {cerr << "[ " << i.first << " " << i.second << " ]" << nline;}}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 
int t, n, m, y, k;
 
void solve() {
	int n, m;
	cin >> n >> m;
	char v[n][m];
 
	Fi ( 0, n ) {
		Fj ( 0, m ) cin >> v[i][j];
	}
 
	int vis[n][m];
	memset ( vis, 0, sizeof vis );
 
	int cnt = 0;
	Fi ( 0, n ) {
		Fj ( 0, m ) {
			queue <pair<int, int>>  q;
			if ( v[i][j] == '.' && vis[i][j] == 0 ) {
				cnt += 1;
				q.push ( make_pair ( i, j ) );
				vis[i][j] = 1;
 
				while ( !q.empty() ) {
					int r = q.front().first;
					int c = q.front().second;
					q.pop();
 
					if ( r - 1 >= 0 && v[r - 1][c] == '.' && vis[r - 1][c] == 0 ) {
						q.push ( make_pair ( r - 1, c ) );
						vis[r - 1][c] = 1;
					}
 
					if ( r + 1 < n && v[r + 1][c] == '.' && vis[r + 1][c] == 0 ) {
						q.push ( make_pair ( r + 1, c ) );
						vis[r + 1][c] = 1;
					}
 
					if ( c + 1 < m && v[r][c + 1] == '.' && vis[r][c + 1] == 0 ) {
						q.push ( make_pair ( r, c + 1 ) );
						vis[r][c + 1] = 1;
					}
 
					if ( c - 1 >= 0 && v[r][c - 1] == '.' && vis[r][c - 1] == 0 ) {
						q.push ( make_pair ( r, c - 1 ) );
						vis[r][c - 1] = 1;
					}
				}
			}
		}
	}
	cout << cnt << nline;
}
 
signed main() {
	fast_io;
#ifndef ONLINE_JUDGE
	file_io
#endif
 
	// cin >> t;
	t = 1 ;
	while ( t-- ) {
		solve();
	}
 
	return 0;
}
