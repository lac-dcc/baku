#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define nline '\n'
#define debug(x) cerr<<#x<<" "<<x<<endl;
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(ll i = (a); i < (b); i++)
 ll gcd(ll a, ll b) { if (b == 0)    return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
const int MOD = pow(10,9)+7;
ll dp[1000001];
int sol(vi& v,int n, int s){
    // debug(s)
    if(s==0)
        return 1;
    else if(s<0)
        return 0;
    else if(dp[s]>=0)
        return dp[s];
    else{
        ll ans=0;
        rep(i,0,n){
            ans+=sol(v,n,s-v[i]);
        }
        ans%=MOD;
        // debug(ans)
        return dp[s]=ans;
    }
}
void solve(){
    int n,x;
    cin>>n>>x;
    // debug(n)
    vi v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<sol(v,n,x);
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    solve();
}