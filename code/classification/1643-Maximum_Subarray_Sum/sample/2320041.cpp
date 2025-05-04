#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll toInt(string s){ll  sm ; stringstream ss(s); ss >> sm; return sm;}
// sum = (sum + a[i] + MOD) % MOD;
void baal()
{
    ll n; cin >> n; vector < ll > a(n , 0); ll mx = -INT_MAX, s = 0;
    for(auto &i : a)
    {
        cin >> i;
        s += i;
        mx = max(mx, s);
        s = max(0LL, s);
    }
    cout << mx << endl; return;
 
}
 
int main()
{
    ll t = 1;
    while(t--)
    {
        baal();
    }
}
 