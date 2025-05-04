#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <tuple>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <any>
 
 
#include <bits/stdc++.h>
using num = int64_t;
 
using namespace std;
 
#ifdef LOCAL
#define eprintf(...)                  \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    }
#else
#define eprintf(...) 42
#endif
 
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
int MOD = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B)
{
    return (ull)rng() % B;
}
 
 
#define pb push_back
#define REPL(x, n) for(int x = 0; x < n; ++x)
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define print(x) cout << x << endl;
#define nl "\n"
 
 
clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
 
void printiv(vector<ll> v) {
    for (int ele : v) {
        cout << ele << " ";
    }
    cout << endl;
}
 
 
bool compare(pair<int, int> p, pair<int,int> q) {
    return p.first < p.second;
}
 
int n, m;
bool visited[1000][1000]; 
int h[] = {-1, 1, 0, 0};
int v[] = {0, 0, -1, 1};
 
 
 
void dfs(int x, int y) {
    visited[x][y] = true;
 
    int dx, dy;
 
    REPL(i, 4) {
        dx = h[i] + x;
        dy = v[i] + y;
 
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy]) {
            dfs(dx, dy);
        }
    }
}
 
int main() {
    char c;
    //ofstream cout("test.out");
    int count = 0;
    cin >> n >> m;
 
    for(int i  = 0; i < n; ++i) {
        REPL(j, m) {
            cin >> c;
            visited[i][j] = (c == '#');
        }
    }
 
    REPL(i , n) {
        REPL(j, m) {
            if (!visited[i][j]) {
                dfs(i, j);
                count++; 
            }
        }
    }
 
    cout << count << nl;
    return 0;
}
