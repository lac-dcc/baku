#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
 
int main() 
{ 
    
        ll n;
        cin>>n;
        set<ll>s;
        for(ll i=0;i<n;i++)
        {
            ll a;
	    cin>>a;
            s.insert(a);
        }
        cout<<s.size()<<endl;
    return 0; 
}
