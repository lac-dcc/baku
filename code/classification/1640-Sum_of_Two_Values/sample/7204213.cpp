#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int n,sum; cin>>n>>sum;
    map <int,int> mp,vt;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]=1;
        if(vt[a[i]]==0) vt[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(mp[sum-a[i]]==1 && i!=vt[sum-a[i]])
        {
            cout<<i<<" "<<vt[sum-a[i]];
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
