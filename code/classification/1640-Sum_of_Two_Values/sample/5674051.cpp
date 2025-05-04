#define _CRT_SECURE_NO_WARNINGS
 
#include <bits/stdc++.h>
 
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <stack>
#include <cstdio>
#include <climits>
#include <tuple>
#include <ctime>
#include <cstring>
#include <numeric>
#include <functional>
#include <chrono>
#include <cassert>
#include <bitset>
#include <fstream>
 
#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vr(v) v.begin(),v.end()
#define rv(v) v.rbegin(),v.rend()
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Davit cout.tie(NULL);
 
using namespace std;
using str = string;
const ll mod = 1e9 + 7;
const int INF = 1e9;
// printf("%.9f\n", x);
//cout << fixed<<setprecision(n);
 
//mt19937 mt(time(nullptr));
//__builtin_clz(x): the number of zeros at the beginning of the number
//__builtin_ctz(x): the number of zeros at the end of the number
//__builtin_popcount(x): the number of 1s
 
 
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    vector<int> idx;
    for (int i = 0; i < n; i++)idx.pb(i + 1);
    sort(vr(idx), [&](int a, int b) {
        return v[a - 1] < v[b - 1];
    });
    sort(vr(v));
//    for (int i = 0; i < n; i++)cout << idx[i] << " ";
    int l = 0, r = n - 1;
    while (l < r) {
        int cur = v[l] + v[r];
        if (cur == x) {
            cout << idx[l] << " " << idx[r] << endl;
            return 0;
        }
        if (cur < x)l++;
        if (cur > x)r--;
    }
    cout << "IMPOSSIBLE\n";
}