#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,m;
    cin>>n>>m;
    multiset <ll> s;
    for (ll i=1,x ;i<=n; i++){
        cin>>x;
        s.insert(x);
    }
    for (ll i=1,x; i<=m; i++){
        cin>>x;
        s.insert(x);
        auto it=s.upper_bound(x); it--;
        if (it==s.begin()){
            cout<<-1<<"\n";
            s.erase(s.find(x));
        }
        else {
            it--;
            cout<<*it<<"\n";
            s.erase(s.find(*it));
            s.erase(s.find(x));
        }
    }
}
