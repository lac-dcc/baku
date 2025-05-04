#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define all(v) v.begin(), v.end()
#define compact(v) sort(all(v)); v.erase(unique(all(v)), v.end())
 
typedef long long ll;
typedef pair<int, int> ii;
 
const int N=1e6+6;
const int M=1e9+7;
const char ln='\n';
 
template<class T> bool remin(T &a, T b){ if(a>b){a=b; return 1; } return 0;}
template<class T> bool remax(T &a, T b){ if(a<b){a=b; return 1; } return 0;}
 
int mod_pow(int a, int b, int m){ int c=1; while(b){ if(b&1) (c*=a)%=m; b>>=1, (a*=a)%=m; } return c; }
int inverse(int a, int m){ return mod_pow(a, m-2, m); }
 
const int div2=inverse(2, M);
 
ll sum(ll n){
    return (n%M)*((n+1)%M)%M*div2%M;
}
 
ll calc(ll a, ll b){
    return (sum(b)-sum(a-1))%M+M%M;
}
 
void solve(){
    ll n; cin>>n;
    ll ans=0, i=1;
    while(true){
        if(i>n) return cout<<((ans+M)%M), void();
 
        ll tmp=n/i, last=n/tmp;
        (ans+=calc(i, last)*tmp%M)%=M;
 
        i=last+1;
    }
    assert(false);
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
 
    int tc=1; //cin>>tc;
    while(tc--) solve();
 
    return 0;
}
