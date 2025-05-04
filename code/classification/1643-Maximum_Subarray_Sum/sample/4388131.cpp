#include<bits/stdc++.h>
using namespace std;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
 
#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
 
void test(){
    ll n;
    cin>>n;
    ll curr=0;
    ll res=-1e18;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (ll i = 0; i < n; i++)
    {
        curr+=a[i];
        res=max(res,curr);
        if(curr<0)curr=0;
    }    
    cout<<res;
    cout<<endl;
}
 
int main()
{
    fastread();
    test();
    return 0;
}