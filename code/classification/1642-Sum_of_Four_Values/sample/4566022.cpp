#include <bits/stdc++.h>
using namespace std;
 
#define forr(i,a,b) for(int i=(a);i<(b);++i)
#define forn(i,n) forr(i,0,n)
#define dforr(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define dforn(i,n) dforr(i,0,n)
#define db(v) cerr<<#v" = "<<(v)<<'\n'
#define vecp(v) cerr<<#v<<" = "; for(auto ee:v)cerr<<ee<<' '; cerr<<'\n'
#define nn cout<<'\n'
#define sz(v) (int(v.size()))
#define all(v) v.begin(), v.end()
#define pb push_back
#define pp pop_back
#define fst first
#define snd second
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 
const ll MAXN = 1e3+100;
const ll INF = 1e18+100;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;
const ld PI = acosl(-1);
 
int n;
int x;
int a[MAXN];
 
 
int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
	cin >> n >> x;
	forn(i,n) cin >> a[i];
 
	map<int, pii> L;
	map<int, pii> R;
 
	forn(i,n-1){
		forr(j,i+1,n){
			int s = a[i] + a[j];
 
			auto Lir = L.insert({s, {i,j}});
			if (!Lir.snd) { auto Lit = Lir.fst; Lit->snd = max(Lit->snd, {i,j}); }
 
			auto Rir = R.insert({s, {j,i}});
			if (!Rir.snd) { auto Rit = Rir.fst; Rit->snd = min(Rit->snd, {j,i}); }
		}
	}
 
	for (auto kv : L) {
		int s = kv.fst;
 
		auto itR = R.find(x-s);
		if (itR == R.end()) continue;
 
		auto Rv = itR->snd;
		auto Lv = kv.snd;
 
		if (Rv.fst < Lv.fst) {
			int i1 = Rv.snd + 1;
			int i2 = Rv.fst + 1;
			int i3 = Lv.fst + 1;
			int i4 = Lv.snd + 1;
			cout << i1 << ' ' << i2 << ' ' << i3 << ' ' << i4 << '\n';
			return 0;
		}
	}
 
	cout << "IMPOSSIBLE\n";
 
	return 0;
}
