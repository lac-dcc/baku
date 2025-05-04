#include <bits/stdc++.h>
#define pb push_back
#define endl '\n'
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O0")
#pragma GCC optimize("O1")
using namespace std;
typedef long long ll;
 
int n;
map<int, int> cnt;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cnt[a]++;
        cnt[b + 1]--;
    }
    int num = 0, res = 0;
    for (auto x : cnt) {
        num += x.second;
        res = max(res, num);
    }
    cout << res;
}
