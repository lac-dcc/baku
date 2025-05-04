#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define tr(a,b,i) for(int i=a;i<b;i++)
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll t;
    cin>>t;
    for(ll i=0;i<t;i++)
    {
        ll m,n;
        cin>>m>>n;
        ll p=max(m,n);
        if(p%2==0)
        {
            if(n==p)
            {
                cout<<(p-1)*(p-1)+m<<"\n";
            }
            else
            {
                cout<<(p)*(p)-n+1<<"\n";
            }
        }
        else
        {
            if(m==p)
            {
                cout<<(p-1)*(p-1)+n<<"\n";
            }
            else
            {
                cout<<(p)*(p)-m+1<<"\n";
            }
 
 
        }
    }
    return 0;
}
