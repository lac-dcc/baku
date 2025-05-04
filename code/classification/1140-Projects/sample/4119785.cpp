#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,tune=native")
#define mikumywaifu ios_base::sync_with_stdio(0)
#define mudrockmywaifu cin.tie(0)
#define pb push_back
#define ss second
#define ff first
#define mem(i,j) memset(i,j,sizeof(i))
#define pii pair<int,int>
#define pll pair<long,long>
#define lowbit(x) x&-x
const int INF =0x3F3F3F3F;
const ll LINF=4611686018426387903;
ll gcd(ll a,ll b){
    if(b==0) return a;
    a%=b;
    return gcd(b,a);
}
void debug(){
    cout<<"DEBUG :";
    cout<<"\n";
}
/*-----------------------------------------*/
struct nd{
	int a,b,c;
	friend bool operator<(nd x,nd y){
		return x.b<y.b;
	}
};
signed main(){
    mikumywaifu;
    mudrockmywaifu;
	int n;
	cin>>n;
	map<int,int> mp;
	set<int> s;
	vector<nd> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i].a>>arr[i].b>>arr[i].c;
		s.insert(arr[i].a);
		s.insert(arr[i].b);
	}
	int cnt=1;
	for(auto e:s){
		mp[e]=cnt++;
	}
	for(int i=0;i<n;i++){
		arr[i].a=mp[arr[i].a];
		arr[i].b=mp[arr[i].b];
	}
	vector<ll> dp(cnt+10);
	sort(arr.begin(),arr.end());
	int pre=1;
	for(int i=0;i<n;i++){
		while(pre<=arr[i].b){
			dp[pre]=max(dp[pre],dp[pre-1]);
			pre++;
		}
		dp[arr[i].b]=max(dp[arr[i].b],dp[arr[i].a-1]+arr[i].c);
	}
 
	cout<<dp[cnt-1]<<"\n";
}
