#include <bits/stdc++.h>
using namespace std;
 
int n, x, a;
vector<pair<int,int>> nums;
 
int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a;
        nums.emplace_back(a, i + 1);
    }
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1;
    while(l < r){
        if(nums[l].first + nums[r].first == x) break;
        if(nums[l].first + nums[r].first > x) r--;
        else l++;
    }
    if(l < r ) cout << nums[l].second << ' ' << nums[r].second;
    else    cout << "IMPOSSIBLE";
}