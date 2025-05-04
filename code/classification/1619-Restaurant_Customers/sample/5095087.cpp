#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n;cin>>n;
    set<array<ll,2>> s;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        s.insert({2*x,1});
        s.insert({2*y+1,-1});
    }
    ll c=0,ans=0;
    for(auto a: s){
        c+=a[1];
        ans= max(ans,c);
    }
    
    cout<<ans;
}
