#include <bits/stdc++.h>
 
 
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define MAX_int 2,147,483,646
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef vector<pii> vpii;
typedef set<int> si;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vi> vvi;
 
int n, x;
 
int main() {
    cin >> n >> x;
    vi c(n);
    vi dp(x+1, -1);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    dp[0] = 0;
    for (int i = 1; i <=x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= c[j]) {
                if (dp[i-c[j]]!= -1) {
                    if (dp[i] != -1) {
                        dp[i] = min(dp[i-c[j]]+1, dp[i]);
                    } else {
                        dp[i] = dp[i-c[j]]+1;
                    }
                }
            }
        }
    }
    cout << dp[x];
 
}