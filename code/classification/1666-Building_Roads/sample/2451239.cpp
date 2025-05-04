#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <math.h>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#include<ctime>
#include <chrono>
#pragma GCC optimize ("-O3")
using namespace std;
 
#define tolower(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define toupper(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define ll long long int
#define pii pair <ll , ll >
#define pb push_back
#define all(s) s.begin(),s.end()
ll gcd(ll a, ll b) { if (a == 0) return b; return b == 0 ? a : gcd(b, a % b);}
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cerr << '\n'; }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << "[ " << *it << " = " << a << " ]"; err(++it, args...);}
 
/**************************************************************************/
const int x4[] = {1, -1, 0, 0};
const int y4[] = {0, 0, 1, -1};
const int x8[] = {1, 1, 1, -1, -1, -1, 0, 0};
const int y8[] = {1, 0, -1, 1, 0, -1, 1, -1};
/***************************************************************************/
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775800;
const long double PI = 3.141592653589793;
const int PRECISION = 10;
/***************************************************************************/
const int DIGITSIZE = 18;
const int MAXN = 100001;
const int LOGN = 22;
const int MAXBIT = 62;
/***************************************************************************/
const bool take_test_case = 0;
const bool print_case_no = 0;
/****************************************************************************/
class DSU {
public:
    DSU(int n) {
        d_count = n;
        d_dsu.resize(n + 1);
        d_size.resize(n + 1, 0);
        for (int i = 0; i <= d_count; i++) {
            d_dsu[i] = i;
            d_size[i] = 1;
        }
    }
    int getRoot(int u) {
        while (d_dsu[u] != u) {
            d_dsu[u] = d_dsu[d_dsu[u]];
            u = d_dsu[u];
        }
        return u;
    }
    void combine(int u, int v) {
        int root_1 = getRoot(u);
        int root_2 = getRoot(v);
        if (root_1 == root_2) {
            return ;
        }
        if (d_size[root_1] > d_size[root_2]) {
            swap(root_1, root_2);
        }
        assert("combining on smaller component" && d_size[root_1] <= d_size[root_2]);
        d_size[root_1] += d_size[root_2];
        d_size[root_2] = 0;
        d_dsu[root_2] = d_dsu[root_1];
    }
    int getComponentSize(int u) {
        int root = getRoot(u);
        return d_size[root];
    }
    void debugComponent() {
        cout << "**DEBUG**" << '\n';
        for (int i = 1; i <= d_count; i++) {
            cout << "[" << i << " has root " << getRoot(i) << " and size = " << getComponentSize(i) << " ]\n";
        }
        cout << "--DEBUG--" << '\n';
    }
    int getNumberOfComponent() {
        return count_if(d_size.begin(), d_size.end(), [](int val) {
            return val > 0;
        }) - 1;
    }
private:
    int d_count;
    vector <int> d_dsu;
    vector <int> d_size;
};
 
 
void getac(int T) {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dsu.combine(x, y);
    }
    set < int> roots;
    for (int i = 1; i <= n; i++) {
        roots.insert(dsu.getRoot(i));
    }
    if (roots.size() == 1) {
        cout << 0 << '\n';
    } else {
        cout << roots.size() - 1;
        cout << '\n';
        auto a = roots.begin();
        auto it = a;
        it++;
        while (it != roots.end()) {
            cout << *a << ' ' << *it << '\n';
            it++;
        }
    }
}
int  main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cerr.tie(NULL);
    auto start_time = std::chrono::high_resolution_clock::now();
 
    int test_cases = 1;
    if (take_test_case) cin >> test_cases;
    for (int test_case_no = 1; test_case_no <= test_cases; test_case_no++) {
        if (print_case_no)
            cout << "Case #" << test_case_no << ": ";
        getac(test_case_no);
    }
    cerr << "Time elapsed " << chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    return 0;
}
 
 
 
