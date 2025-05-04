#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 200000, M = 1 << 18;
 
long long sum[M * 2], arr[M * 2], maxSuffixSum[M * 2], maxPrefixSum[M * 2],seg[M*2];
void init(int k, int x) {
    sum[k] = x;
    seg[k] = maxPrefixSum[k] = maxSuffixSum[k] = max(x, 0);
}
 
void pull(int k, int k1, int k2) {
    sum[k] = sum[k1] + sum[k2];
    maxPrefixSum[k] = max(maxPrefixSum[k1], sum[k1] + maxPrefixSum[k2]);
    maxSuffixSum[k] = max(maxSuffixSum[k2], sum[k2] + maxSuffixSum[k1]);
    seg[k] = max(max(seg[k1], seg[k2]), maxSuffixSum[k1] + maxPrefixSum[k2]);
}
 
void update(int k, int l, int r, int i, int x) {
    if (r - l == 1)
        init(k, x);
    else {
        int m = (l + r) / 2, k1 = k * 2 + 1, k2 = k * 2 + 2;
        if (i < m)
            update(k1, l, m, i, x);
        else
            update(k2, m, r, i, x);
        pull(k, k1, k2);
    }
}
 
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		update(0,0,n,i,arr[i]);
	}
	while(m--){
		int a;
		int b;
		cin>>a>>b;
		update(0,0,n,a-1,b);
		cout<<max(0ll,seg[0])<<endl;
	}
}
 
signed main() {
	int t=1;
	// cin>>t;
	while(t--){
		solve();
	}
}
 
 
