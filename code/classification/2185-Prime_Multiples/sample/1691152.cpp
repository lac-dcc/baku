#include <bits/stdc++.h>
using namespace std;
 
long long gcd(long long a, long long b) {
	if(b == 0)
		return a;
	return gcd(b, a % b);
}
 
long long lcm(long long a, long long b, long long n) {
	long long g = gcd(a, b);
	if(n / a < b / g)
		return n + 1;
 
	return (a / g) * b;
}
 
int main() {
	long long n, k;
	cin >> n >> k;
 
	vector<long long> vec(k);
	for(int i = 0; i < k; ++i)
		cin >> vec[i];
	
	long long ans = 0;
 	
	vector<long long> l_vec(1 << k, 1);
	vector<int> sign(1 << k, -1);
 
	for(long long i = 0; i < k; ++i) 
		for(long long j = 0, l = (1 << i); j < (1 << i); ++j, ++l) {
			sign[l] = -sign[j];
			l_vec[l] = lcm(l_vec[j], vec[i], n);
 
			ans += sign[l] * (n / l_vec[l]);
		}
 
 
	cout << ans << "\n";
 
}