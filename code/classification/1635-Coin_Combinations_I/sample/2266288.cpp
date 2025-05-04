#include <iostream>
using namespace std;
#define int long long int
 
int32_t main() {
    int mod=1000000007;
    int n;cin>>n;int sum;cin>>sum;
    int arr[n+1]; for(int i=0;i<n;i++){cin>>arr[i];}
    int dp[1000001]={0};
    dp[0]=1;
    for(int i=1;i<=sum;i++){
        for(int j=0;j<n;j++){
            if(i-arr[j]>=0){
                dp[i]+=(dp[i-arr[j]])%mod;
            }
        }
 
    }
    cout<<(dp[sum])%mod<<endl;
 
 
 
    return 0;
}
