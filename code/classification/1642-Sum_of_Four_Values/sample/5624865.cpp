#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <algorithm>
#include <streambuf>
#include <exception>
#include <iostream>
#include <typeinfo>
#include <valarray>
#include <iterator>
#include <ostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <climits>
#include <iomanip>
#include <istream>
#include <fstream>
#include <utility>
#include <locale>
#include <string>
#include <iosfwd>
#include <memory>
#include <bitset>
#include <vector>
#include <limits>
#include <queue>
#include <cmath>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <new>
 
#define      NAME   ""
#define        ll   long long int
#define       pll   pair <ll, ll>
#define       pii   pair <int, int>
#define        fi   first
#define        se   second
 
using namespace std;
 
bool maxim (int &a, int b) {
    if (a < b)
        return a = b, true;
    return false;
}
 
bool minim (int &a, int b) {
    if (a > b)
        return a = b, true;
    return false;
}
 
map <ll, vector<pii>> id;
int n, H[1002];
ll X, Y;
 
bool ok (int i, int j, pair <int, int> p) {
    return (i != j) && (i != p.fi) && (i != p.se) && (j != p.fi) && (j != p.se);
}
 
signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if (fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> X;
    for (int i = 1; i <= n; i++)
        cin >> H[i];
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            id[1LL * (H[i] + H[j])].push_back(pii(i, j));
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            Y = X - H[i] - H[j];
            if (id[Y].size()) {
                for (pii k : id[Y])
                    if (ok(i, j, k))
                        return cout << i << " " << j << " " << k.fi << " " << k.se, 0;
            }
        }
    cout << "IMPOSSIBLE";
    return 0;
}