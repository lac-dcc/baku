#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
 
signed main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxsub[n];
    maxsub[0]=a[0];
    for(int i=1;i<n;i++){
        maxsub[i]=max(maxsub[i-1]+a[i],a[i]);
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,maxsub[i]);
    }
    cout<<ans<<endl;
}