#include <bits/stdc++.h>
 
 
#define ll long long int
#define ull unsigned ll
#define lld double
#define str_lwr(x) transform(x.begin(),x.end(),x.begin(),::towlower)
#define str_upr(x) transform(x.begin(),x.end(),x.begin(),::towupper)
#define tc ll t;in t;while(t--)
 
 
#define vec(b,a,n) vector<b>a(n)
#define mpi(a,b,mp) map<a,b>mp
#define mi(mp) mp.insert
#define vecbool(is_prime,n) vector<bool>is_prime(n+1,true)
#define pb push_back
#define it(a) for(auto it : a)out it<<(char)32;
#define new out endl
#define vecp(b) vector<pair<ll,ll>>b
#define iit(b) for(auto iit : b)out iit.first<<(char)32<<iit.second<<(char)32;
#define gcd __gcd
#define in cin>>
#define out cout<<
#define loopi(a,b,c) for(ll i=a;i<b;i+=c)
#define loopj(a,b,c) for(ll j=a;j<b;j+=c)
#define rloopi(a,b,c) for(ll i=a;i>=b;i-=c)
 
 
#define all(a) a.begin(),a.end()
#define max_value(a) *max_element(a.begin(),a.end())
#define max_index(a) max_element(a.begin(),a.end())-a.begin()
#define min_value(a) *min_element(a.begin(),a.end())
#define min_index(a) min_element(a.begin(),a.end())-a.begin()
#define b_s(a,x) binary_search(a.begin(),a.end(),x)
#define free(a,x1) count(a.begin(),a.end(),x1)
#define nsort(a) sort(a.begin(),a.end())
#define rsort(a) sort(a.rbegin(),a.rend())
 
 
#define PM_RIFAT ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
 
#define M 1e9+7
using namespace std;
 
 
int main()
{
    PM_RIFAT;
    ll n; in n;
    map<ll,ll>mp;
    loopi(0,n,1)
    {
        ll a,b;in a>>b;
        mp[a]++;
        mp[b]--;
    }
    ll count=0,mx=0;
    for(auto it:mp)
    {
        count+=(it.second);
        mx=max(count,mx);
    }
    out mx<<"\n";
    return 0;
}
