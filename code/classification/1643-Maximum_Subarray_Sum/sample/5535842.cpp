# include <iostream>
# include <bits/stdc++.h>
# include <algorithm>
# define ll                     long long int
# define ld                     long double
# define pb                     push_back
# define cinvector(arr,n)       for(ll i=0;i<n;i++){ ll num; cin>>num; arr.push_back(num);  }
# define sumvector(arr,len)     ll sum=0;  for(ll i=0;i<len;i++){  sum=sum+arr[i];   }
# define coutvector(x)          for(ll i=0 ; i<x.size() ; i++) cout<<x[i]<<" "; cout<<endl;
# define sumvectorrev(arr,n,r)  ll sum1=0; for(ll i=n-1;i>=0;i--){ sum1=sum1+arr[i]; r.pb(arr[i]); }
# define vecpair                vector<pair<char,ll>> ans;
# define debug                  cout<<"here"<<endl;
# define fast                   ios_base::sync_with_stdio(false);  cin.tie(NULL); 
# define setvector(s,arr)   	for(ll i=0;i<arr.size();i++){ s.insert(arr[i]); }
# define khatam                 cout<<endl;
# define yes                    cout<<"YES\n";
# define no                     cout<<"NO\n";
# define pi                     3.141592653589793238462
# define its                    to_string // converting integer to string 
# define inn                    ll n;   cin>>n;
# define inarr                  vector<ll> arr; cinvector(arr,n);
# define test                   ll tc; cin>>tc;
unsigned ll MOD = 1e9 + 7;
# define zero cout<<0<<endl;
# define print(i)   cout<<i<<endl;
ll MAX = 1e9 + 1;
ll MIN = -1e9;
 
using namespace std;
 
/* **************** DHWANI UPADHYAY *************************** */
// PRIME NUMBERS
ll N=1e6+6;
vector<ll> iprime;
vector<ll> isprime(N,1);
void sieve(ll n){
    isprime[0]=isprime[1]=0;
    for(ll i=2;i<=n;i++){
        if(isprime[i]){
            iprime.pb(i);
            for(ll j=i*i;j<=n;j=j+i)
                isprime[j]=0;
        }
    }
}
 
bool is_prime_check(ll n){
    if(n<=1)    return false;
    for(ll i=2;i<n;i++){
        if(n%i==0)  return false;
    }
    return true;
}
 
// Sorting vector of pair by second value
bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return (a.second < b.second);
}
 
// Printing vector of pair<ll,ll> 
void vecpairprint(vector<pair<ll,ll>> vecp){
    for(auto it:vecp) 
        cout<<it.first<<" "<<it.second<<endl;
    cout<<endl;
}
 
bool is_palindrome(string is_palins)
{
    string is_palint=is_palins;
    reverse(is_palins.begin(),is_palins.end());
    if(is_palint==is_palins)
        return true;
    return false;
}
 
ll fact(ll n)
{
    return (n==1 || n==0) ? 1: n * fact(n - 1);
}
 
bool cmp(pair<ll, ll>& a,
        pair<ll, ll>& b)
{
    return a.second < b.second;
}
 
ll getsqrt(ll n) {
    ll l=1, r=1000000000;
    while (l<=r) {
        ll m = (l+r)/2;
        if (m*m <= n) l = m+1;
        else r = m-1;
    }
    return r;
}
bool check_power(ll z){
    while(z%2==0){
        z=z/2;
    }
    if(z==1)    return true;
    else return false;
}
 
 
int main(){
    fast;
    inn;
    inarr;
    ll sum=0,res=INT_MIN;
    for(ll i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum<0){
            sum=0;
        }
        if(arr[i]>=0)
            res=max(res,sum);
    }
    sort(arr.begin(),arr.end());
    if(res==INT_MIN)    cout<<arr[n-1]<<endl;
    else cout<<res<<endl;
}
