#include<iostream>
#include<algorithm>
using namespace std;
 
int main()
{
    int n,x;
    cin>>n>>x;
    int arr[n],b[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        b[i] = arr[i];
    sort(arr,arr+n);
    bool f=0;
    int l,r;
    for(int i=0;i<n;i++)
    {
        int a=arr[i];
        int b = x-arr[i];
        if(b<a)
            break;
        int start = i+1,end=n-1;
        while(start<=end)
        {
            int mid = (start+end)>>1;
            if(arr[mid]==b)
            {
                f=1;
                l=arr[i];
                r=arr[mid];
                break;
            }
            if(arr[mid]>b)
                end = mid-1;
            else
                start = mid+1;
        }
        if(f)
            break;
    }
    if(f)
    {
        int s,t;
        if(l!=r)
        {
            for(int i=0;i<n;i++)
            {
                if(b[i]==l)
                    s=i+1;
                if(b[i]==r)
                    t=i+1;
            }
        }
        else
        {
            int i=0;
            for(;i<n;i++)
            {
                if(b[i]==l)
                {
                    s=i+1;
                    break;
                }
            }
            i++;
            for(;i<n;i++)
            {
                if(b[i]==r)
                {
                    t=i+1;
                    break;
                }
            }
        }
        cout<<min(s,t)<<" "<<max(s,t);
    }
    else
        cout<<"IMPOSSIBLE";
}