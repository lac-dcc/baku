#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pi;
 
 
 
int main() {
    //ifstream fin("wormsort.in");
    //ofstream fout("wormsort.out");
    //freopen("snowboots.in", "r", stdin);
    //freopen("snowboots.out", "w", stdout);
    
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> minps(n);
    minps[0] = min(0LL, a[0]);
    ll cs = a[0];
    for (int i = 1; i < n; i++) {
        cs += a[i];
        minps[i] = min(minps[i-1], cs);
    }
    
    cs = a[0];
    ll mv = a[0];
    for (int i = 1; i < n; i++) {
        cs += a[i];
        mv = max(mv, cs-minps[i-1]);
    }
    
    cout << mv << endl;
}
