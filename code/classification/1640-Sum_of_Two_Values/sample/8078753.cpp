#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n,x;
    cin >> n >> x;
 
    vector<pair<int, int>>arr;
 
    for ( int i = 1; i <= n; ++i){
       int a;
       cin >> a;
       arr.push_back({a,i});
    }
 
    sort(arr.begin(), arr.end());
 
    int left = 0;
    int right = n - 1;
 
    while ( left <right){
        int sum = arr[left].first + arr[right].first;
 
        if ( sum == x){
            cout << arr[left].second << " " << arr[right].second << "\n";
            return 0;
        } else {
            if ( sum < x){
                left++;
            } else {
                right--;
            }
        }
    }
 
    cout << "IMPOSSIBLE" << "\n";
return 0;
}
