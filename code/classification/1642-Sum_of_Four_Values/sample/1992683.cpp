//----------Coded By: ap_darknight-------------//
#include <bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
#define mapL map<ll, ll>
#define mapC map<char,ll>
#define mapS map<string,ll>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define vecL vector<ll>
#define vecC vector<char>
#define vecS vector<string>
#define pb push_back
#define repf(i,j,k) for(ll i=j; i<k; i++)
#define repb(i,j,k) for(ll i=j; i>k; i--)
#define mod 1000000007
#define bin_mod 4294967296
#define bit 32
#define BLK 200
ll gcd(ll a, ll b){
    if(a==0) return b;
    else return gcd(b%a,  a);
}
 
void solve(){
    ll n,x,q,y,m,k,sum=0;
    cin>>n>>q;
    
    vector<pll> arr;
    repf(i,0,n) cin>>x, arr.pb({x,i});
    sort(arr.begin(), arr.end());
    
    ll i, j, f=0;
    for( i=0; i<n; i++){
        for( j=i+1; j<n; j++){
            ll l = j+1, r = n-1, val = q-arr[i].ff-arr[j].ff;
            while(l<r){
            	sum = arr[l].ff + arr[r].ff;
            	if(sum==val){
            		f=1, k = l, m = r;
            		break;
        		}
        		
        		if(sum>val) r--;
        		else l++;
        	}
        	if(f) break;
        }
        if(f) break;
    }
    
    if(f) cout<<arr[i].ss+1<<" "<<arr[j].ss+1<<" "<<arr[k].ss+1<<" "<<arr[m].ss+1<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    
    // cout<<"## fucked"<<endl;
	return;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1,n,x,y,k,e;
    // cin>>t;
    // while(t--) 
	solve();
 
    return 0;
}
 
 
