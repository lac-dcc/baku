#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main()
{    
    int n,x;
    cin>>n>>x;
 
    vector<pair<int,int>> nums;
 
    for(int e=0;e<n;e++)
    {
        int i;cin>>i;
        nums.push_back({i,e+1});
    }
 
    sort(nums.begin(),nums.end());
 
    int i=0,j=n-1;
 
    while(i<j)
    {
        if(nums[i].first+nums[j].first<x)
        {
            i++;
        }
        else if(nums[i].first+nums[j].first>x)
        {
            j--;
        }
        else
        {
            break;
        }
    }
 
    if(i!=j)
    {
        cout<<nums[i].second<<" "<<nums[j].second;
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
    
    return 0;
}