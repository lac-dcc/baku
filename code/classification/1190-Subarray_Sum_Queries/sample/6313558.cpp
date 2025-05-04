#include <bits/stdc++.h>
 
using namespace std;
const int N =2e5+80;
long long ans[4*N];
const long  INF= 1e18;
long long prefix[N+2];
long long max1[4*N+2];
long long min1[4*N+2];
long long lazy[4*N+2];
long long a[N+2];
void push(int id){
    long long t=lazy[id];
    lazy[id*2]+=t;
    lazy[id*2+1]+=t;
    max1[id*2]+=t;
    max1[id*2+1]+=t;
    min1[id*2]+=t;
    min1[id*2+1]+=t;
    lazy[id]=0;
}
void update(int id, int l ,int r, int u, int v, long long val){
    if(l>v||r<u){
        return;
    }
    if(l>=u&&v>=r){
        max1[id]+=val;
        min1[id]+=val;
        lazy[id]+=val;
        return ;
    }
    push(id);
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    max1[id]=max(max1[id*2],max1[id*2+1]);
    min1[id]=min(min1[id*2],min1[id*2+1]);
    ans[id]=max(ans[id*2],max(ans[id*2+1],max1[id*2+1]-min1[id*2]));
}
int main()
{
   int n,m;
   cin>>n>>m;
   prefix[0]=0;
   update(1,0,n,0,0,0);
   for(int i=1;i<=n;i++){
    cin>>a[i];
    prefix[i]=prefix[i-1]+a[i];
    update(1,0,n,i,i,prefix[i]);
   }
   while(m--){
    int k; long long x;
    cin>>k>>x;
    update(1,0,n,k,n,-a[k]);
    update(1,0,n,k,n,x);
    a[k]=x;
    cout<<ans[1]<<"\n";
   }
    return 0;
}
