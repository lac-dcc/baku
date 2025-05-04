#include "bits/stdc++.h"
using namespace std;
#define int long long
 
void calc(vector<int> &a, vector<int> &nums, int l, int r, int ind, int curr) {
    if (ind > r) {
        nums.push_back(curr);
        return;
    }
 
    calc(a, nums, l, r, ind + 1, curr + a[ind]);
    calc(a, nums, l, r, ind + 1, curr);
}
 
vector<int> getSum(vector<int> &a, int l, int r) {
    vector<int> nums;
    calc(a, nums, l, r, l, 0);
    return nums;
}
 
void test_case() {
    int n, target;
    cin >> n >> target;
 
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    vector<int> leftHalf = getSum(a, 0, n / 2);
    // all possible subset sums of left half
 
    vector<int> rightHalf = getSum(a, n / 2 + 1, n - 1);
    // all possible subset sums of right half
 
 
    sort(leftHalf.begin(), leftHalf.end());
    sort(rightHalf.begin(), rightHalf.end());
 
    int res = 0;
    for (int &x : leftHalf) {
        int y = target - x;
        int low = lower_bound(rightHalf.begin(), rightHalf.end(), y)
                  - rightHalf.begin();
        int high = upper_bound(rightHalf.begin(), rightHalf.end(), y)
                   - rightHalf.begin();
 
        res += (high - low);
    }
 
    cout << res << "\n";
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    test_case();
    return 0;
}
