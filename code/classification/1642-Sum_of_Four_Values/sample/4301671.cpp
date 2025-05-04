#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int, int>
 
bool pairSum(vector<pii>&a, int start, int end, int target) {
	
	while(start < end) {
		
		int sum = a[start].first + a[end].first;
		
		if(sum == target)
		{
			cout << a[start].second << ' ' << a[end].second << ' ';
			return true;
		}
		
		if(sum < target) {
			start++;
		} else {
			end--;
		}
	}
	
	return false;
}
 
bool kSum(vector<pii> &a, int start, int end, int target, int k) {
	
	if(end - start + 1 < k || start > end) {
		return false;
	}
	
	if(k == 2) {
		return pairSum(a, start, end, target);
	}
	
	for(int i = start; i <= end; ++i) {
		bool done = kSum(a, i + 1, end, target - a[i].first, k - 1);
		if(done) {
			cout << a[i].second << ' ';
			return true;
		}
	}
	
	return false;
}
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    
	int n; cin >> n;
	int target; cin >> target;
	
	vector<pii> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
		
	sort(a.begin(), a.end());
	
	bool done = kSum(a, 0, n - 1, target, 4);
	
	if(!done) cout << "IMPOSSIBLE";
}