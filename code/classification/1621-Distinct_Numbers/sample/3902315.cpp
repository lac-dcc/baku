#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mod 1000000007 
#define loop_int(a,s,e) for(int a=s;a<=e;a++)
#define loop_ll(a,s,e) for(ll a=s;a<=e;a++)
#define loop_rev(a,e,s) for(ll a=e;a>=s;a--)
#define inf INT_MAX
#define full(a) a.begin(),a.end() 
#define pb push_back
#define vll vector<ll>
 
void solve(){
 ll n;
 cin>>n;
 vll arr(n);
 loop_ll(i,0,n-1) cin>>arr[i];
 sort(full(arr));
 ll cnt = 0;
 loop_ll(i,0,n-1){
     ll t = arr[i];
     cnt++;
     while(arr[i] == t) i++;
     i--;
 }
 
 std::cout << cnt << std::endl;
}
 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
	ll t=1;
	//cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}