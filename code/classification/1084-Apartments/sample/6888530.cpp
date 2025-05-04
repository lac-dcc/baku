#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using lli = long long;
 
signed main(){
    IOS
    lli n,m,k;
    cin>>n>>m>>k;
    vector<lli>vec(n);
    for(lli i=0;i<n;i++){
       cin>>vec[i];
    }
    multiset<lli>mt;
    for(lli i=0;i<m;i++){
        lli u;
        cin>>u;
        mt.insert(u);
    }
 
    lli cnt = 0;
    sort(vec.begin(),vec.end());
    for(auto v:vec){
        auto it = mt.lower_bound(v-k);
        if(it == mt.end()){
            continue;
        }
        if(*it <= v+k){
            cnt++;
            mt.erase(mt.find(*it));
        }
    }
    cout << cnt;
    return 0;
}
