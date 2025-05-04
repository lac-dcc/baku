#include <bits/stdc++.h>
using namespace std;
#define inputJunk ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define debug cout<<"HERE"<<endl;
#define ell "\n"
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<pi, int> trip;
typedef pair<pll, ll> tripll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<trip> vtrip;
 
const ll INF = 1e15+250;
const ll P = 9973, M = 1e9+9;
const int MM = 1e5+5; int mod = 1e9+7;
 
ll n, ans = 0;
 
int main(){
    inputJunk
    cin>>n;
    for(ll i = 1,j; i<=n; i = j){
        ll q = n/i; j = n/q+1;
        ll x = j-i, y = i+j-1;
        if(x%2==0)x/=2;
        else y/=2;
        x%=mod; y%=mod;
        ans= (ans+q%mod*x%mod*y%mod)%mod;
    }
    cout<<ans<<ell;
}
 
 
/*CUSTOM TEST CASE 1
*/
 
/*CUSTOM TEST CASE 2
 
*/
 
/*CUSTOM TEST CASE 3
 
*/
/*Comments of Shame
- floating error (use integer division instead)
- cin vs getline
- upperbound and lowerbound returns iterators
- use long long when number is big enough
*/
 
//freopen("time.in","r", stdin);
//freopen("time.out","w", stdout);
