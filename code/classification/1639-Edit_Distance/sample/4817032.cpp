#include <iostream>
#include <string>
 
using namespace std;
 
int dp[5001][5001] = {0};
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string x,y;
    cin>>x;
    cin>>y;
    int n1 = x.size();
    int n2 = y.size();
    
    for(int i=0;i<n1+1;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<n2+1;j++){
        dp[0][j] = j;
    }
 
    for(int i=1;i<n1+1;i++){
        for(int j=1;j<n2+1;j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
            }
        }
    }
    
    cout<<dp[n1][n2];
 
    return 0;
}