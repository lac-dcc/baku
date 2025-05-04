#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
void solve() {
    ll n,m,k;
    cin>>n>>m>>k;
    ll a[n];
    ll b[m];
    for(ll i = 0;i<n;i++) 
        cin>>a[i];
    for(ll j = 0;j<m;j++)  
        cin>>b[j];
    
    sort(a,a+n);
    sort(b,b+m);
    
    ll i = 0, j = 0, ans = 0;
    while(i < n && j < m){
        if(abs(a[i] - b[j]) <= k){
            i++;
            j++;
            ans++;
        }
        else {
            if(a[i] - b[j] > k)
                j++;
            else 
                i++;
        }
    }
    cout<<ans;
    
    
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    //int t;
    //cin >> t;
    //while (t--)
      solve();
 
    return 0;
}