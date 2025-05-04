#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n+5],brr[m+5];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<m;i++)
        cin>>brr[i];
    sort(arr,arr+n);
    sort(brr,brr+m);
    int i=0,j=0,ans=0;
    while(i<n&&j<m)
    {
        if(abs(arr[i]-brr[j])<=k)
        {
            ans++;
            i++;
            j++;
        }
        else
        {
            if(arr[i]-brr[j]>k)
                j++;
            else
                i++;
        }
    }
    cout<<ans<<endl;
 
  return 0;
}