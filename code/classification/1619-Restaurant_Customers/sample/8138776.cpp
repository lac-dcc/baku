#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, a, b) for (ll i = b-1; i >= a; i--)
#define fa(ele, x) for (auto ele : x)
#define sorta(v,n) sort(v,v+n)
#define sortv(v) sort(v.begin(),v.end())
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define sei set<int>
#define sel set<ll>
#define mii map<int, int>
#define mll map<ll, ll>
#define mipii map<int, pair<int, int>>
#define mic map<int, char>
#define qi queue<int>
#define ql queue<ll>
#define qpii queue<pair<int, int>>
const ll mod = 1e9 + 7;
const ll INF = LONG_LONG_MAX;
const ll N = 1e5 + 5;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(0);
ll n,a,b;
cin>>n;
vl s2,v;
f(i,0,n){
	cin>>a>>b;
	v.PB(a);
	s2.PB(b);
}
sortv(v);
sortv(s2);
ll ans = 0;
ll best = 0;
f(i,0,n){
	ans++;
	auto h = upper_bound(s2.begin(),s2.end(),v[i]) - s2.begin();
	best = max(best,ans-h);
}
cout<<best<<endl;
return 0;
}
