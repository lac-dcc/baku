#include <bits/stdc++.h>
#define reu(i,a,b) for (int i=a;i<=b;++i)
//KADANE TIM SUM MAX LIEN TIEP
 
using namespace std;
long long n,a[200001];
int main()
{
    cin>>n;
    reu(i,1,n) cin>>a[i];
    long long res=0,ans=a[1];
    reu(i,1,n)
    {
        if (res<0)
        {
            res=a[i];
            ans=max(ans,res);
        } else {res=a[i]+res;ans=max(ans,res);}
    }
    cout<<ans;
    return 0;
}
