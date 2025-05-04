#include <iostream>
#include <stdio.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
#include <unordered_set>
#include <climits>
#include <utility>
#include <iterator>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
 
 
int d_x[] = { 0, 1, 0, -1 , -1, -1, 1, 1 };
int d_y[] = { 1, 0, -1, 0 , 1, -1, -1, 1 };
 
 
//int k_x[8] = {1, 2, -1, -2, 1, 2, -1, -2};
//int k_y[8] = {2, 1, 2, 1, -2, -1, -2, -1};
 
 
 
 
 
 
 
int main() {
 
    cin.tie(0); cin.sync_with_stdio(0);
 
    //freopen("helpcross.in", "r", stdin);
    //freopen("helpcross.out", "w", stdout);
 
 
 
    ll n, k;
    cin >> n >> k;
 
    vector<ll> temp(k);
    for (int i = 0; i < k; i++) { cin >> temp[i]; }
 
    ll total = 0;
 
    for (int i = 1; i < (1 << k); i++) {
        ll curr = n;
        int divisors = 0;
        for (int j = 0; j < k; j++) {
            if ((1 << j) & i) {
                curr /= temp[j];
                ++divisors;
            }
        }
        if (divisors % 2 == 0) {
            total -= curr;
        }
        else {
            total += curr;
        }
    }
 
    cout << total << "\n";
 
 
 
 
 
 
}
