// ================================ c++ ====================================================
 
// #pragma GCC optimize("O3") // (code on steroids)
# include <bits/stdc++.h>
# pragma GCC diagnostic ignored "-Wunused-variable"
using namespace std;
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
// ================================= TYPEDEF MACROS ==========================================
 
typedef long long ll;
typedef unsigned long long ull;
 
# define vii vector<int>
# define vll vector<long long int>
# define vcc vector<char>
# define vvi vector<vector<int>>
# define vvl vector<vector<long long int>>
# define vvc vector<vector<char>>
# define pii pair<int,int>
# define pll pair<long long int, long long int>
# define sii set<int>
# define sll set<long long int>
# define scc set<char>
# define usii unordered_set<int>
# define usll unordered_set<long long int>
# define uscc unordered_set<char>
# define msii multiset<int>
# define msll multiset<long long int>
# define mscc multiset<char>
# define mii map<int,int>
# define mll map<long long int,long long int>
# define mci map<char,int>
# define mcl map<char,long long>
# define umii unordered_map<int,int>
# define umll unordered_map<long long int,long long int>
# define umci unordered_map<char,int>
# define umcl unordered_map<char,long long>
 
// ================================ MACROS =======================================
 
// Range based for loops
# define forr(i,a,b) for(long long i=a;i<b;i++)
 
# define P0(x) cout<<(x)<<' '
# define P1(x) cout<<(x)<<"\n"
# define P2(x,y) cout<<(x)<<' '<<(y)<<' '<<"\n"
# define P3(x,y,z) cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<"\n"
# define P4(x,y,z,w) cout<<(x)<<' '<<(y)<<' '<<(z)<<' '<<(w)<<' '<<"\n"
# define endl "\n"
# define lb lower_bound
# define ub upper_bound
 
 
ll hcf(ll a, ll b) {if (!a) return (b); else return (hcf(b % a, a));}
ll lcm(ll a, ll b) {return ((a * b) / hcf(a, b));}
# define lif(a,b) (((a)%(b))?(((a)/(b))+1):((a)/(b)))
 
// ================================ ENTRY POINT ============================================================
// Constants
# define INF LLONG_MAX
# define mod 1000000007
# define nax 100005
 
bool sortBySec(tuple<ll, ll, ll>& a, tuple<ll, ll, ll>& b) {
	return get<1>(a ) < get<1>(b);
}
int32_t main()
{
	fastio;
 
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	ll n; cin >> n;
	vector<tuple<ll, ll, ll>> projects;
	forr(i, 0, n) {
		ll a, b, p; cin >> a >> b >> p;
		projects.push_back({a, b, p});
 
	}
	sort(projects.begin(), projects.end(), sortBySec);
	forr(i, 1, n) {
		ll st = get<0>(projects[i]);
		ll ind = -1;
		for (ll j = n; j >= 1; j /= 2) {
			while (ind + j < i && get<1>(projects[ind + j]) < st)ind += j;
		}
		if (ind != -1)get<2>(projects[i]) += get<2>(projects[ind]);
		get<2>(projects[i]) = max(get<2>(projects[i]), get<2>(projects[i - 1]));
	}
	cout << get<2>(projects.back()) << endl;
}