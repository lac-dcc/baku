//#pragma GCC optimize("Ofast")
//#pragma GCC target("fma")
//#pragma GCC optimization ("unroll-loops")
 
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
#define pb          push_back
#define all(v)      v.begin(),v.end()
#define yes         cout<<"Yes"<<endl;
#define no          cout<<"No"<<endl;
#define ff          first
#define sc          second
#define inf         999999999
#define pi          3.14159265359
#define printv(v)   for(auto x:v)cout<<x<<' ';cout<<endl;
#define takev(v)    for(auto &x:v)cin>>x;
inline  int         random(int a=1,int b=10)
{
    return a+rand()%(b-a+1);
}
typedef long long ll;
inline ll           lcm(ll a,ll b)
{
    return (a*b)/__gcd(a,b);
}
//#define see(x)  cout<<endl<<#x<<" : "<<(x)<<endl;
#define see(args...) \
{ \
    string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
    stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);\
}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout<< *it << " = " << a <<",\n"[++it==istream_iterator<string>()];
    err(it, args...);
}
#define scc(n) scanf("%d",&n);
#define sccc(n) scanf("%lld",&n);
 
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const int N=1e5+9,mod=1e9+7;
char c[1009][1009];
 
int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(NULL);
 
    int n,x;
    scc(n)
    scc(x)
 
    vector<int> h(n+2),s(n+2);
    for(int i=1;i<=n;i++) scc(h[i])
 
    for(int i=1;i<=n;i++) scc(s[i])
 
    vector< vector<int> >dp(n+10,vector<int>(x+10));
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(j-h[i] >= 0)
            dp[i][j] = max(dp[i-1][j-h[i]]+s[i],dp[i-1][j]);
            else
            dp[i][j] = dp[i-1][j];
//            cout<< dp[i][j] << ' ';
        }
//        cout<< endl;
    }
 
    cout<< dp[n][x];
 
    return 0;
}
