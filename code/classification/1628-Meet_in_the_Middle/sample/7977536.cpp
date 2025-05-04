#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);    
    ll n,x,ans=0; cin >> n >> x;
    ll a[n];
    vector<ll> v;
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    ll mid=n/2;
    for(int mask=0;mask<(1<<mid);++mask) {
        ll cur=0;
        for(int i=0;i<mid;++i) {
            if(mask>>i&1) {
                cur += a[i];
            }
        }
        v.push_back(cur);
    }
    sort(v.begin(),v.end());
    ll mid2=n-mid;
    for(int mask=0;mask<(1<<mid2);++mask) {
        ll cur=0;
        for(int i=0;i<mid2;++i) {
            if(mask>>i&1) {
                cur += a[i+mid];
            }
        }
        int temp = upper_bound(v.begin(),v.end(),x-cur) - lower_bound(v.begin(),v.end(),x-cur);
        ans += temp;
    }
    cout << ans;
    return 0;
}
