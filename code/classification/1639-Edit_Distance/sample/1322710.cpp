#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pii = pair<int,int>;
#define f first
#define s second
#define mp make_pair
int mod = 1e9+7;
int n,m,maior;
string a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b;
    n = sz(a);
    m = sz(b);
    vector<vi> dp(n+1, vi(m+1,1e9));
    dp[0][0] = 0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i){
                dp[i][j] = 1 + dp[i-1][j];
            }
            if(j){
                dp[i][j] = min(1 + dp[i][j-1],dp[i][j]); 
            }
            if(i && j){
                dp[i][j] = min(dp[i-1][j-1] + (a[i-1]!=b[j-1]), dp[i][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}