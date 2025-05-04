#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
//#define mod (ll)(1e9+7)
 
string s1,s2;
ll dp[5050][5050];
 
ll rec(ll level1,ll level2){
    if(level1==s1.length() or level2==s2.length()){
        return max(s1.length()-level1,s2.length()-level2);
    }
    if(dp[level1][level2]!=-1) return dp[level1][level2];
    ll ans=1e9;
    if(s1[level1]==s2[level2]){
        ans=rec(level1+1,level2+1);
    }else{
        ans=min(ans,1+rec(level1+1,level2));
        ans=min(ans,1+rec(level1+1,level2+1));
        ans=min(ans,1+rec(level1,level2+1));
    }
    dp[level1][level2]=ans;
    return ans;
}
 
void solve(){
    cin>>s1>>s2;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int t;
    //cin>>t; while(t--)
    solve();
    return 0;
}