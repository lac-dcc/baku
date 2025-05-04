#include<bits/stdc++.h>
#include<bitset>
#include<nmmintrin.h>
using namespace std;
#define oOo {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define ll long long
#define vc vector
#define str string
#define e "\n"
#define all(v) (v).begin() , (v).end() 
#define File freopen("two2.in", "r", stdin);
#define ONES(x) _mm_popcnt_u64(x)
#define ONESs(x) __builtin_popcount(x)
#define MEM(x , y) memset(x , y , sizeof(x))
const int mod = 1e9 + 7;
const ll modd = 998244353;
const int oo = 0x3f3f3f3f;
bool ok = false, sat = false;
int dxx[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dyx[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll add(ll a, ll b, ll md) {
	return (((a % md) + (b % md)) % md);
}
ll mul(ll a, ll b, ll md) {
	return (((a % md) * (b % md)) % md);
}
//---------------------------- [ We need a learn ] -------------------------</end>
const int N = 1e6+1, M = 101;
int n, m;
str s_n, s_m;
vc<vc<int>>mem;
int dp(int a, int z) {
	if (a == n || z == m) {
		return (m - z) + (n - a);
	}
	int& ret = mem[a][z];
	if (~ret)return ret;
	if (s_n[a] == s_m[z]) {
		return ret = dp(a + 1, z + 1);
	}
	else {
		int op3 = dp(a + 1, z + 1) + 1;
		int op1 = dp(a + 1, z) + 1;
		int op2 = dp(a, z + 1) + 1;
		return ret = min({ op1, op2, op3 });
	}
}
int main() {
	oOo;
	//cin >> n >> m;
	cin >> s_n >> s_m;
	n = s_n.size(); m = s_m.size();
	mem = vc<vc<int>>(n + 1, vc<int>(m + 1, -1));
	cout<<dp(0, 0);
}
