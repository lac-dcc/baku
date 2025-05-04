#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout<<'\n';
#define E cerr<<'\n';
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll mod = 1000000007;
const ll INF = 1e18;
int n, x;
int res[1000005], a[1000001], b[1000001];
void solve(){
	cin >> n >> x;
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i <= n; i++)cin >> b[i];
	for(int i = 1; i <= x; i++)res[i] = -1;
	
	for (int j = 1; j <= n; j++){
		for(int i = x; i - a[j] >= 0; i--){
			if(res[i-a[j]] >= 0)res[i]=max(res[i], res[i-a[j]]+b[j]);
		}
	}
	int mx = 0;
	for(int i = 0; i <= x; i++)mx= max(mx, res[i]);
	cout << mx;
}    
signed main(){
    IOS;
    int t = 1;
    //cin>>t;
    while(t--){
		solve();
		cout<<'\n';
    }
}