#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n;
    set<ll>a;
    for(int i=0;i<n;i++){
        cin>>m;
        a.insert(m);
    }
    cout<<a.size();
    return 0;
}
