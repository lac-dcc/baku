#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define x first
#define y second
#define pb push_back
 
const int mod=1e9+7;
 
ll N, sol=0;
 
ll power(ll a, ll b){
    if(b==0)
        return 1;
    if(b%2==1)
        return ((a%mod)*power(a,b-1))%mod;
    a=((a%mod)*(a%mod))%mod;
    return power(a,b/2)%mod;
}
 
ll inverse(ll a){
    return power(a,mod-2);
}
 
void solve(){
//    ifstream cin("text.in");
 
    cin>>N;
    for(ll i=1;i*i<=N;i++)
        sol=(sol+(N/i)*i)%mod;
 
    ll st=sqrt(N);
    for(ll i=sqrt(N);i>=1;i--){
        ll dr=N/i;
        ll sum=0;
        sum+=((((dr%mod)*((dr+1)%mod))%mod)*inverse(2))%mod;
        sum-=((((st%mod)*((st+1)%mod))%mod)*inverse(2))%mod;
        sum=(sum+mod)%mod;
        sum=(sum*(i%mod))%mod;
 
        sol=(sol+sum)%mod;
        st=dr;
    }
    cout<<sol;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
    return 0;
}
