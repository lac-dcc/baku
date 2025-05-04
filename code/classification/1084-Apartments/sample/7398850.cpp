#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
#define int long long
int32_t main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>v1(n),v2(m);
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
        v1[i]-=k;
    }
    for(int i=0;i<m;i++)
        cin>>v2[i];
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i=0,j=0,res=0;
    while(i<n&&j<m)
    {
        if(v1[i]<=v2[j]&&v1[i]+2*k>=v2[j])
        {
            res++;
            i++;
            j++;
        }
        else if(v1[i]>v2[j])
            j++;
        else
            i++;
    }
    cout<<res;
    return 0;
}
