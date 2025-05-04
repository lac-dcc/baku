#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <stack>
#include <numeric>
#include <map>
 
#define MP make_pair
#define PB push_back
#define PPB pop_back
#define FOR(i, s, n) for (int i = s; i <= n; i++)
#define UP(i, n) for (int i = 0; i < n; i++)
#define DOWN(i, n) for (int i = n-1; i >= 0; i--)
#define AUTO(i, v) for (auto i : v)
#define print(i) cout << (i) << '\n'
#define LB lower_bound
#define UB upper_bound
#define endl '\n'
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
 
 
template<typename T>
void Print(T v)
{
    AUTO(i, v) cout << i << (" ");
    cout << endl;
}
 
int INF = 1000000007;
ll LINF = 1000000000000000000;
 
 
int main()
{
    int n, k; cin >> n >> k;
    vector<pii> v(n);
    UP(i, n) cin >> v[i].F >> v[i].S;
    sort(v.begin(), v.end());
    multiset<int> right; right.insert(INF);
    int l; int count = 0;
    UP(i, n)
    {
        l = v[i].F;
        while (*right.begin() <= l) right.erase(right.begin());
        if (right.size() < k+1)
        {
            count++;
            right.insert(v[i].S);
            continue;
        }
        if (right.size() > 1)
        {
            auto it = right.end(); it--; it--;
            if (*(it) > v[i].S)
            {
                right.erase(it);
                right.insert(v[i].S);
            }
        }
    }
    print(count);
}
 
