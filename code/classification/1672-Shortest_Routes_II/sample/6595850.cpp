#include <bits/stdc++.h>
 
using namespace std;
 
template<typename T1,typename T2> istream &operator>>(istream &cin,pair<T1,T2> &a) { return cin>>a.first>>a.second; }
template<typename T1> istream &operator>>(istream &cin,vector<T1> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename T1,typename T2> ostream &operator<<(ostream &cout,const pair<T1,T2> &a) { return cout<<a.first<<' '<<a.second; }
template<typename T1,typename T2> ostream &operator<<(ostream &cout,const vector<pair<T1,T2>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename T1> ostream &operator<<(ostream &cout,const vector<T1> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
 
#define ll long long
#define ar array
#define rep(i, n) for (ll i = 0; i < n; i++)
#define print(answer) cout << answer << "\n";
#define vll vector<ll>
#define all(v) v.begin(), v.end()
 
 
void slv()
{
	int n, m, q;cin>>n>>m>>q;
	vector<vector<ll>> dists(n, vector<ll>(n, INT64_MAX));
	rep(i,m){
		ll a,b,c;cin>>a>>b>>c;
		a--; b--;
		dists[a][b] = min(dists[a][b], c);
		dists[b][a] = min(dists[b][a], c);
	}
	rep(i,n)dists[i][i] = 0;	
	rep(i,n){
		rep(j,n){
			rep(k,n){
				if(dists[j][i]<INT64_MAX&&dists[i][k]<INT64_MAX)
					dists[j][k] = min(dists[j][k], dists[j][i]+dists[i][k]);
			}
		}
	}
	
	rep(i,q){
		int a, b;cin>>a>>b;a--;b--;
		if(dists[a][b]==INT64_MAX)cout<<-1;
		else
			cout<<dists[a][b];
		cout<<'\n';
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t=1;
    //cin>>t;
    while (t--)
        slv();
}
 
