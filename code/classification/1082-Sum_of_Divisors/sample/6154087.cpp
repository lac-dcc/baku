#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define mod 1000000007
 
int modulo_expo(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b = b/2;
    }
    return res;
}
 
signed main(){
    int n;cin>>n;
    int srt = sqrt(n),ans=0;
    for(int i=1;i<=srt;i++){
        int l=(((n-i*i)/i+1)%mod);
        (ans += (((l-1)*i)%mod+((l*(2*i+(l-1))%mod)*modulo_expo(2,mod-2))%mod)) %= mod;
    }
    cout<<ans<<"\n";
}
