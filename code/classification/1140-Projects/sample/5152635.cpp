#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x, y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
const int mod = 1000000007;
 
int startDate(vector<vector<int>>& v,int last){
	int l=0, r=last-1;
	int idx=-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(v[mid][1]<v[last][0]){
			idx=mid; l=mid+1;
		}
		else r=mid-1;
	}
	return idx;
}
 
inline void test_case(){
	int n; cin>>n;
	vector<vector<int>> v(n,vector<int>(3,0));
	for(int i=0;i<n;i++){
		cin>>v[i][0]>>v[i][1]>>v[i][2];
	}
	sort(v.begin(),v.end(),[&](vector<int> a,vector<int> b){
		if(a[1]==b[1]) return a[0]<b[0];
		return a[1]<b[1];
	});
	vector<ll> dp(n+1,0);
	dp[0]=0;
	dp[1]=v[0][2];
	for(int i=2;i<=n;i++){
		int idx=startDate(v,i-1);
		dp[i]=max(dp[i-1],v[i-1][2] + dp[idx+1]);
	}
	cout<<dp[n];
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    test_case();
    return 0;
}