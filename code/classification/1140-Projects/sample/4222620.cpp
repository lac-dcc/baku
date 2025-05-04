#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int mod = 1000000007;
 
struct node
{
    int start;
    int end;
    int profit;
};
 
 
bool comp(node a, node b)
{
    if(a.end <= b.end)
        return true;
    else
        return false;
}
 
 
int main()
{
    int N;
    cin>>N;
    
    vector<node>input(N);
    vector<ll>dp(N+1,0);
    
    for(int i=0; i<N; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        input[i].start = x;
        input[i].end = y;
        input[i].profit = z;
    }
        
    sort(input.begin(), input.end(), comp);
    
    dp[0] = 0;
    
    for(int cur=0; cur<N; cur++)
    {
        int low = 0;
        int high = cur-1;
        int lowBound = -1;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(input[mid].end < input[cur].start)
            {
                low = mid + 1;
                lowBound = mid;
            }
            else
                high = mid - 1;
        }
        
        dp[cur+1] = dp[cur];
        
        if(lowBound == -1)
            dp[cur+1] = max(dp[cur+1], (ll) input[cur].profit);
        else
            dp[cur+1] = max(dp[cur+1], dp[lowBound+1] + (ll) input[cur].profit);
    }
       
    // for(int i=0; i<=N; i++)
        // cout<<dp[i]<<"  ";
        
    cout<<dp[N]<<"\n";
    return 0;
}
