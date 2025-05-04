#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define fp(i,a,b) for(int i=a ; i<b ; i++)
#define fn(i,a,b) for(int i=a ; i>=b ; i--)
#define ones(x) __builtin_popcount(x)
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;*/
const int M=1e7+5;
const int inf=1e9;
const int mod=1e9+7;
 
void go(){
	ll x,y; cin >> y >> x;
	ll ans;
 
	if (x <= y){
		if (y&1) ans = (y-1)*(y-1) + x;
		else ans = y*y - x +1;
	}
	else {
		if (x&1) ans = x*x - y+1;
		else ans = (x-1)*(x-1) + y;
	}
 
	cout << ans << "\n";
}
 
int main(){	
 
	fastio;
	int tst=1;
	cin >> tst;
	while (tst--) go();
 
	return 0;
}