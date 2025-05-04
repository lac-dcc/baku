// author: arpunagar
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
#define inv(v)         \
    for (auto &it : v) \
        cin >> it;
#define MOD 1000000007
#define pb push_back
#define popb pop_back()
#define endl "\n"
#define fi first
#define se second
#define ar array
typedef priority_queue<ll, vector<ll>, greater<ll>> minheap;
typedef priority_queue<ll> maxheap;
#define sortv(v) sort(v.begin(),v.end())
#define db(x) cout << (#x) << " is " << (x) << endl;
#define rsortv(v) sort(v.begin(),v.end(), greater<>());
 
ll nCr(ll n, ll r) {
    ll res = 1;
    if (r > n - r) {
        r = n - r;
    }
    for(int i=0;i<r;i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
const int N = 1e5+1;
vector<vi> adj;
vi ans;
void dfs(int i){
	ans[i]++;
	for(auto x: adj[i]){
		dfs(x);
		ans[i]+=ans[x];
	}
}
 
void solve(){
	int n;
	cin >> n;
	adj.resize(n+1);
	ans.resize(n+1);
	for(int i=2;i<=n;i++){
		int a;
		cin >> a;
		adj[a].pb(i);
	}
 
	dfs(1);
 
	for(int i=1;i<=n;i++) cout << ans[i]-1 << " ";
	cout << endl;
}
 
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int t = 1;
      
 
        while (t--)
            solve();
        return 0;
}
 
 
 
 
