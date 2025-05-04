#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pci = pair<char,int>;
using pic = pair<int,char>;
using pll = pair<ll, ll>;
using mii = map<int,int>;
using mci = map<char,int>;
 
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
 
#define debug(x) cout << #x << " = " << x <<"\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define prec(n) fixed<<setprecision(n)
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) ((int)(v).size())
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
 
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())
//#define print(x) for(auto it:x) cout<<it<<" ";
 
ll gcd(ll x, ll y){return !y? x : gcd(y, x % y);}
ll lcm(ll x, ll y){return x * (y / gcd(x, y));}
 
const int N=1e3 + 5;
const int MOD = 1e9 + 7;
 
//int dx[]={-1,-1,-1,0,0,1,1,1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int n, m;
 
vector<string> a;
bool visited[N][N];
 
bool bfs(int x, int y) {
	bool ok = 1;
	queue<pii> q;
	q.push({x, y});
	visited[x][y] = 1;
	
	while (!q.empty()) {
		pii p = q.front();
		q.pop();
		//cout << p.ff << " " << p.ss << "\n";
		//if (p.ff == n - 1 || p.ff == 0 || p.ss == m - 1 || p.ss == 0) ok = 0;
		for (int i = 0; i < 4; i++) {
			int xx = p.ff + dx[i];
			int yy = p.ss + dy[i];
			if (xx < n && xx >= 0 && yy < m && yy >= 0) {
				if (!visited[xx][yy] && a[xx][yy] == '.') {
					q.push({xx, yy});
					visited[xx][yy] = 1;
				}
				
			}
		}
	}
	return ok;
}
 
int main() {
	cin >> n >> m;
	int ans = 0;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		a.pb(s);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && a[i][j] == '.') {
				if (bfs(i, j)) ans++;			
			}
			visited[i][j] = 1;
		}
	}
	cout << ans;
	
	
}
