#include <iostream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string.h>
#include <stdlib.h>
 
using namespace std;
// vector push_back push front top empty pop make_pair long long insert begin end  
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair <int,int> > vpi;
typedef vector<long long> vll;
typedef pair<int,int> pi;
#define F first
#define ln '\n'
#define S second
#define PB push_back
#define MP make_pair
#define B begin()
#define RB rbegin()
#define E end()
#define RE rend()
#define Z size()
#define REP(i,a,b) for (int i = a; i < b; i++)
#define L length()
#define show(a) cerr << " *** " << a << endl;
#define show1(a) cerr << " /// " << a << endl;
#define valid(a,b,c) (a >= b && a < c ? 1 : 0)
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const int mod = (int)1e9 + 7;
const ll INF64 = 3e18;
void smxl(ll &a, ll b){if (a < b)a=b;}
void smnl(ll &a, ll b){if (a > b)a=b;}
void adsl(ll &a, ll b){a += b;if (a >= mod)a -= mod;}
void misl(ll &a, ll b){a -= b;if (a >= mod)a -= mod; if (a < 0)a += mod;}
void smx(ll &a, ll b){if (a < b)a=b;}
void smn(ll &a, ll b){if (a > b)a=b;}
void ads(ll &a, ll b){a += b;if (a >= mod)a -= mod;}
void mis(ll &a, ll b){a -= b;if (a >= mod)a -= mod; if (a < 0)a += mod;}
ll gcd(ll a, ll b) {return (b==0? a:gcd(b,a%b));}
ll egcd(ll a, ll b, ll & x, ll & y) {if (a == 0){x = 0;y = 1;return b;}ll x1, y1;ll d = egcd(b % a, a, x1, y1);x = y1 - (b / a) * x1;y = x1;return d;}
ll mbinp(ll a, ll b){a %= mod;if (b == 0)return 1;ll ans = mbinp(a, b/2);ll tmp = (ans * ans) % mod;if (b % 2)return ((tmp * a) % mod);return ((tmp) % mod);}
ll binp(ll a, ll b){if (b == 0)return 1;ll ans = binp(a, b/2);ll tmp = (ans * ans);if (b % 2)return ((tmp * a));return ((tmp));}
long long C(int n, int m){ll ret=1;for(int i=1;i<=m;i++){ret*=(n-i+1);ret/=i;}return ret;}
long long overbinp(long long a, int b){long long res = 1;while (b){if (b & 1){if (res < INF64 / a) res *= a;else return INF64;}if (b > 1){if (a < INF64 / a) a *= a;else return INF64;}b >>= 1;}return res;}
/*const int FMAXN = 1000 * 1000 + 10;int fen[FMAXN];void add(int x, int val){for (int i = x + 1; i < MAXN; i += i & (-i)) fen[i] += val;}int get(int x){int ans = 0;for (int i = x; i > 0; i -= i & (-i)) ans += fen[i];return ans;}int sum(int x, int y){return get(y) - get(x);}*/
/*int distfloor(int n){int sum;int la;for (int i = 1; i <= n; i = la+1){la = n/(n/i);sum++;show(n/i);}return sum;}*/
//int pointsCoveredBySegment(pi a, pi b){return(gcd((int)abs(a.F-b.F),(int)abs(a.S-b.S))+1);}
//segment inters
/*struct seg{int x1, y1, x2, y2;seg(){};};
struct line{long long Al, Bl, Cl;line(){};line(seg a){Al = a.y1 - a.y2;Bl = a.x2 - a.x1;Cl = -Al * a.x1 - Bl * a.y1;};};
int get(seg a){int dx = a.x1 - a.x2;int dy = a.y1 - a.y2;return __gcd(abs(dx), abs(dy)) + 1;}
long long det(long long a, long long b, long long c, long long d){return a * d - b * c;}
bool in(int x, int l, int r){if (l > r) swap(l, r);return (l <= x && x <= r);}
bool inter(seg a, seg b, int& x, int& y){line l1(a), l2(b);long long dx = det(l1.Cl, l1.Bl, l2.Cl, l2.Bl);long long dy = det(l1.Al, l1.Cl, l2.Al, l2.Cl);long long d = det(l1.Al, l1.Bl, l2.Al, l2.Bl);if (d == 0)return false;if (dx % d != 0 || dy % d != 0)return false;x = -dx / d;y = -dy / d;if (!in(x, a.x1, a.x2) || !in(y, a.y1, a.y2))return false;if (!in(x, b.x1, b.x2) || !in(y, b.y1, b.y2))return false;return true;}*/
//const int nax = 1e7+10;int par[nax];int siize[nax];int get(int x){return (x == par[x] ? x : par[x] = get(par[x]));}void merge(int a, int b){int x = get(a);int y = get(b);if (x == y)return;if (siize[x] < siize[y])swap(x,y);par[y] = x;siize[x] += siize[y];}
//const int nx = 1e5+10;ll cmd[nx];ll civ[nx];void initcmod(){	cmd[0] = 1;	cmd[1] = 1;	REP(i,2,nx)	{		cmd[i] = cmd[i-1]*i;		cmd[i] %= mod;	}	REP(i,0,nx)		civ[i] = mbinp(cmd[i],mod-2);}ll cmod(int n, int m){	initcmod();	ll ans = cmd[n];	ans *= civ[m];	ans %= mod;	ans *= civ[n-m];	ans %= mod;	return ans;}
//double triarea(double a, double b, double c){double p= (a+b+c)/2;return (sqrt(p*(p-a)*(p-b)*(p-c)));}
//ll diag(ll n){return ((n*(n-1))/2 - n);}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int,pi> > all(n);
	REP(i,0,n)
		cin>>all[i].S.F>>all[i].F>>all[i].S.S;
	sort(all.B,all.E);
	set<pair<ll,ll>> st;
	st.insert({0,0});
	ll ans = 0;
	REP(i,0,n)
	{
		auto t  = st.lower_bound({all[i].S.F,-1});
		t--;
		ans = max(ans,t->S+all[i].S.S);
		st.insert({all[i].F,ans});
	}
	cout <<ans;
}
