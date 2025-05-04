#include <bits/stdc++.h>
using namespace std;
 
#define sz(a) ((int)a.size())
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define forse(i,s,e) for(int i=(int)s;i<(int)e;i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
using dbl=double;
using ll=long long;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
 
dbl PI=3.141592653589793;
 
const int mx=1e9+1;
 
vector<int> out(vector<int> &in){
	int n=sz(in);
	vector<int> proc;
	proc.pb(0);
	forn(ind,n){
		int k=sz(proc);
		forn(id,k){ 
			auto i=proc[id];
			if(i+in[ind]<mx) proc.pb(i+in[ind]);
		}
	}
	return proc;
}
 
void solve(){
	int n,x;
	cin >> n >> x;
	int k=n/2;
	vector<int> in1(k),in2(n-k);
	forn(i,k) cin >> in1[i];
	forn(i,n-k) cin >> in2[i];
	auto v1=out(in1),v2=out(in2);
	sort(all(v1)),sort(all(v2));
 
	
	vector<pair<int,int>> nv1,nv2;
	forn(i,sz(v1)){
		if(nv1.empty()||nv1.back().fi!=v1[i]) nv1.pb({v1[i],1});
		else nv1.back().se++;
	}
	forn(i,sz(v2)){
		if(nv2.empty()||nv2.back().fi!=v2[i]) nv2.pb({v2[i],1});
		else nv2.back().se++;
	}
 
 
	ll out=0;
	for(auto &i:nv1){
		int ind=lower_bound(all(nv2),mp(x-i.fi,-1))-nv2.begin();
		if(ind<sz(nv2)&&i.fi+nv2[ind].fi==x){
			out+=1ll*i.se*nv2[ind].se;
		}
	}
	cout << out;
//	cerr << endl << clock()/1000.0 << endl;
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int T=1;
//	cin >> T;
	for(int c=1;c<=T;c++){
		solve();
	}
}
