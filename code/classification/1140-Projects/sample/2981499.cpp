#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll int mod = 1e9+7;
 ll int b(vector<vector<ll int>>&v,int i){
        int l = i+1;
        int h = v.size()-1;
        ll int ans=-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(v[mid][0]>v[i][1]){
                ans = mid;
                h = mid-1;
            }else l = mid+1;
        }
        return ans;
    }
    ll int f(vector<vector<ll int>>&v,int i,ll int*dp){
        if(i>=v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        //basecase
        ll int ans = f(v,i+1,dp);
        ll int ni = b(v,i);
        if(ni!=-1){
            ans = max<ll int>(ans,v[i][2]+f(v,ni,dp));
        }else ans = max<ll int>(ans,v[i][2]);
        return dp[i] = ans;
    }
 
    ll int jobScheduling(vector<ll int>& start, vector<ll int>& end, vector<ll int>& profit) {
        vector<vector<ll int>>v;
        for(int i=0;i<start.size();i++){
            v.push_back({start[i],end[i],profit[i]});
        }
        ll int dp[200002];
        memset(dp,-1,sizeof(dp));
        sort(v.begin(),v.end());
        return f(v,0,dp);
    }
int main() {
    int n;
    cin>>n;
    vector<ll int>st,en,pr;
    for(int i=0;i<n;i++){
        ll int x;cin>>x;
        st.push_back(x);
        ll int y;cin>>y;
        en.push_back(y);
        ll int z;cin>>z;
        pr.push_back(z);
    }
    cout<<jobScheduling(st,en,pr);
}