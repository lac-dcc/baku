#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;
 
typedef long long ll;
 
ll cross_sum (vector<ll> v, int start, int end) {
    int mid = (start + end) / 2;
    ll sum_l = INT_MIN, sum_r = INT_MIN, temp = 0;
    for (int i = mid; i >= start; --i) {
        temp += v[i];
        sum_l = max (temp, sum_l);
    }
    temp = 0;
    for (int i = mid + 1; i <= end; ++i) {
        temp += v[i];
        sum_r = max (temp, sum_r);
    }
    return max ({sum_r + sum_l, sum_l, sum_r});
}
 
 
ll max_sub (vector<ll> v, int start, int end) {
    if (start == end) {
        return v[start];
    }
    
    int mid = (start + end) / 2;
    ll left = max_sub (v, start, mid);
    ll right = max_sub (v, mid + 1, end);
    ll cross = cross_sum (v,start,end);
 
    return max ({left, right, cross});
}
 
int main () {
    int n, x;
    cin >> n;
    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v.push_back(x);
    }
    ll max_sum = INT_MIN, max_end = 0;
    for (int i = 0; i < n; ++i) {
        max_end = max_end + v[i];
        if (max_sum < max_end)
            max_sum = max_end;
        if (max_end < 0) 
            max_end = 0;
    }
    cout << max_sum << endl;
}