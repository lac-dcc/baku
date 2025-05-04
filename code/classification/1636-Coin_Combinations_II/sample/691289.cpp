#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
//#define int long long int
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(s)   scanf("%s",s)
#define pi(x)   printf("%d\n",x)
#define pl(x)   printf("%lld\n",x)
#define ps(s)   printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define INF 1e9+7
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
int mpow(int base, int exp);
void ipgraph(int m);
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
const int mod = 1e9 + 7;
const int N = 2e5+5, M = N;
//=========================================
 
 
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //#ifndef ONLINE_JUDGE
    //freopen("inputf.in", "r", stdin);
    //freopen("outputf.in", "w", stdout);
    //#endif
 
    int n, x;
    cin >> n >> x;
 
    vector<int> c(n);
    for(int i = 0; i < n; ++i)
        cin >> c[i];
 
    //vector<vector<int> > dp(n + 1, vector<int> (x + 1, 0));
 
    vector<vector<int>> dp(n+1,vector<int>(x+1,0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-c[i-1];
            if (left >= 0) {
                (dp[i][j] += dp[i][left]) %= mod;
            }
        }
    }
 
    //cout << dp[n][target] << endl;
    cout << dp[n][x] << "\n";
 
    return 0;
}