#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int cns = 1e9 + 7;
 
int main()
{
    int n,x,i,j;
    cin >> n >> x;
    vector<int>arr(n);
    
    for(i=0; i<n; i++){
        cin >> arr[i];
    }
    
    vector<int>dp(x+1, 0);
    dp[0] = 1;
    sort(arr.begin(), arr.end());
    for(j=0; j<n; j++){
        for(i=1; i<=x; i++){
            if( (i-arr[j]) >=0 ){
                dp[i] = (dp[i]%cns + dp[i-arr[j]]%cns)%cns;
            }
        }   
    }
    
    cout<<dp[x]<<endl;
    //return dp[x];
    
}