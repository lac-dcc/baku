#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip>
#include<math.h>
#include<string>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define ll long long
#define ld long double
#include <sstream>
#include<map>
#define lop(n) for(ll i=0;i<n;i++)
#define loop(a,b) for(ll i=a;i<b;i++)
#include <cstring>
#define MOD 1000000007
#define en "\n"
#define F first
#define S second
#define inputlist for(ll i=0;i<n;i++) cin>>A[i]
#define pb(x) push_back(x)
#define MP make_pair
#define PI 3.14159265
 
// Driver program
 
//
 
void solve()
{
    ll n;
    cin>>n;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++)
    {
        ll a;
        cin>>a;
        mp[a]++;
    }
    cout<<mp.size()<<en;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    //cin>>t;
    for(ll i=1;i<=t;i++)
    {
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
 
