#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define popcount(x) __builtin_popcountll(x)
#define MOD 1000000007
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
    }
    map<ll,vector<pll>> m; 
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            m[v[i]+v[j]].push_back({i,j});
        }
    }
    
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++){
            ll target=k-(v[i]+v[j]);
            for(auto it:m[target]){
                if(i!=it.first && i!=it.second && j!=it.first && j!=it.second){
                    cout<<i+1<<" "<<j+1<<" "<<it.first+1<<" "<<it.second+1<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
    
return 0;
}
