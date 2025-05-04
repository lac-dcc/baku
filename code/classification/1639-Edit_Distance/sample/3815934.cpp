#include <bits/stdc++.h>
 
using namespace std;
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
 
 
// int dp[5001][5001];
 
// int f(string s1, string s2, int i1, int i2)
// {
//     if(dp[i1][i2]!=-1)
//     return dp[i1][i2];
 
//     if(i1==s1.length())
//     return (s2.length()-i2);
//     if(i2==s2.length())
//     return (s1.length()-i1);
 
 
 
 
//     if(s1[i1]==s2[i2])
//     {
//         if(dp[i1+1][i2+1]!=-1)
//         {
//             dp[i1][i2]=dp[i1+1][i2+1];
//             return dp[i1][i2];
//         }
//         dp[i1+1][i2+1] = f(s1,s2,i1+1,i2+1);
//         dp[i1][i2]=dp[i1+1][i2+1];
//         return dp[i1][i2];
//     }
   
//     if(dp[i1+1][i2]==-1)
//     dp[i1+1][i2] = f(s1,s2,i1+1,i2);
//     if(dp[i1][i2+1]==-1)
//     dp[i1][i2+1] = f(s1,s2,i1,i2+1);
//     if(dp[i1+1][i2+1]==-1)
//     dp[i1+1][i2+1] = f(s1,s2,i1+1,i2+1);
 
//     int m = min(dp[i1+1][i2],dp[i1][i2+1]);
//     m = min(m,dp[i1+1][i2+1]);
 
 
//     dp[i1][i2]=1+m;
//     return dp[i1][i2];
 
// }
int dp[5005][5005]={};
int f(string s1, string s2)
{
    for(int i=0; i<=s1.length(); i++)
    {
        dp[i][0] = i;
    }
    for(int j=0; j<=s2.length(); j++)
    {
        dp[0][j] = j;
    }
 
    for(int i=1; i<=s1.length(); i++)
    {
        for(int j=1; j<=s2.length(); j++)
        {
            dp[i][j] = INT_MAX;
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
            }
            else dp[i][j] = min(dp[i][j],1+dp[i-1][j-1]);
            dp[i][j] = min(dp[i][j],min(1+dp[i-1][j],1+dp[i][j-1]));
        }
    }
    return dp[s1.length()][s2.length()];
}
 
void solve() {
    
    string s1,s2;
    cin>>s1>>s2;
    
    cout<<f(s1,s2);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}