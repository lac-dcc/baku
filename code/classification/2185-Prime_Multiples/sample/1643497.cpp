#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include <unordered_map>
#include<climits>
#include<set>
#include <iomanip>
#include<numeric>
#include<queue>
#include<stack>
 
using namespace std;
 
#define ff              first
#define ss              second
#define ll              long long
#define ld              long double
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<ll,ll>
#define vi              vector<ll>
#define mii             map<ll,ll>
#define pqb             priority_queue<ll>
#define pqs             priority_queue<ll,vi,greater<ll> >
#define mod             1000000007
#define inf             1e18
#define all(v)          (v).begin(),(v).end()
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl            "\n"
ll arr[30] ; 
ll solve( vi v , ll k , ll c ,ll n ){
    if(c == k){
        ll k1 = 1 ; 
        if(v.size() > 0){
            for(int i = 0 ; i < (ll)v.size() ;i++){
                ll x = n/k1 ; 
                if(v[i] > x){
                    return 0 ; 
                }
                k1*=v[i] ; 
            }
            
            k1=n/k1 ; 
            if(v.size()%2){
                return k1 ;
            }
            else {
                return -k1 ; 
            }
        }
 
        else{
            return 0 ; 
        }
    }
 
    ll a1 = solve(v,k,c+1,n) ; 
    v.pb(arr[c]) ; 
    ll a2 = solve(v,k,c+1,n) ; 
    return a1+a2 ; 
 
 
}
int main(){
 
    FIO ;
    int t ;
    t =1  ;
    //cin >> t ;
 
    while(t--){
      ll n,k ;
      cin >> n >> k ; 
      for(int i = 0 ; i < k ;i++){
          cin >> arr[i] ; 
      }
      vi v; 
 
      ll ans = solve(v,k,0,n) ; 
      cout << ans ; 
 
 
 
    }
    return 0 ;
 
}