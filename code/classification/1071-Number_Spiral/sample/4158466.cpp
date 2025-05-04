#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--)
	{
	    ll x,y;
	    cin>>x>>y;
	    ll ans=0;
	    if(x==y)
	    {
	        ans=x*x-x+1;
	    }
	    else if(x>y)
	    {
	        if(x%2==0)
	        ans=x*x-y+1;
	        else ans=(x-1)*(x-1)+y;
	    }
	    else
	    {
	        if(y%2!=0)
	        ans=y*y-x+1;
	        else ans=(y-1)*(y-1)+x;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
