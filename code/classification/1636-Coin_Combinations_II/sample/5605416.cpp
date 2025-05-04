#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<long long int>
#define endl "\n"
const int N=1e6;
vi dp(N+1,0);
 
 
void solve(){
    int n,x; cin>>n>>x;
    vi v(n);
    int p=1e9+7;
    dp[0]=1;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j>=v[i]) dp[j]=((dp[j])%p+(dp[j-v[i]])%p)%p;
            // cout<<j<<" "<<dp[j]<<endl;
        }
    }
    cout<<dp[x]<<endl;
}
 
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}