#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> a;
    vector<ll> v;
    ll x;
    for(ll i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(v.begin(),v.end());
    ll a_index = 0;
    ll v_index = 0;
    ll ans = 0;
    while(a_index < m && v_index < n){
        if(a[a_index] >= v[v_index]- k && a[a_index] <= v[v_index]+ k){
            a_index++;
            v_index++;
            ans++;
        }
        else if(a[a_index] >= v[v_index] + k){
            v_index++;
        }
        else if(a[a_index] <= v[v_index] - k){
            a_index++;
        }
    }
    cout << ans << endl;
    return 0;
}
