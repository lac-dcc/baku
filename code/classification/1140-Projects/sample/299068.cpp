#include <bits/stdc++.h>
#define sz(c)       int(c.size())
#define rep(i,a,b)  for (int i=a; i<(b); ++i)
#define per(i,a,b)  for (int i=(b)-1; i>=(a); --i)
#define fore(c,...) for (auto &__VA_ARGS__:(c))
using namespace std;
using ll = long long;
template<class T> bool umin(T &x,T y) { if (x<y) return 0; x=y; return 1; }
template<class T> bool umax(T &x,T y) { if (x>y) return 0; x=y; return 1; }
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(10);
 
	int n;
	cin>>n;
	vector<tuple<int,int,int>> proj(n);
	fore(proj,[a,b,p]) cin>>a>>b>>p;
 
	map<int,int> cc;
	fore(proj,[a,b,ignore]) {
		cc[a]=0;
		cc[b]=0;
	}
 
	int cnt=0;
	fore(cc,i) i.second=cnt++;
	fore(proj,[a,b,ignore]) {
		a=cc[a];
		b=cc[b];
	}
 
	vector<ll> best(cnt+1);
	sort(proj.begin(),proj.end());
	int cur=0;
	fore(proj,[a,b,p]) {
		while (cur<a) {
			umax(best[cur+1],best[cur]);
			cur++;
		}
		umax(best[b+1],best[a]+p);
	}
	while (cur<cnt) {
		umax(best[cur+1],best[cur]);
		cur++;
	}
	cout<<best[cnt]<<'\n';
}