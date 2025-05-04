#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define fori for (int i = 0; i < n; i++)
int main()
{
 
    int t; cin>>t;
    while(t--)
    {
        ll ans;
        ll x,y; cin>>x>>y;
        if(x>y)
        {
            if(x%2==0)
            {
               ans=x*x - (y-1); 
            }
            else
            ans=(x-1)*(x-1) +1 +(y-1);
        }
 
        else{
            if(y%2!=0)
            ans=y*y -(x-1);
 
            else
            ans=(y-1)*(y-1) + 1 +(x-1);
        }
        cout<<ans<<"\n";
    }
}
