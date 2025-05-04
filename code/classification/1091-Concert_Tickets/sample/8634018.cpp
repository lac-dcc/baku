#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ll long long
#define f first
#define s second
#define ALL(x) x.begin(), x.end()
#define RALL(x) x.rbegin(), x.rend()
 
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3f;
const int EPS = 1e-9;
const int MOD = 1e9+7;
const int MAXN = 1e3+10;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
 
void solve(){
	int x; cin >> x;
}
 
bool cmp(pii a, pii b){
	return a.s < b.s;
}
 
int main() { _
    int n, m; cin >> n >> m;
	
	multiset<int> ms;
 
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		ms.insert(x);
	}
 
	int t;
	while(m--){
		cin >> t;
		auto it = ms.upper_bound(t);
		if(it == ms.begin()) cout << -1 << '\n';
		else {
			cout << *(--it) << '\n'	;
			ms.erase(it);
		}
	}	
 
    exit(0);
}
