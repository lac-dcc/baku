#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int32_t main(){
	ios_base::sync_with_stdio(false);
	int n, x; cin >> n >> x;
	
	vector<int> nums(n);
	set<int> pairsums;
	
	for(int i = 0; i< n; i++) cin >> nums[i];
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int rem = x - nums[i] - nums[j];
			if(pairsums.count(rem) != 0){
				for(int k = 0; k < n; k++){
					if(k == i || k == j) continue;
					for(int l = 0; l < n; l++){
						if(l == i || l == j || k == l) continue;
						if(nums[i] + nums[j] + nums[k] + nums[l] == x){
							cout << i+1 << " " << j+1 << " " << k+1 << " " << l+1 << endl;
							return 0;
						}
					}
				}
			}
		}
		
		for(int j = 0; j < i; j++){
			pairsums.insert(nums[i]+nums[j]);
		}	
	}
	
	cout << "IMPOSSIBLE" << endl;
	
	return 0;
}
