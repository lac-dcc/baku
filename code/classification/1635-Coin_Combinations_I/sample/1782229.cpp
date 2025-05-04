#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
 
using namespace std;
 
const int mod=1e9+7;
int n,x;
int a[105];
int dp[1000006];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    dp[0]=1;
    
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(a[j]<=i){
                dp[i]=(dp[i]+dp[i-a[j]])%mod;
            }
        }
    }
    
    cout << dp[x];
    
}
