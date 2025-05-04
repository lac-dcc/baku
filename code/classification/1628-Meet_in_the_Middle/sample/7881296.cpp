#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl '\n'
#define ld long double
#define pii pair<int, int>
#define pin pair<int,pair<int, int>>
#define F first
#define S second
#define ll long long
 
 
const int N=41;
int a[N];
int X,n;
int cnt;
vector<int>A={};
vector<int>B={};
map<int,int>mp;
 
void sol(int i, int high, int sum, int x){
	if(i==high){
		if(x==0)A.pb(sum);
		if(x==1)B.pb(sum);
		return;
	}
	int tsum=sum+a[i];
	sol(i+1,high,tsum,x);
	sol(i+1,high,sum,x);
}
 
 
 
void solve(){
	cnt=0;
	cin>>n>>X;
	for(int i=0;i<n;i++) cin>>a[i];
	int mid=n/2;
	sol(0,mid,0,0);
	sol(mid,n,0,1);
	sort(B.begin(),B.end());
	for(int i=0;i<A.size();i++){
		int x=X-A[i];
		auto first=lower_bound(B.begin(),B.end(),x);
		auto last=upper_bound(B.begin(),B.end(),x);
 
			cnt+=(last-first);
	}
	
	cout<<cnt<<endl;
	
}
 
 
 
 
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
//	cin >> t;
    while(t--){
    	solve();
    }
}
