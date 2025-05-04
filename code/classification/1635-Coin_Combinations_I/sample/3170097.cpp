#include<bits/stdc++.h>
#define st first
#define nd second
#define ll long long
using namespace std;
const int MOD = 1e9+7;
ll a[106], dp[1000006];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    dp[0]=1;
    for(int i=0; i<n; i++){
        cin >> a[i];
       // dp[a[i]]+=1;
    }
    for(int i=0; i<=m; i++){
        for(int j=0; j<n; j++){
            if(i-a[j]<0) continue;
            dp[i]+=dp[i-a[j]];
            dp[i]%=MOD;
        }
        //cout << x << " " ;
        dp[i]%=MOD;
    }
    cout << dp[m];
}
