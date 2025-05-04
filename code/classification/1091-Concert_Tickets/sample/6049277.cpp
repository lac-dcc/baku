#define RAGHAV_PATEL ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define int long long int
 
void solve()
{
    int n,t;
    cin >> n >> t;
 
    multiset<int>ms;
 
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ms.insert(x);
    }
    for(int i = 0; i < t; i++){
        int y;
        cin >> y;
       
        auto it = ms.upper_bound(y);
        if(it == ms.begin()){
            cout << -1<<"\n";
            continue; 
        }
        else{
            it--;
            cout<<(*it)<<"\n";
            ms.erase(it);
        }
 
    }
}
 
signed main()
{
    RAGHAV_PATEL
    int t, i;
    //cin >> t;
     t = 1;
 
    while (t)
    {
        solve();
        t--;
    }
}
