#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n;
pair<pair<int,int>,long long> a[200010];
long long mx[200010];
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].f.s>>a[i].f.f>>a[i].s;
    sort(a+1,a+1+n);
    mx[0]=0;
    for(int i=1;i<=n;i++)
    {
        mx[i]=mx[i-1];
        int l=0,r=i-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[mid].f.f<a[i].f.s)
            {
                mx[i]=max(mx[i],mx[mid]+a[i].s);
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
    }
    cout<<mx[n]<<'\n';
}