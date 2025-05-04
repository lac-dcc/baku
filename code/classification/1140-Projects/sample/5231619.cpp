#include <bits/stdc++.h>
     
using namespace std;
     
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
     
#define int long long int
 
#define pb push_back
 
#define pii pair<int,int>
 
#define f first
 
#define s second
struct proj {
    int st;
    int ed;
    int pr;
};
 
#define proj struct proj 
bool cmp(proj p1,proj p2){
    return p1.ed<p2.ed;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n+1,0),b(n+1,0),p(n+1,0);
    vector<proj>pro(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>p[i];
        pro[i].st=a[i];
        pro[i].ed=b[i];
        pro[i].pr=p[i];
    }
    
   sort(pro.begin(), pro.end(),cmp);
   sort(b.begin(), b.end())
   ;
    
    vector<int>dp(n+1,0);
    for(int i=1;i<n+1;i++){
        
        int j= lower_bound(b.begin(), b.end(),pro[i].st)-b.begin();
        j--;
        // cout<<i<<" "<<a[i]<<" "<<j<<" jthere"<<endl;
        if(j>=0){
            dp[i]=max(dp[i-1],pro[i].pr+dp[j]);
            // cout<<i<<" "<<dp[i-1]<<" "<<dp[j+1]+p[i-1]<<endl;
        }
        // else dp[i]=dp[i-1];
    }
   
    // for(int i=0;i<=n;i++)cout<<dp[i]<<" ";
        // cout<<endl;
    cout<<dp[n]<<endl;
      //cout<<"case #"<<t<<": "<<;
  
}
 
signed main()
{
    fastio
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
}
                
