/*
Problem Name: Sum of Four Values
Problem Link: https://cses.fi/problemset/task/1641
Author: sidsabh
*/
#include <iostream>
#include <algorithm>
#include <map>
 
using namespace std;
 
const int MAX_N = 5000;
int arr[MAX_N];
int n, target;
 
void foursum() {
    map<int, pair<int, int>> mp;
 
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            auto curr = arr[i] + arr[j];
 
            if (mp.count(target - curr)) {
                cout << mp[target - curr].first + 1 << " " << mp[target - curr].second + 1 
                    << " " << i + 1 << " " << j + 1;
                exit(0);
            }
 
        }
 
        for (int j = i - 1; j >= 0; j--) mp[arr[i] + arr[j]] = {i, j};
    }
}
 
void solve() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    foursum();
    cout << "IMPOSSIBLE" << '\n';
}
 
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
