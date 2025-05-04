#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define print(...) for(auto& i:__VA_ARGS__) cout<<i<<" "; cout<<'\n';
#define read(...) for(auto& i:__VA_ARGS__) cin>>i;
#define int long long
const int mod=1e9+7;
 
void solve(){
    int n,k; cin>>n>>k;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        a[i]={y,x};
    }
    sort(a.begin(), a.end());
    int ans=0;
    set<pair<int,int>> st;
    for(int i=0;i<n;i++){
        int find=0;
        if(st.size()){
            auto x=st.upper_bound({a[i].second, INT_MAX});
            if(x!=st.begin()){
                x--; find=1;
                ans++; st.erase(x); st.insert({a[i].first, i});
            }
        }
        if(!find and st.size()<k){
            ans++; st.insert({a[i].first, i});
        }
    }
    cout<<ans<<endl;
}
 
#undef int
int main() {
    FAST; int T=1;
    //cin>>T;
    while(T--) solve();
    return 0;
}