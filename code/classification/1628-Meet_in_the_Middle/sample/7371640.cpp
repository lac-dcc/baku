#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,x;cin>>n>>x;
    ll arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];if(arr[i]>x)i--,n--;}
    sort(arr,arr+n);
    unordered_map<ll,ll> mp;
    for(int i=0;i<(1<<(n/2));i++){
        ll s=0,v=i,j=0;
        for(int j=0;j<n/2;j++){
            if(i&(1<<j))s+=arr[j];
        }
        mp[s]++;
    }
    ll ans=0;
    for(int i=0;i<(1<<(n-n/2));i++){
        ll s=0,v=i,j=n/2;
        for(int j=0;j<n-n/2;j++){
            if(i&(1<<j))s+=arr[n/2+j];
        }
        if (mp.count(x-s))ans+=mp[x-s];
    }
    cout<<ans;
}
