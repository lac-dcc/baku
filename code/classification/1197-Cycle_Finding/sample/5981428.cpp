#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ffr(i,j,k) for(int i=j;i<k;i++)
#define f(n) ffr(i,0,n)
#define f1(n) ffr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 200005;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int,int>,int>>v;
    f(m) {
        int x, y, z;
        cin >> x >> y >> z;
        z = -z;
        v.pb({{x,y},z});
    }
    //ll dp[n+1] = {};
    vector<ll> dp(n + 1, 0);
    //int fr[n + 1] = {};
    vector<int> fr(n + 1, 0);
    //memset(dp, 0xc4,sizeof(dp));
    dp.assign(dp.size(), 0xc4); 
    dp[1] = 0;
    vector<int>ch;
    for (int z = 0 ; z < n ; z++) {
        for (auto &i : v) {
            if (dp[i.F.F] + i.S > dp[i.F.S]) {
                dp[i.F.S] = dp[i.F.F] + i.S;
                fr[i.F.S] = i.F.F;
                if (z == n - 1) {
                    ch.pb(i.F.S);
                }
            }
        }
    }
    if (!ch.size()) {
        cout << "NO\n";
        return;
    }
    //memset(dp, 0xc4, sizeof(dp));
    dp.assign(dp.size(), 0xc4);
    for (auto &i : ch) {
        dp[i] = 1e12;
    }
    //memset(fr,0, sizeof(fr));
    fr.assign(fr.size(), 0);
    for (int z = 0 ; z < n ; z++) {
        for (auto &i : v) {
            if (dp[i.F.F] + i.S > dp[i.F.S]) {
                dp[i.F.S] = dp[i.F.F] + i.S;
                fr[i.F.S] = i.F.F;
            }
        }
    }
    /*cout << ch[0] << endl;
    f1(n) {
        cout << fr[i] << ' '; 
    }
    cout << '\n';*/
    cout << "YES\n";
    vector<int>ans{ch[0]};
    //int ex[n + 5] = {};
    vector<int> ex(n + 5, 0);
    ex[ch[0]] = 1;
    while (ans.size()== 1|| ans.back() != ans[0]) {
        ans.pb(fr[ans.back()]);
        if (ex[ans.back()]) {
            break;
        }
        ex[ans.back()] = 1;
    }
    reverse(all(ans));
    int cur = 0;
    for (auto &i : ans) {
        cout << i << ' ';
        if (cur && i == ans[0]) {
            break;
        }
        cur++;
    }
    cout << '\n';
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        solve();
    }
}
