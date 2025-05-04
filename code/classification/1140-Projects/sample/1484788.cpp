#include<bits/stdc++.h>
using namespace std;
int mod=1000000007;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
 
bool comp(vector<long>&t1,vector<long>&t2)
{
    if(t1[1]==t2[1])
        return t1[0]<t2[0];
    return t1[1]<t2[1];
}
 
 long solve(vector<vector<long>> &pro,vector<int>& endP,vector<long>&dp,int idx)
    {
        if(idx==-1)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int k=pro[idx][0];
        int i=upper_bound(endP.begin(),endP.end(),k-1)-endP.begin()-1;
        dp[idx]=max(solve(pro,endP,dp,idx-1),solve(pro,endP,dp,i)+pro[idx][2]);
        return dp[idx];
    }
 
int main()
{
    fast_io;
    int n;
    cin>>n;
    vector<vector<long>> pro;
    for(int i=0;i<n;i++)
    {
        vector<long> temp(3);
        cin>>temp[0]>>temp[1]>>temp[2];
        pro.push_back(temp);
    }
    sort(pro.begin(),pro.end(),comp);
    
    vector<int> endP(n);
    int i=0;
    for(auto k:pro)
        endP[i++]=k[1];
    vector<long>dp(n,-1);
    cout<<solve(pro,endP,dp,n-1)<<endl;
  
}