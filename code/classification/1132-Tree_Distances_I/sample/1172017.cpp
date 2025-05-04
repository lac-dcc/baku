#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define INF 0x3f3f3f3f
#define f first
#define s second
#define pii pair<int, int>
#define mod 1000000007
#define all(x) x.begin(), x.end()
#define mem(x, a) memset(x, a, sizeof(x))
#define loli ios_base::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int maxn = 1e6 + 50;
vector<int> vc[maxn];
int dis[maxn], far, mmax, ans[maxn];
 
void dfs(int x, int fa = 0, int len = 0){
	for(auto i : vc[x]){
		if(i != fa){
			dis[i] = max(dis[i], len + 1);
			dfs(i, x, len + 1);
		}
		if(mmax < dis[i]){
			mmax = dis[i];
			far = i;
		}
	}
}
 
signed main(){
	loli;
	//freopen("/home/iceylemon157/Desktop/test.in", "r", stdin);
	//freopen("/home/iceylemon157/Desktop/test.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++){
		int a, b;
		cin >> a >> b;
		vc[a].pb(b);
		vc[b].pb(a);
	}
	dfs(1);
	mmax = 0;
	dfs(far);
	dfs(far);
	for(int i = 1; i <= n; i ++) cout << max(ans[i], dis[i]) << " ";
}
