/*
    Author: Hi-TechMissile
    From: IIT Indore
 
    Written on 05-11-2023 at 12:12:12 IST
*/
 
#include <bits/stdc++.h>
#define yes() cout<<"YES\n"
#define no() cout<<"NO\n"
#define ne() cout<<"-1\n"
#define pb push_back
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define rf(i, b, a) for(int i = b; i >= a; i--)
#define all(v) v.begin(), v.end()
#define go(i, a) for(auto &i : a)
using ll = long long;
using ld = long double;
const int mod = 1e9 + 7;
const int MOD = 998244353;
const int N = 2e5;
const int inf = INT_MAX;
const ll INF = 5e18;
const ld ep = 1e-9;
using namespace std;
 
template <typename T>
void init(T* a, int size, const T val)
{
    fr(i, 0, size - 1)
        a[i] = val;
    return;
}
 
 
void solve()
{
    // Use ll iff sum or products (1e9) are involved.
    // Fenwick Tree is used to update and query
    // for values of an arbitrary array other than the tree itself.
    
    string s, t;
    cin>>s>>t;
 
    const int n = s.length(), m = t.length();
 
    int dp[n + 1][m + 1];
    dp[0][0] = 0;
 
    fr(i, 1, m)
        dp[0][i] = dp[0][i - 1] + 1;
    
    fr(i, 1, n)
        dp[i][0] = dp[i - 1][0] + 1;
 
    fr(i, 1, n)
        fr(j, 1, m)
        {
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    
    // fr(i, 0, n)
    // {
    //     fr(j, 0, m)
    //         cout<<dp[i][j]<<" ";
    //     cout<<"\n";
    // }
    
    cout<<dp[n][m]<<"\n";
}
 
 
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);
    clock_t t0 = clock();
 
    #ifndef ONLINE_JUDGE
        freopen("haybales.in", "r", stdin);
        freopen("haybales.out", "w", stdout);
    #endif
 
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
 
    double dt = double(clock() - t0) * 1000.0 / double(CLOCKS_PER_SEC);
    #ifndef ONLINE_JUDGE
        cout<<"Consumed "<<fixed<<setprecision(5)<<dt<<" ms.";
    #endif
 
 
    return 0;
}
