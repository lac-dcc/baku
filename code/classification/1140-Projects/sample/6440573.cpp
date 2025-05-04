#define ll long long
#include <bits/stdc++.h>
using namespace std;
int maskl;
 
int main() {
    int t = 1;
 //   cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<vector<ll>>v(n,vector<ll>(3,0));
        for(int i=0;i<n;i++){
            cin >> v[i][0] >> v[i][1] >> v[i][2];
        }
        sort(v.begin(),v.end());
        vector<vector<ll>>dp(n+1,vector<ll>(2,0));
        ll res=0;
        for(int i=n-1;i>=0;i--){
            ll lo=i+1,hi=n-1,mid,ans=-1;
            while(hi>=lo){
                mid=lo+(hi-lo)/2;
                if(v[mid][0]>v[i][1]){
                    ans=mid;
                    hi=mid-1;
                }else{
                    lo=mid+1;
                }
            }
            if(ans!=-1){
                dp[i][1]=max({dp[ans][1]+v[i][2],dp[i][1],dp[ans][0]+v[i][2]});
            }else{
                dp[i][1]=max(dp[i][1],v[i][2]);
            }
           // dp[i][1]=max({dp[i][1],(i+1<n?dp[i+1][0]:0),(i+1<n?dp[i+1][1]:0)});
            dp[i][0]=max({dp[i][0],(i+1<n?dp[i+1][1]:0),(i+1<n?dp[i+1][0]:0)});
            res=max(res,max(dp[i][0],dp[i][1]));
        }
        cout << res <<"\n";
 
    }
    return 0;
}