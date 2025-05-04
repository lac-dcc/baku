#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);
int main(){
    ll n;
    cin>>n;
    ll a[n];
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    int ans=s.size();
    cout<<ans<<endl;    
    return 0;
}