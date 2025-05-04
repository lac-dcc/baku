#include <bits/stdc++.h>
#pragma GCC optimize(3)
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define endl '\n'
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
 
double startTime = clock();
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
 
void solve(){
    int n; cin >> n;
    map<int, int> mp;
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        mp[x]++;
        mp[y]--;
    }
    int cnt = 0, ans = 0;
    for(auto [p, q] : mp){
        cnt += q;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    int t = 1;
    //cin >> t;
    while(t--)
    solve();
 
    return 0;
}
