#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
 
    ll n;
    cin>>n;
    ll tmp;
    map<ll,ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin>>tmp;
        mp[tmp]++;
    }
    
    
    
    cout<<mp.size()<<endl;
    
 
}