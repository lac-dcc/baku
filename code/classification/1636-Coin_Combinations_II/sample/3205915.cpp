#include <bits/stdc++.h>
#define maxn (int)(1e5+51)
#define all(x) x.begin(), x.end()
#define sz(x) (int) x.size()
#define endl '\n'
#define ll long long
#define pb push_back
#define ull unsigned long long
#define ii pair<int,int>
#define iii tuple<int,int,int>
#define inf (int)(2e9+1)
#define mod (int)(1e9+7)
 
using namespace std;
int v[100],dp[101][1000001];
 
void sum(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,x;cin>>n>>x;
    for(int i=0;i<n;i++)
        cin>>v[i];   
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j]=dp[i-1][j];
            if(j-v[i-1]>=0){
                sum(dp[i][j],dp[i][j-v[i-1]]);
            }
        }
    }
 
    cout<<dp[n][x]<<endl;
}