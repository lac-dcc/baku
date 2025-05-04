#include <bits/stdc++.h>
#define fname "TASK 1639"
#define bug(x) cerr << (#x) << " = " << (x) << '\n'
#define ll long long
#define ld long double
#define ull unsigned long long
#define ui unsigned int
#define REP0(i, n) for(int i = 0, _n = (n); i < _n; ++i)
#define REP1(i, n) for(int i = 1, _n = (n); i <= _n; ++i)
#define REPB0(i, n) for(int i = (n) - 1; i >= 0; --i)
#define REPB1(i, n) for(int i = (n); i > 0; --i)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; ++i)
#define FORB(i, a, b) for(int i = (a), _b = (b); i >= _b; --i)
#define ARR0(a, n) {cerr <<(#a)<< ": ["; REP0(i, n) cerr<< ' ' << a[i] <<','; cerr<<"]\n";}
#define ARR1(a, n) {cerr <<(#a)<< ": ["; REP1(i, n) cerr<< ' ' << a[i] <<','; cerr<<"]\n";}
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define LB lower_bound
#define UB upper_bound
#define X first
#define Y second
 
using namespace std;
template<typename T, typename V>
inline void bugp(const pair<T, V> &x) {cerr << '{' << x.X << ", " << x.Y << "}\n";}
template<typename T, typename U, typename V>
inline void bugpp(const pair<T, pair<U, V> > &x) {cerr << '{' << x.X << ", {" << x.Y.X << ", " << x.Y.Y << "}}\n";}
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<float, float> ff;
typedef pair<int, ii> iii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef pair<ll, ii> lii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int N = 5005, M = 5005;
int dp[N][M];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    REP1(i, n) dp[i][0] = i;
    REP1(j, m) dp[0][j] = j;
    REP1(i, n) {
        REP1(j, m) {
            if(s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
        }
    }
    cout << dp[n][m];
	return 0;
}