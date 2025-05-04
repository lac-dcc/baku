// Faster
#pragma GCC optimize("Ofast") 
//#pragma GCC target("fma")
 
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <array>
#include <numeric>
#include <map>
#include <deque>
 
using namespace std;
 
const int mxN = 2e5;
array<int, 3> arr[mxN];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, k;
    cin >> n >> k;
    
 
    for (int i = 0; i < n; i++) {
        cin >> arr[i][1] >> arr[i][0];
        arr[i][2] = i;
    }
    sort(arr, arr + n);
    set <array<int, 2>> ans;
    int sol = 0;
    for (int i = 0; i < n; i++) {
        auto pos = ans.lower_bound({ arr[i][1] + 1 });
        if (pos != ans.begin()) {
            --pos;
            ans.erase(pos);
        }
        if (ans.size() < k) {
            ++sol;
            ans.insert({ arr[i][0], i });
        }
    }
    cout << sol;
 
 
 
  
 
}
