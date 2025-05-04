#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    string a,b;
    cin>>a>>b;
    
    int n=(int)a.size();
    int m=(int)b.size();
    
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i<=n;i++){
        dp[i][m]=n-i;
    }
    
    for(int i=0;i<=m;i++)
        dp[n][i]=m-i;
        
    
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(a[i]==b[j])
                dp[i][j]=dp[i+1][j+1];
                
            else{
                dp[i][j]=1+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
            }
        }
    }
    
    cout<<dp[0][0]<<endl;
}