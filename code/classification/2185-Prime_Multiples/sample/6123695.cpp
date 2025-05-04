#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using ll = long long;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
int m = 1e9 + 7;
const int TWO_MOD_INV = 500000004;
 
ll inv(ll i,ll m)
{
    return i <= 1 ? i : m - (long long)(m / i) * inv(m % i, m) % m;
}
vector<long long> primes;
 
vector<long long> trial_division4(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
vector<ll> fastfactor(long long n)
{
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++)
    {
        while (n % d == 0)
        {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
    {
        factorization.push_back(n);
    }
    return factorization;
}
vector<bool> sieve(int n)
{
 
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}
ll func(ll a,ll b){
   return (((((b+a)%m)*((b-a+1)%m)%m)*TWO_MOD_INV)%m);
}
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll lcm(ll a,ll b){
    return (a*b)/(__gcd(a,b));
}
int main()
{
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll> v(k);
    for(int i=0;i<k;i++){
        cin>>v[i];
    }
    vector<ll> nodiv(k+1,0);
    vector<vector<ll>> subsets;
    for(int i=1;i<(1<<k);i++){
        //vector<ll> t;
        ll temp=n;
        ll divs=0;
        for(int j=0;j<k;j++){
            if((i & (1<<j))!=0){
                divs++;
                temp/=v[j];
                //t.push_back(v[j]);
                //cout<<"inserted "<<v[j]<<"\n";
            }
        }
        nodiv[divs]+=temp;
        //subsets.push_back(t);
    }
    ll ans=0;
    for(int i=1;i<=k;i++){
        if(i%2==0){
            ans-=nodiv[i];
        }
        else{
            ans+=nodiv[i];
        }
    }
    //cout<<subsets.size()<<"\n";
    /*for(int i=0;i<subsets.size();i++){
        cout<<"ith "<<i<<"\n";
        for(int j=0;j<subsets[i].size();j++){
            cout<<subsets[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    
    /*for(int i=0;i<ll(subsets.size());i++){
        if(subsets[i].empty()){
            continue;
        }
        if((ll)subsets[i].size()%2==0){
            ll div=subsets[i].front();
            for(int j=1;j<ll(subsets[i].size());j++){
                div*=subsets[i][j];
            }
            cout<<"subs "<<n/div<<"\n";
            ans-=(n/div);
        }
        if((ll)subsets[i].size()%2==1){
            ll div=subsets[i].front();
            for(int j=1;j<ll(subsets[i].size());j++){
                div*=subsets[i][j];
            }
            cout<<"added "<<n/div<<"\n";
            ans+=(n/div);
        }
    }*/
    cout<<ans<<"\n";
 
    
}