/*
Mokshith Ch  |,,|
*/
#include<bits/stdc++.h>
using namespace std;
 
#define   endl "\n"
#define int long long
 
const int N = 2e5 + 1;
const int mod = 1e9 + 7;
const int INF = 1e18;
#define debug(x) cout<<#x<<": "<<x<<endl;
 
void solve(int tc)
{
    int n,x;
    cin>>n>>x;
    vector<int> a(n/2),b(n-n/2);
    for(int i=0;i<n/2;i++){
        cin>>a[i];
    }
    for(int i=n/2;i<n;i++){
        cin>>b[i-n/2];
    }
    vector<int> low,high;
    for(int i=0;i<(1<<a.size());i++){
        int k=0;
        for(int j=0;j<a.size();j++){
            if(i& (1<<j)){
                k+=a[j];
            }
        }
        low.push_back(k);
    }
    for(int i=0;i<(1<<b.size());i++){
        int k=0;
        for(int j=0;j<b.size();j++){
            if(i& (1<<j)){
                k+=b[j];
            }
        }
        high.push_back(k);
    }
    
 
    int ans=0;
    sort(low.begin(), low.end());
    sort(high.begin(), high.end());
 
    for(int i :low){
 
        int i1=lower_bound(high.begin(), high.end(),x-i)-high.begin();
        int i2=upper_bound(high.begin(), high.end(),x-i)-high.begin();
 
        ans+=(i2-i1);
    }
 
    cout<<ans<<endl;
    
}
 
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1; 
    // cin>>t;
    for(int tc=1;tc<=t;tc++) solve(tc);
    return 0;
}
