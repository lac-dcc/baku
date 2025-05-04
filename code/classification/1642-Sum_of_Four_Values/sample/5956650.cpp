#include <bits/stdc++.h> 
using namespace std;
#define ll long long
#define pii pair<int, int>
 
int n;
ll t, a[1005];
unordered_map<ll, vector<pii>> mp;
 
int main(){
    cin>>n>>t;
    mp.reserve(1005*1005);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<i;j++){
            ll psum=a[i]+a[j];
            if(psum>=t) continue;
            if(mp.find(t-psum)!=mp.end()){
                for(pii p : mp[t-psum]){
                    if(p.first!=j&&p.first!=i&&p.second!=j&&p.second!=i){
                        cout<<p.first<<" "<<p.second<<" "<<i<<" "<<j<<'\n';
                        return 0;
                    }
                }
            }
            else mp[psum].push_back({j, i});
        }
    }
    cout<<("IMPOSSIBLE\n");
}
