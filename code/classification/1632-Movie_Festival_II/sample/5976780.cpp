#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define ip pair<ll, ll>
using namespace std;
bool comparator (const ip &a, const ip &b){
    return (a.second<b.second);
}
int main(){
    FAST
    ll n,m, result=0, maxval=1e9+1;
    cin>>n>>m;
    vector <ip> a(n+1);
    multiset <ll> b;
    for (int i=1; i<=n; i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(), a.end(), comparator);
    for (int i=1; i<=m; i++){
        b.insert(0);
    }
    b.insert(maxval);
    for (int i=1; i<=n; i++){
        multiset <ll>::iterator itr=b.upper_bound(a[i].first);
        while (itr!=b.begin() && *itr > a[i].first) itr--;
        if (itr==b.begin() && *itr>a[i].first) {
            continue;
        } else {
            result++;
            b.erase(itr);
            b.insert(a[i].second);
        }
    }
    cout<<result;
}