#include <bits/stdc++.h>
#define nline "\n"
#define ll long long
#define pll pair<long long>
#define loop(x, n) for (int x = 0; x < n; ++x)
#define rloop(x, n) for (int x = n - 1; x >= 0; --x)
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while(t--)
    {
        int n;
        cin>>n;
        set<pair<int,int>> s;
        loop(i,n)
        {
            int a,b;
            cin>>a>>b;
            s.insert({a,1});
            s.insert({b,-1});
        }
        int ans=0,sum=0;
        for(auto k:s)
        {
            sum+=k.second;
            ans=max(ans,sum);
        }
        cout<<ans<<endl;
    }
}
