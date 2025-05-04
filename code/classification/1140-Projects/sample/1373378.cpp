#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int mod=1e9+7;
 
struct prct
{
    int x;
    int y;
    int p;
};
vector<int> V[400005];
prct arr[200005];
map<int,int>M;
long long dp[400005];
 
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i].x>>arr[i].y>>arr[i].p;
    for(int i=0;i<n;i++)M[arr[i].x]=-1, M[arr[i].y]=-1;
    int ind=0;
    for(PII u:M)M[u.first]=++ind;
    for(int i=0;i<n;i++)arr[i].x=M[arr[i].x], arr[i].y=M[arr[i].y];
    for(int i=0;i<n;i++)V[arr[i].y].push_back(i);
    for(int i=1;i<=ind;i++)
    {
        dp[i]=dp[i-1];
        for(int u:V[i])dp[i]=max(dp[i],dp[arr[u].x-1]+arr[u].p);
    }
    cout<<dp[ind]<<endl;
}
