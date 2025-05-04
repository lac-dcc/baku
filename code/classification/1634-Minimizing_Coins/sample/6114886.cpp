#include<bits/stdc++.h>
using namespace std;
 
int dp[10000005];
 
int main(){
    int n, x, num;
    scanf("%d %d", &n, &x);
    for(int i=0;i<=x;i++){
        dp[i] = INT_MAX-1;
    }
    vector<int>vec;
    for(int i=0;i<n;i++){
        scanf("%d", &num);
        vec.push_back(num);
        dp[num] = 1;
    }
 
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i<=vec[j]){
                continue;
            }
            dp[i] = min(dp[i], dp[i-vec[j]] + 1);
        }
    }
    if(dp[x] == INT_MAX-1){
        printf("-1\n");
    }
    else{
        printf("%d\n", dp[x]);
    }
    
}