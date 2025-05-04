#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
#define all(x) x.begin(),x.end()
#define Test unsigned int TC; cin >> TC; while(TC--)
#define debug(x) cout << '\t' << #x << " is " << x << '\n'
#define repeat(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
 
void Solve()
{
    int n; cin >> n;
 
    vector<LL> v(n);
 
    for (auto &i : v)
        cin >> i;
 
    for (int i = 1; i < n; i++)
        v[i] += v[i - 1];
    
    set<LL> s(all(v));
    
    LL mxDif = -2e18, mx = *s.rbegin();
 
    for (LL i = n - 1, mn; i > 0; i--)
    {
        s.erase(v[i]);
        mn = *s.begin();
        mxDif = max(mxDif, v[i] - mn);
    }
 
    cout << max(mxDif, mx);
 
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    Solve();
 
    return 0;
}