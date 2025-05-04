#include "bits/stdc++.h"
using namespace std;
//#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
 
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
 
    
 
void solve(){
 
    int mod = 1e9+7;
    int n, target;
    cin >> n >> target;
 
    vector<int> v(n);
 
    for(auto &x: v) cin >> x;
 
    int dp[n+1][target+1];    // no of ways using first n elements having sum == target
    memset(dp, 0, sizeof(dp));
 
    dp[0][0] = 1;  // using first 0 elements having sum==0  we have one way empty set
 
    
    // using first i elements having sum==0  we have one way empty set(not selecting any element)
    for(int i=1; i<=n; i++)   
        dp[i][0] = 1;
 
    
    // using first 0 elements having (sum>0) we have zero ways(bcz no elements to select)
    for(int i=1; i<=n; i++)
        dp[0][i] = 0;
 
 
    // no of ways using first i elements having sum==j 
    for(int i=1; i<=n; i++){
        for(int j=1; j<=target; j++){
            
            dp[i][j] = dp[i-1][j];  //if coin is not picked
 
            int left = j-v[i-1];  // if coin picked 
            if(left>=0){
                (dp[i][j] += dp[i][left]) %= mod;
            }
        }
    }
 
    cout << dp[n][target] << "\n";
}
 
 
 
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        init();
    #endif
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}