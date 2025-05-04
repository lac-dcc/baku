//Jai Jagannath
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define input(a,n) for(ll i=0;i<n;i++)cin>>a[i]
#define input1(a,n) for(ll i=1;i<=n;i++)cin>>a[i]
#define pll pair<ll,ll>
#define svl multiset<ll>
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    vector<pll>a;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        a.push_back(mp(x,1));
        a.push_back(mp(y,-1));
    }
    sort(all(a));
    ll count =0;
    ll ans=0;
    for(ll i=0;i<a.size();i++){
        count+=a[i].second;
        ans=max(ans,count);
    }
    cout<<ans;
 
 
 
 
 
}
