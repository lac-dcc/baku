#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
#define vi vector<ll> 
#define ii pair<int, int>
#define pb push_back
#define f first
#define s second
#define all(i) (i).begin(), (i).end()
 
// int main() {
// 	ll n, x;
// 	cin>>n>>x;
 
// 	vi nums(n);
 
// 	rep(i, 0, n) {
// 		cin>>nums[i];
// 	}
 
// 	auto generate = [&](int l, int r) -> vector<ll> {
// 		ll len = (r - l) + 1;
// 		vi l1;
// 		rep(i, 0, 1<<len) {
// 			ll sum = 0;
// 			rep(j, 0, len) {
// 				if((1<<j) & i) {
// 					sum += nums[j + l];
// 				}
// 			}
// 			l1.pb(sum);
// 		}
// 		return l1;
// 	};
 
// 	//Generate the subsets of both the arrays, i.e. dividing the original array into two parts.
// 	int l = 0;
// 	int r = (n-1)/2;
// 	vi part1 = generate(l, r);
// 	vi part2 = generate(r+1, n-1);
 
// 	// rep(i, 0, part1.size()) {
// 	// 	cout<<part1[i]<<" ";
// 	// }
 
// 	// cout<<endl;
// 	// rep(i, 0, part2.size()) {
// 	// 	cout<<part2[i]<<" ";
// 	// }
// 	// cout<<endl;
 
 
// 	sort(all(part1));
// 	sort(all(part2));
 
// 	ll res = 0;
 
// 	for(ll i : part1) {
// 		int lower = lower_bound(all(part2), x - i) - part2.begin();
// 		int upper = upper_bound(all(part2), x - i) - part2.begin();
 
// 		res += upper - lower;
// 	}
 
// 	cout<<res<<endl;
// }
 
int main() {
	int n, x;
	cin>>n>>x;
 
	vi nums(n);
	rep(i, 0, n) {
		cin>>nums[i];
	}
 
	vector<ll> part1;
	vector<ll> part2;
 
	auto generate = [&](int l, int r) {
		int len = (r-l)+1;
		vector<ll> arr;
		for(int i = 0; i < 1<<len; i++) {
			ll sum = 0;
			for(int j = 0; j < len; j++) {
				if(i & (1<<j)) {
					sum += nums[l+j];
				}
			}
			arr.pb(sum);
		}
 
		return arr;
	};
 
	part1 = generate(0, (n-1)/2);
	part2 = generate((n-1)/2 + 1, n-1);
 
	// rep(i, 0, part1.size()) {
	// 	cout<<part1[i]<<" ";
	// }
 
	// cout<<endl;
	// rep(i, 0, part2.size()) {
	// 	cout<<part2[i]<<" ";
	// }
 
	sort(all(part1));
	sort(all(part2));
 
	ll result = 0;
	for(ll i : part1) {
		int l = lower_bound(all(part2), x-i) - part2.begin();
		int r = upper_bound(all(part2), x-i) - part2.begin();
		result += r - l;
	}
 
	cout<<result<<endl;
}
