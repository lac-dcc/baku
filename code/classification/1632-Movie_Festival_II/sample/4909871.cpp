// carot15
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define edn(x) {cout<<x;return;}
#define cyd {cout<<"Yes";return;}
#define cyn {cout<<"No";return;}
const ll nmax=2e5+5;
const ll mod=1e9+7;
const int X[]={0,0,1,-1};
const int Y[]={-1,1,0,0};
void solve(){
	int n,k,ans=0;
	cin>>n>>k;
	multiset<ll,greater<ll>> s;
	vector<vector<ll>> a(n+1,vector<ll>(2));
	for (int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][0];
	}
	s.insert(0);
	sort(a.begin()+1,a.end());
	for (int i=1;i<=n;i++){
		auto d=s.lower_bound(a[i][1]);
//		cout<<*d;
		if (*d==0){
			if (s.size()<=k) s.insert(a[i][0]),ans++;
		}else {
			s.erase(d);
			s.insert(a[i][0]); 
			ans++;
		}
//		multiset<ll,greater<ll>> s1;s1=s;
//		for (auto a:s){
//			cout<<a<<' ';
//		}cout<<'\n';
//		cout<<' '<<a[i][0]<<'\n';
	}
	cout<<ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
//	freopen(".INP", "r", stdin);
//	freopen(".OUT", "w", stdout);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
		cout<<'\n';
	}
}
