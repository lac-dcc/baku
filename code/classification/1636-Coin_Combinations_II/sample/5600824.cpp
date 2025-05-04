//samoJako:)
#include <bits/stdc++.h> 
using namespace std;
 
#define all(v) v.begin(),v.end()
#define ceil_div(x, y) x / y + (x % y != 0)
#define fast_cin() ios::sync_with_stdio(false); cin.tie(0)
 
typedef long long ll;
const int mod = 1000000007;
int c[101];
int dp[1000002];
int n;
 
int main(){
    fast_cin();
    int x; cin>>n>>x;
    dp[0]=1;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c,c+n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= x; j++){
            if(j-c[i]>=0){
                dp[j]+=dp[j-c[i]];
                dp[j]%=mod;
            }
        }   
    }
    
    cout<<dp[x]<<endl;
    return 0;
}