#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vdb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
typedef set<int> si;
typedef set<long long> sl;
typedef set<double> sdb;
typedef set<string> ss;
typedef set<char> sc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define ftb(i, a, b) for (int i = a, _b = b; i <= _b; i++)
#define ft(i, a, b) for (int i = a, _b = b; i < _b; i++)
#define fgb(i, a, b) for (int i = a, _b = b; i >= _b; i--)
#define fg(i, a, b) for (int i = a, _b = b; i > _b; i--)
#define endl "\n"
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<int, int> d;
    ft(i,0,n){
        int x, y;
        cin >> x >> y;
        d[x] += 1;
        d[y] -= 1;
    }
    int ans = 0;
    int sum = 0;
    for(auto it:d){
        sum += it.second;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
