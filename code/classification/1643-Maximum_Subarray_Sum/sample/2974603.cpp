#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
    int n=1;
    cin>>n;
    vector<int> v(n,0);
    int mini=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        mini= max(mini,v[i]);
    }
 
    long long sum=0,ans=0;   
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        
        if(sum<0)
        sum=0;
 
        ans=max(ans,sum);
        
    }
    if(ans==0)
    cout<<mini;
    else
    cout<<ans;
}