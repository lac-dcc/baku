#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define double long double
#define endl '\n'
 
const int MOD = 1000000007;
 
void findSums(const vector<int>& subset, unordered_map<int, int>& sums) {
    int subsetSize = subset.size();
    
    for (int mask = 0; mask < (1 << subsetSize); ++mask) {
        int sum = 0;
        for (int i = 0; i < subsetSize; ++i) {
            if (mask & (1 << i)) {
                sum += subset[i];
            }
        }
        sums[sum]++;
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
 
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    int mid = n / 2;
    
    vector<int> firstHalf(nums.begin(), nums.begin() + mid);
    vector<int> secondHalf(nums.begin() + mid, nums.end());
 
    unordered_map<int, int> firstHalfSums;
    unordered_map<int, int> secondHalfSums;
 
    // Reserve space to avoid rehashing
    firstHalfSums.reserve(1 << mid);
    secondHalfSums.reserve(1 << (n - mid));
 
    // Find sums for first half
    findSums(firstHalf, firstHalfSums);
 
    // Find sums for second half
    findSums(secondHalf, secondHalfSums);
    
    int totalCount = 0;
    for (auto& kv : firstHalfSums) {
        int remainingSum = x - kv.first;
        if (secondHalfSums.count(remainingSum)) {
            totalCount += kv.second * secondHalfSums[remainingSum];
        }
    }
 
    cout << totalCount << endl;
    
    return 0;
}
