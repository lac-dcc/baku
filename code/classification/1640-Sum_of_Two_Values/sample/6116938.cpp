//Author: Manish :)                                ¯\_(ツ)_/¯
#include<bits/stdc++.h>
using namespace std;
#define pr pair
#define ff first
#define ss second
#define inf 1e18
#define rev reverse
#define pb push_back
#define ppb pop_back
#define vll vector<ll>  //-----------
#define mod1 998244353
const int mod = 1e9 + 7;
#define ll long long int
#define lld long long double
#define vllp vector<pr<ll,ll>> //-------------------------------
#define pi 3.141592653589793238462
#define iloop(start,n) for(int i = start; i < n; i++)
#define jloop(start,n) for(int j = start; j < n; j++)//------------
#define all(x) (x).begin(), (x).end()
#define setbits(x) __builtin_popcountll(x) 
#define yes(flag) if(flag) cout<<"YES\n"; else cout<<"NO\n";
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
/*------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b); ll lcm(ll a, ll b); ll expo(ll a, ll b, ll m=inf); ll sqrtt(ll x);ll cbrtt(ll x);
/*------------------------------------------------------------------------------------------------------------*/
//vll v(n,0); vllp arr(n)//pb //pr //ff //ss //lp(0,n){cout<<v[i]<<" ";}
 
int main(){
IO;
ll n,k;cin>>n>>k;
vector <pair<ll,ll>> v;
iloop(0,n){
    ll a;
    cin>>a;
    v.pb({a,i});
}
sort(all(v));
ll x=-1,y=90;
vll vv;
iloop(0,n){
    vv.pb(v[i].ff);
}
iloop(0,n){
    ll val=k-v[i].ff;
    if(val<v[i].ff)break;
     ll ind=upper_bound(all(vv),val)-vv.begin();
     ind--;
    if(ind!=i &&  ind!=-1 && val==v[ind].ff){
        x=v[i].ss+1;y=v[ind].ss+1;break;
 
    }
}
 
 
 
if(x==-1)cout<<"IMPOSSIBLE";
else cout<<min(x,y)<<" "<<max(x,y);
return 0;}
 
ll gcd(ll a, ll b) {if (b>a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a*b)/gcd(a,b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll sqrtt(ll x){if (x==0 || x==1)return x;ll i = 1,result = 1;while (result <= x) {i++; result=i*i;} return i-1;}
ll cbrtt(ll x){if(x==0||x==1)return x;ll i=1, result=1;while(result<=x){i++;result=i*i*i;}return i-1;}
