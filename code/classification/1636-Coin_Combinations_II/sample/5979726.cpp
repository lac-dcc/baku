#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pk pop_back
#define joda pair<ll,ll>
#define fr first
#define sc second
#define rpt(i,n) for(int i=0;i<n;++i)
#define upb upper_bound
#define lob lower_bound
 
using namespace std;
 
void yes(){
    printf("YES\n");}
void no(){
    printf("NO\n");}
 
const ll mod=1e9+7;
const ll INF=LLONG_MAX-1;
 
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
 
ll gcd(ll a,ll b){
    while(a>0 && b>0) {
        if (a>b) a = a % b;
        else b = b % a;
    }
    if (a == 0) return b;
    return a;}
bool cmp(const pair<ll,ll> a, const pair<ll,ll> b){
    return a.sc<b.sc;}
 
ll dp[1000001];
ll coin[1000];
ll n,x;
 
void solve(){
    cin>>n>>x;
    rpt(i,n) cin>>coin[i];
    for(int i=0;i<=x;i++) dp[i]=0;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(j-coin[i-1]<0) continue;
            dp[j]+=dp[j-coin[i-1]]%mod;
        }
    }
    cout<<dp[x]%mod<<endl;
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tt; tt=1;
    while(tt--) solve();
	return 0;}