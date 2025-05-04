#include <bits/stdc++.h>
#define pp pair<int, int>
using namespace std;
 
int main(){
    int n, x; cin >> n >> x;
    vector<pp> nums(n);
    for(int i=0; i<n; i++)cin >> nums[i].first, nums[i].second=i+1;
 
    sort(nums.begin(), nums.end());
    int p1=0, p2=n-1;
    while(p1<p2){
        int temp = nums[p1].first+nums[p2].first;
 
        if(temp==x)return cout << nums[p1].second<<' '<<nums[p2].second<<'\n', 0;
        else if(temp<x)p1++;
        else p2--;
    }
    cout << "IMPOSSIBLE" << '\n';
}