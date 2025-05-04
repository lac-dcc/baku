#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef pair<int, int> point;
const int N = 1e7 + 5;
int cnt[N];
 
int main() {
  fastIO;
  int n;
  cin >> n;
  vector<point> v(n);
  vector<int> a;
  for (auto &[x, y] : v) cin >> x >> y;
  for (auto [x, y] : v) {
    a.pb(x);
    a.pb(y);
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
 
  for (auto [x, y] : v) {
    // cout << x << " " << y << " --> ";
    int id = lower_bound(all(a), x) - a.begin();
    // cout << id << " ";
    cnt[id]++;
    id = lower_bound(all(a), y) - a.begin();
    // cout << id << endl;
    cnt[id + 1]--;
  }
  int ans = -1;
  for (int i = 1; i < N; i++) {
    cnt[i] += cnt[i - 1];
  }
  for (int i = 1; i < N; i++) {
    ans = max(ans, cnt[i]);
  }
  cout << ans << endl;
}
