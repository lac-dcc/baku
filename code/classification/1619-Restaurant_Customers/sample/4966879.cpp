#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[200005],c[200005];
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("FILE.INP","r",stdin);
    //freopen("FILE.OUT","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>c[i];
    sort(a,a+n);
    sort(c,c+n);
    int i=0,j=0;
    int s=0,mx=0;
 
    while(i<n)
    {
        s++;
        while(a[i]>=c[j])
            s--,j++;
        mx=max(mx,s);
        i++;
    }
    cout<<mx;
    return 0;
}
