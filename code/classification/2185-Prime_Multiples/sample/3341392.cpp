#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int maxN=20;
 
ll a[maxN+1];
 
int main() {
    ll n;
    int k;
 
    cin >> n >> k;
 
    for (int i=0; i<k; ++i) {
        cin >> a[i];
    }
 
    ll res=0;
    for (int i=1; i<(1<<k); ++i) {
        ll num=1, cnt=0;
        for (int j=0; j<k; ++j) {
            if (i & (1<<j)) {
                cnt++;
                if (n/num<a[j]) {num=n+1; break;}
                num *= a[j];
            }
        }
        if (cnt%2==1) res+=n/num;
        else res-=n/num;
    }
 
    cout << res << endl;
 
    return 0;
}