#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define PI acos(-1)
#define ld long double
//mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9+7, N = 2e5+5;
 
int n, k;
int a[N];
void solve(int test_case){
	int i, j, x;
	cin >> n >> x;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	unordered_map<int, pii> m;
	m.reserve(1<<22);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(m.find(x-(a[i]+a[j]))!=m.end()){
				pii temp = m[x-(a[i]+a[j])];
				cout << i+1 << ' ' << j+1 << ' ' << temp.ff << ' ' << temp.ss;
				return;
			}
		}for(j=0;j<i;j++){
			m[(a[i]+a[j])] = {i+1, j+1};
		}
			
	}cout << "IMPOSSIBLE";
	return;
}
 
signed main(){
	FASTIO;
#define MULTITEST 0
#if MULTITEST
	int ___T;
	cin >> ___T;
	for(int T_CASE = 1; T_CASE <= ___T; T_CASE++)
		solve(T_CASE);
#else
	solve(1);
#endif
	return 0;
}
 
