#include <bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define pob     pop_back
#define vll vector<ll>
#define all(v)  v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define csort(v, var)  sort(all(v),[](const pair<ll,ll> &a, const pair<ll,ll> &b){return a.var<b.var;});
 
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
 
using namespace std;
 
int main() {
    //shiv
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    ll n, t;
    vector<pair<ll, ll>> v;
    bool e=false;
    cin>>n>>t;
    for(ll i=0; i<n; i++) {
        ll a;
        cin>>a;
        v.pb({a, i+1});
    }
    sort(all(v));
    ll i=1, j=n;
    while(i<j) {
        if(v[i-1].first+v[j-1].first==t) {
            e=true;
            break;
        } else if (v[i-1].first+v[j-1].first>t) {
            j--;
        } else i++;
    }
    if(e) cout<<v[i-1].second<<" "<<v[j-1].second;
    else cout<<"IMPOSSIBLE";
}