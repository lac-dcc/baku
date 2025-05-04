#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(),x.end()
#define ar array
template <class T,class S> inline bool chmin(T &a,const S &b) {return (a> b? a= b, 1: 0);}
template <class T,class S> inline bool chmax(T &a,const S &b) {return (a< b? a= b, 1: 0);}
const int mxn = 5005;
int dp[mxn][mxn];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    string a,b;
    cin >> a >> b;
    for(int i = 1;i <= (int)a.size();i++)
        dp[i][0] = i;
    for(int j = 1;j <= (int)b.size();j++)
        dp[0][j] = j;
    /* init */
 
    for(int i = 1;i <= (int)a.size();i++)
        for(int j = 1;j <= (int)b.size();j++){
            dp[i][j] = 0x3f3f3f;
            dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j - 1] : min({dp[i - 1][j], dp[i][j - 1], dp[i][j] - 1, dp[i - 1][j - 1]}) + 1;
        }
 
    cout << dp[a.size()][b.size()] <<"\n";
 
    return 0;
}
