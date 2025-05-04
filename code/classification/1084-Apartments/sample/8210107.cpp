#include <iostream>
#include <algorithm>
#define int long long
 
using namespace std;
const int maxn=200005;
 
int a[maxn],b[maxn];
 
signed main()
{
    int n,m,K;cin>>n>>m>>K;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    
    int ans=0;
    for(int i=0,j=0;i<n;i++){
        while (j<n && a[j]<b[i]-K)j++;
        
        if(j==n)break;
        if(a[j]<=b[i]+K)ans++,j++;
    }
    cout<<ans<<'\n';
 
    return 0;
}
