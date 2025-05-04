#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
 
int main() {
    ll n,m,k; cin >> n >> m >> k;
    vector<ll> app;
    vector<ll> apa;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        app.push_back(x);
    }
    for(ll i = 0; i < m; i++) {
        ll x; cin >> x;
        apa.push_back(x);
    }
    sort(app.begin(),app.end());
    sort(apa.begin(),apa.end());
    ll appptr = 0; ll apaptr = 0;
    ll cnt = 0;
    while(appptr < n && apaptr < m) {
        while(apa[apaptr] < app[appptr] - k && apaptr < m) apaptr++;
        if(apaptr < m && apa[apaptr] - k <= app[appptr])  {
            cnt++;
            apaptr++;
        }
        //cout << appptr << ' ' << apaptr << ' ' << cnt << endl;
        appptr++;
    }
    cout << cnt;
    return 0;
}
