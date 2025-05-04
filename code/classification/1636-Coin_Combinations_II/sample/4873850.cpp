#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define x first
#define y second
#define debug(x) cout << (#x) << " is " << (x) << "\n"
#define FOR(i,m,n) for(int i = m; i <= n; i++)
#define FORD(i,n,m) for(int i = n; i >= m; i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//end_define
bool Multitests = 0;
const int maxN= 1e8 + 5;
ll n, k, A[105], dp[maxN];
void input()
{
    cin >> n >> k;
    FOR(i,1,n)
    {
        cin >> A[i];
    }
}
const ll Mod = 1e9 +7;
void solve()
{
    dp[0] = 1;
    FOR(j, 1, n)
    {
        FOR(i, 1, k)
        {
            if(A[j] <= i)
            {
                dp[i] = (dp[i] + dp[i - A[j]] % Mod) % Mod;
                //cout << i << " " << dp[i] << " " << j << " " <<dp[A[j]] << '\n';
            }
        }
    }
    cout << dp[k];
}
int main()
{
    //freopen("1.in", "r", stdin);
    faster;
    int t = 1;
    if( Multitests )
    cin >> t;
    while(t--)
    {
        input();
        solve();
    }
    return 0;
}
 
