/*
*   author: codemohitpra2103
*/
 
#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define lb                lower_bound
#define ub                upper_bound
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
#define goog(tno)         cout << "Case #" << tno <<": "
#define read(x)           int x; cin >> x
#define prDouble(x)       cout << fixed << setprecision(10) << x
#define inf               (1LL<<60)
#define triplet           pair<ll,pair<ll,ll>>
#define endl              "\n"
#define inar(a,n)         int a[n]; rep(i,0,n)cin>>a[i];
#define inav(a,n)         vector<int> a(n); rep(i,0,n)cin>>a[i];
#define outar(a,n)        rep(i,0,n)cout<<a[i]<<" "; cout<<endl;
 
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
 
const int N=1001;
 
 
 
void solve(){
    int n,w;
    cin>>n>>w;
    inav(wt,n);
    inav(val,n);
    // outar(wt,n);
    // outar(val,n);
    vector<int> dp(w+1,0);
    rep(i,0,w){
        if(i>=wt[0])dp[i]=val[0];
        // cout<<wt[i]<<endl;
    }
    // outar(dp,w);
    rep(i,1,n){
        for(int j=w;j>=1;j--){
            int op1=dp[j];
            int op2=-INF;
            if(j>=wt[i]){
                op2=val[i]+dp[j-wt[i]];
            }
            dp[j]=max(op1,op2);
        }
        // outar(dp,w);
    }
    cout<<dp[w];
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
    // cin>>t; 
    while(t--) solve();
    return 0;
}
