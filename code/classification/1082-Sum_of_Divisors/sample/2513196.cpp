#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)(1e9)+7, inv2=500000004;
int add(int a,int b) { a%=mod, b%=mod; return (0ll+a+b+mod)%mod; }
int mul(int a,int b) { a%=mod, b%=mod; return (1ll*a*b)%mod; }
 
int32_t main() {
    int n,ans=0; cin>>n;
    auto sum=[](int a,int b) { return add(mul(mul(b,b+1),inv2), -mul(mul(a,a-1),inv2)); };
    for (int i=1,la; i<=n; i=la+1) {
        la=(n/(n/i));
        ans=add(ans,mul((n/i),sum(i,la)));
    } 
    cout<<ans<<'\n';
}
