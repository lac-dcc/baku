#include<bits/stdc++.h>
 
#define inp 200005
#define check exit(0)
#define nl cout<<endl;
#define mod 1000000007 
#define ll long long int
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define jaldi ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define deb(v) for(int i=0;i<v.size();i++) {cout<<v[i]; (i==v.size()-1) ? cout<<"\n":cout<<" "; }
 
using namespace std;
 
// Pick yourself up, 'cause...
 
int main()
{
    jaldi
 
    int n;
    cin>>n;
 
    vector<int> v(n);
    for(int &x:v) cin>>x;
 
    ll ans=*max_element(v.begin(),v.end());
    ll till=0;
 
    for(int i=0;i<n;i++)
    {
        till+=v[i];
        ans=max(ans,till);
        till=max(till,0ll);
    }
 
    cout<<ans;
    
    return 0;
}