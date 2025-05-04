#include <bits/stdc++.h>
using namespace std;
typedef  long long   lli ;  
#define rep(i,a,b)  for(i=a;i<b;i++)
#define ret return 0
const lli mxlli=1e18 ;
const int mxint = 1e9+7 ;
 
lli n,c[1000001],a[1000001];
 
lli f(lli x)
{
    int i; if(x==0) ret;
    if(x<0) return mxint;
    if(a[x]!=-1) return a[x];
    lli p=mxint;
    rep(i,0,n)
    {
        p=min(p,1+f(x-c[i]));
    }
    return a[x]=p;
 
}
 
 
int solv() 
{ 
    int i,x; cin>>n>>x;
    rep(i,0,n) cin>>c[i];
    rep(i,0,x+1) a[i]=-1;
    //cout<<"xc\n"; cout<<a[x]<<"\n";
    lli p=f(x);
    if(p>1000000) p=-1;
    cout<<p;
     
    
   
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int testcases=1;
    // cin>>testcases;
    while(testcases--)
    {
        solv();
    }
   
}