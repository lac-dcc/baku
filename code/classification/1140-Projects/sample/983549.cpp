#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()
 
void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
 
struct Arr{
	ll ff,ss,p;
};
 
bool comp(const Arr &a1,const Arr &a2){
	return a1.ff<a2.ff;
}
 
void solve(){
	int n;
	cin>>n;
	map<int,int> mm;
	vi ss;
	vector<Arr> arr(n);
	fr(i,0,n){
		cin>>arr[i].ff>>arr[i].ss>>arr[i].p;
		ss.pb(arr[i].ff);
		ss.pb(arr[i].ss);
	}
	sort(all(arr),comp);
	sort(all(ss));
	int ind=1;
	for(auto xx: ss){
		if(mm[xx]==0)
			mm[xx]=ind++;
	}
	int m=ind+1,st,en;
	vll dp(m+2,0);
	ll mx=0,ans=0;
	ind=0;
	fr(i,0,n){
		st=mm[arr[i].ff];
		en=mm[arr[i].ss];
		while(ind!=st){
			mx=max(mx,dp[ind]);
			ind++;
		}
		dp[en]=max(dp[en],mx+arr[i].p);
		ans=max(ans,dp[en]);
	}
	cout<<ans;
	return;
}
 
int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}