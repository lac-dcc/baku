#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
bool c(ll a,ll b,ll c,ll d){
    if(a!=c and a!=d and b!= c and b!=d) return 1;
    return 0;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll t;
    cin>>n>>t;
    vector<ll> v(n);
    for(int i=0;i<n;++i){
        cin>>v[i];
    }
    map<ll,pair<int,int>> m;
    for(int i=0;i<n-1;++i){
        for(int j= i+1;j<n;++j){
            m[v[i]+v[j]] = {i,j};
        }
    }
    bool f=0;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            ll s = v[i]+v[j];
            s=t-s;
            if(m.find(s)!=m.end() and c(m[s].first,m[s].second,i,j)){
                cout<<m[s].first+1<<" "<<m[s].second+1<<" "<<i+1<<" "<<j+1<<endl;
                f=1;
                break;
            }
        }
        if(f) break;
    }
    if(!f) cout<<"IMPOSSIBLE\n";
    return 0;
}
