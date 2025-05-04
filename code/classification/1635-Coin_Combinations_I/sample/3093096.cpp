#include<iostream>
#include<algorithm>
using namespace std;
const long long du=1000000007;
int a[101];
long long dp[1000001];
int n, k;
long long coin(long long x){
	if (dp[x]!=-1)return dp[x];
	else if (x==0)return dp[x]=1%du;
	else {
		long long t=0;
		for (int i=0;i<n;i++){
			if (x>=a[i]){
				t=t+coin(x-a[i]);
				t=t%du;
			}
			else break;
		}
		return dp[x]=t;
	}
}
void solve(){
	cin>>n>>k;
	for (int i=0;i<n;i++)cin>>a[i];
	for (int i=0;i<1000001;i++)dp[i]=-1;
	sort(a,a+n);
	cout<<coin(k)%du;
}
int main(){
	solve();
}