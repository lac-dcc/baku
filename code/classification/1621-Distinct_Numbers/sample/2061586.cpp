#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main(){
    ll n; cin >> n;
    ll a[n];
    set<ll> se;
    for(ll i=0;i<n;i++){
        ll x; cin >> x;
        se.insert(x);
    }
    cout << se.size() << "\n";
}