// Created by Nandu Vinodan
#include <bits/stdc++.h>
 
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define vi vector<int>
#define pi pair<int, int>
#define INF INT_MAX
#define _INF INT_MIN
#define TC 0
 
using namespace std;
using ll = long long;
 
void testcase() {
    int n; cin >> n;
    vector<pair<pair<int, int>, ll> > v(n);
 
    for (int i=0; i<n; i++) {
        int s, e; ll p;
        cin >> s >> e >> p;
 
        v[i] = {{e, s}, p};
    }
 
    sort(v.begin(), v.end());
 
    vector<int> x(n, -1);
    for (int i=1; i<n; i++) {
        pair<pair<int, int>, ll> p = {{v[i].first.second,0}, 0}; //{{v[i].first.second,0}, 0LL}
        auto it = lower_bound(v.begin(), v.end(), p);
        x[i] = it - v.begin() - 1;
    }
 
    ll dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = v[0].second;
    for (int i=1; i<n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        int s = x[i];
        if (s >= 0)
            dp[i][1] = max(dp[s][0], dp[s][1]) + v[i].second;
        else
            dp[i][1] = v[i].second;
    }
    cout << max(dp[n-1][0], dp[n-1][1]);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    if (TC)
        cin>>t;
    while(t--) {
        testcase();
    }
    return 0;
}
