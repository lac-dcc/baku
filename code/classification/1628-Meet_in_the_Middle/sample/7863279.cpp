#include<bits/stdc++.h>
using namespace std;
 
long long n, x;
long long a[50];
 
 
void solve() {
	cin >> n >> x;
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vector<long long>v1, v2, sum1, sum2;
	for (long long i = 0; i < n / 2; ++i)
	{
		v1.push_back(a[i]);
	}
	for (long long i = n / 2; i < n; ++i)
	{
		v2.push_back(a[i]);
	}
 
	for (long long i = 0; i < (1 << v1.size()); ++i)
	{
		long long sum = 0;
		for (long long j = 0; j < v1.size(); j++) {
			if ((1 << j)&i) {
				sum += v1[j];
			}
		}
		sum1.push_back(sum);
	}
	for (long long i = 0; i < (1 << v2.size()); ++i)
	{
		long long sum = 0;
		for (long long j = 0; j < v2.size(); j++) {
			if ((1 << j)&i) {
				sum += v2[j];
			}
		}
		sum2.push_back(sum);
	}
	sort(sum1.rbegin(), sum1.rend());
	sort(sum2.begin(), sum2.end());
 
	long long ans = 0;
	for (auto it : sum1) {
		long long pos = lower_bound(sum2.begin(), sum2.end(), x - it) - sum2.begin();;
		long long y = upper_bound(sum2.begin(), sum2.end(), x - it) - sum2.begin();
		if (y - pos > 0)ans += y - pos;
	}
	cout << ans << endl;
 
 
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}
