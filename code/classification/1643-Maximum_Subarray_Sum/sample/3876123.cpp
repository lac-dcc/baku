/*
code by harsha_76
 
*/
 
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef std::vector<int> vi;
 
#define all(x) x.begin(), x.end()
#define rep(i, start, end) for(int i=start;i<end;i++)
//kadane's algorithm
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin>>n;
    vi a(n);
    rep(i, 0, n) cin>>a[i];
    ll sum=0;
    ll ans=-INT_MAX;
    rep(i, 0, n)
    {
        sum=max(static_cast<ll>(a[i]), sum+a[i]);
        ans=max(sum, ans);
    }
    cout<<ans<<'\n';
    
    return 0;
}