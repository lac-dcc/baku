#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
 
int32_t main() {
    IOS;
    int n;
    cin>>n;
    map<pair<int,int>,int> cost_map;
    vector<pair<int,int>> ll;
    for(int i=0;i<n;i++){
        int x,y,cost;
        cin>>x>>y>>cost;
        ll.emplace_back(make_pair(x,y));
        cost_map[{x,y}]=max(cost_map[{x,y}],cost);
    }
 
    sort(ll.begin(),ll.end());
 
    int dp[n+1];
    memset(dp,0,sizeof dp);
 
    int ans=0;
    map<int,int> tmap;
    for(int i=n-1;i>=0;i--){
        int maxi=0;
        int key=ll[i].second;
        if(tmap.upper_bound(key)!=tmap.end())
            maxi=tmap[tmap.upper_bound(key)->first];
 
        dp[i]=maxi+cost_map[{ll[i].first,ll[i].second}];
        ans = max(dp[i],ans);
 
        tmap[ll[i].first]=ans;
    }
 
    cout<<ans;
 
    return 0;
}