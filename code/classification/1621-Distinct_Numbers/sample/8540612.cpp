#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int mod = 1e9+7;
 
int main(){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(auto &it:nums)cin >> it;
    sort(nums.begin(), nums.end());
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(nums[i-1]!=nums[i])cnt++;
    }
    cout << cnt << "\n";
}
