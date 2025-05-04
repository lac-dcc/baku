#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#define ll long long
#define ld long double
#define mp make_pair
#define vt vector
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define deb(x) cout << #x << ": "<< x << '\n';
using namespace std;
 
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<double,double>;
 
using vi = vt<int>;
using vb = vt<bool>;
using vl = vt<ll>;
using vd = vt<double>;
using vs = vt<string>;
using vpi = vt<pi>;
using vpl = vt<pl>;
using vpd = vt<pd>;
#define lb lower_bound
#define ub upper_bound
// #define tcT template<class T
// #define tcTU tcT, class U
template<class T> int lwb(vt<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
template<class T> int upb(vt<T>& a, const T& b) { return int(ub(all(a),b)-bg(a)); }
 
const int dx[8]  = {1,1,0,-1,-1,-1, 0, 1};
const int dy[8]  = {0,1,1, 1, 0,-1,-1,-1};
const int d4x[4]  = {1,-1, 0, 0};
const int d4y[4]  = {0, 0, 1,-1};
 
const double PI = acos(-1.0);
const int INF = INT_MAX;
const ll int MOD = 1e9+7;
 
vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
 
    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
 
    res.push_back (s.substr (pos_start));
    return res;
}
 
string& remove_chars(string& s, const string& chars) {
    s.erase(remove_if(s.begin(), s.end(), [&chars](const char& c) {
        return chars.find(c) != string::npos;
    }), s.end());
    return s;
}
 
string to_uppercase(string cadena) {
  for (int i = 0; i < cadena.length(); i++) cadena[i] = toupper(cadena[i]);
  return cadena;
}
 
string to_lowercase(string cadena) {
  for (int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
  return cadena;
}
 
string strip(const string &inpt) // " ABC" -> "ABC"
{
    auto start_it = inpt.begin();
    auto end_it = inpt.rbegin();
    while (std::isspace(*start_it))
        ++start_it;
    while (std::isspace(*end_it))
        ++end_it;
    return std::string(start_it, end_it.base());
}
 
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
template <typename T> std::istream& operator>>(std::istream& input, std::vector<T>& data){ for(T& x : data)input >> x;return input;}
template <typename T> std::ostream& operator<<(std::ostream& stream, const vector<T>& vec){ for(size_t i = 0; i < vec.size(); i++){stream << vec[i];if(i != vec.size() - 1)stream << ' ';}; return stream; }
 
// bool valid(int r, int c){
//     return r>=0 && c>=0 && r<n && c<m;
// }
 
// bool isValid (pair<int,int> pos){
// 	if (pos.fi < 0 || pos.fi >= lines)
// 		return false;
// 	if (pos.se < 0 || pos.se >= cols)
// 		return false;
// 	return true;
// }
 
// vector<pair<int,int>> dir = {
// 	{-1, 0},
// 	{1,0},
// 	{0,-1},
// 	{0,1},
// };
 
int mod(int a, int b, int c){ // pow(a,b) % c
	if (b==0) return 1;
 
	if (b%2 == 0){
		int x = mod(a,b/2,c);
		return (x*x)%c;
	}
	else return (a%c * mod(a,b-1,c))%c;
}
 
ll power(ll a, ll b){ // a raised to power b
  ll res=1;
  while(b){
    if(b&1) res=(res*a)%MOD;
    b>>=1;
    a=(a*a)%MOD;
  }
  return res;
}
 
int gcd(int x,int y){
  if(y==0)
   	return x;
  return gcd(y,x%y);	
}
 
bool myCompare(pair <int, int> p1, pair<int, int> p2){
	return p1.fi<p2.fi;
}
/*
3 11
5 3 4
*/
const int mxN = 1e6;
int dp[mxN];
void solve(){
	int n, x;
	cin >> n >> x;	
	int c[n];
	for(int i = 0; i<n;i++)
		cin >>c[i];
 
	for(int i = 1; i<=x;i++){
		dp[i] = 1e9;
		for(int j = 0; j<n;j++){
			if (c[j]<=i){
				dp[i] = min(dp[i], dp[i-c[j]]+1);
			}
		}
	}
	cout<< (dp[x] == 1e9 ? -1 : dp[x]);
}
	
int main(){
	 ios::sync_with_stdio(0);
	 cin.tie(0);
 
	 int t = 1;
	 // cin >> t;
	 while (t--)
	 	solve();
} 