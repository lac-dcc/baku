#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef long double ld ;
#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define pb push_back
#define pi pair<ll,ll>
#define pll pair<ll,ll>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define firsst cout<<"First"<<endl;
#define seconnd cout<<"Second"<<endl;
#define tiie cout<<"Tie"<<endl;
#define fr(i,a,b) for(ll i = a;i < (ll)b;i++)
#define rfr(i,a,b) for(ll i = a;i > (ll)b;i--)
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define alll(x) ((x).begin()+1), (x).end()
#define MOD mod
#define endl '\n'
//#define uid(a, b) uniform_ll_distribution<ll>(a, b)(rng)
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7  ;
void io(){ios::sync_with_stdio(false) ;cin.tie(NULL) ;
//freopen("milkorder.in","r",stdin) ;freopen("milkorder.out","w",stdout) ;
}
void dbg(vector<ll> tab){for(auto it : tab) cout<<it<<" ";cout<<endl;}
void dbgg(pi p){cout<<p.F<<" "<<p.S<<endl;}
void dbgpi(vector<pi> tab){for(auto it : tab) dbgg(it) ;}
template<class T> bool ckmax(T& a, const T& b){return a < b ? a = b, 1 : 0;}
template<class T> bool ckmin(T& a, const T& b){return a > b ? a = b, 1 : 0;}
template<class T> void add(T& a, const T& b){a = a + b ; if(a>mod) a-= mod ;}
void nop(){cout<<"LIE"<<endl;return;}
 
const int N = 5e3 + 5  ;
int n , m , dp[N][N] ;
string s , t ;
 
 
int work(int i , int j)
{
    if(i==n && j==m) return 0 ;
    if(i==n) return m-j ;
    if(j==m) return n-i ;
    int& ret = dp[i][j] ;
    if(ret!=-1) return ret ;
    ret = 1e9 ;
    if(s[i]==t[j]) ckmin(ret , work(i+1 , j+1)) ;
    ckmin(ret , work(i+1 , j+1) + 1) ;
    ckmin(ret , work(i+1 , j) + 1) ;
    ckmin(ret , work(i , j+1) + 1) ;
    return ret ;
}
 
void solve()
{
    memset(dp , -1 , sizeof(dp)) ;
    cin>>s>>t ;
    n = s.size() ;
    m = t.size() ;
    cout<<work(0 , 0)<<endl;
}
 
int main()
{
    io() ;
    ll tt = 1 ;
//    cin>>tt ;
    while(tt--) solve() ;
    return 0 ;
}
