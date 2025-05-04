#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define ll long long
#define int long long
#define vii vector<int>
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 2e5+1;
 
bool comp(vii &a, vii &b){
    if(a[1]<b[1])return true;
    else if(a[1]>b[1])return false;
    else return a[0]<b[0];
}
 
int32_t main()
{
    FAST;
    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif
    int n;cin>>n;
    vector<vii>a;
    for(int i=0;i<n;i++){
        int u,v,w;cin>>u>>v>>w;
        vii temp;
        temp.pb(u);temp.pb(v);temp.pb(w);
        a.pb(temp);
    }
    sort(a.begin(),a.end(),comp);
    vii dp(n,0);
    dp[0] = a[0][2];
    for(int i=1;i<n;i++){
        //Take No Reward
        int ans1 = dp[i-1];
 
        //Take Reward
        int startV = 0;
        int endV = i-1;
        int index = -1;
        int ans2 = 0;
        while(startV<=endV){
            int middleV = startV+(endV-startV)/2;
            if(a[middleV][1]<a[i][0]){
                index = middleV;
                startV = middleV+1;
            }
            else endV = middleV-1;
        }
        if(index!=-1)ans2 = dp[index];
        ans2 += a[i][2];
        dp[i] = max(ans1,ans2);
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
