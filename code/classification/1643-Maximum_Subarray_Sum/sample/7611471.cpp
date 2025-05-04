//using kadanes algorithm
#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n ;
    cin>>n ;
    long long arr[n] ;
    for(int i=0;i<n;i++){
        cin>>arr[i] ;
    }
    //kadanes algorithm
    long long ans = INT_MIN ;
    long long sum = 0 ;
    for(int i=0;i<n;i++){
        sum+= arr[i] ;
        ans = max(ans,sum) ;
        if(sum<=0){   //anytime the sum is less than zero we abandon the subarray till this point
            sum = 0 ;
        }
    }
    cout<<ans ;
    return 0;
}
