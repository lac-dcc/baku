#include <bits/stdc++.h>
#include <time.h>
using namespace std;
 
#define sz(x) ((int)(x).size())
#define pb push_back
#define vec vector
#define fi first
#define se second
#define ends "\n"
#define sp ' '
#define fun function
#define ar(x) array<int, x>
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
 
const long long MOD=1e9+7; 
 
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) { cerr << to_string(h); if(sizeof...(t)) cerr << ", "; DBG(t...); }
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
 
int MOD_SUM(long long s1, long long s2){
    return ((s1) + (s2)) % MOD;
}
 
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);
 	  
    int n, sum;
    cin >> n >> sum;
 
    vec<ll> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
 
    vec<ll> dp(sum + 1);
    dp[0] = 1;
 
    for(int s = 1; s <= sum; ++s){
        for(auto x : a)
            if(s - x >= 0)  
                dp[s] = MOD_SUM(dp[s], dp[s - x]); 
    }
    cout << dp[sum] << ends;
 	
}
