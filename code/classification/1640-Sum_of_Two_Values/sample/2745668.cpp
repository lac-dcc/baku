#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
 
 
int main()
{
    
    ll int n,x;
    cin>>n>>x;
    
    vector<pair<ll, ll>> a;
    for(ll int i=0; i<n; i++)
    {
        ll int value;
        cin>>value;
        a.pb({value, i+1});
    }
    
    if(n==1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        sort(a.begin(), a.end());
        
        
        ll int tot = a[0].first + a[n-1].first;
        
        ll int lo = 0, hi = n-1;
        
        while(lo<hi)
        {
            if(a[lo].first+a[hi].first==x)
            {
                break;
            }
            else if(a[lo].first+a[hi].first > x)
            {
                hi--;
            }
            else
            {
                lo++;
            }
        }
        if(lo<hi)
        {
            cout<<a[hi].second<<" "<<a[lo].second<<endl;
        }
        else
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        
    }
    
    
    
    
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
