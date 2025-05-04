#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+1;
const int mod=1e9+7;
const ll mod_inverse_2=500000004;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
 
 
ll binary_exponentiation(ll a,ll n){
    if(n==0)return 1;
    if(n&1) return (a*binary_exponentiation(a*a,(n-1)/2));
    else return binary_exponentiation(a*a,n/2);
}
ll binPow(ll a, ll b, ll m)
{
    if(a==0 && b==0) return 1;
    if(a==0)return 0;
    a %= m;
    ll ans = 1;
    while (b != 0)
    {
        if (b & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return ans;
}
 
 
int smallestDivisor(int n)
{
    // if divisible by 2
    if (n % 2 == 0)
        return 2;
 
    // iterate from 3 to sqrt
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
    return n;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(30);
    int t=1;
//    cin>>t;
//    bool sieve[N];
//    for(int i=2;i<N;i++)sieve[i]=true;
//    sieve[0]=sieve[1]=false;
//    vector<int> primes;
//    for(int i=2;i<N;i++){
//        if(sieve[i]) {
//            primes.push_back(i);
//            for (int j = 2 * i; j < N; j += i) {
//                sieve[j]=false;
//            }
//        }
//    }
 
    while(t--) {
        ll n; cin>>n;
        ll k=1;
        ll beg=n; ll end=n;
        ll ans=0;
        while(end>0){
            beg=n/(k+1);
            ans=(ans+(end%mod-beg%mod+mod)%mod*((end%mod+beg%mod+1)%mod)%mod*mod_inverse_2%mod*k%mod)%mod;
            k=n/end;
            end=beg;
//            cout<<beg<<" "<<end<<" "<<ans<<"\n";
 
        }
 
        cout<<ans<<"\n";
 
    }
 
}
