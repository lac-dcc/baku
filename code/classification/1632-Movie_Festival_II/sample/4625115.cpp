#include<bits/stdc++.h>
 
using namespace std;
 
#define ff first
#define ss second
#define ll long long
#define zerobits(x) __builtin_ctzll(x)
#define setbits(x) __builtin_popcountll(x)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define vi vector<int>
#define invectr(x)     \
    for (auto &i : x) \
        cin >> i;
const int MAXN = 200200;
 
 
 
int main(){
 
    ll n, k;
    cin >> n >> k;
    std::vector<pair<ll,ll>> v(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> v[i].ss >> v[i].ff;
    }
 
    sort(all(v));
    multiset<ll> end;
    ll maxi = 0;
 
    for (ll i = 0; i < k; ++i)
    {
        end.insert(0);
    }
 
    for (ll i = 0; i < n; ++i)
    {
        
        auto it = end.upper_bound(v[i].ss);
        if(it == begin(end)){
            continue;
        }
        end.erase(--it);
        end.insert(v[i].ff);
        maxi++;
    
    }
 
    cout << maxi << "\n";
 
}
//haze_12
