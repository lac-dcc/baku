#include <bits/stdc++.h>
#define int long long
#define gcd __gcd
#define mod 1000000007
using namespace std;
 
void solve()
{
    int n,x,a;
    cin>>n>>x;
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++)
    {
        cin>>a;
        v.push_back({a,i});
    }
    sort(v.begin(),v.end());
    for(int i = 0;i<n;i++)
    {
        int s1 = x - v[i].first;
        int ind = -1;
        int l = 0, r = n-1;
        while(l<=r)
        {
            int mid = l + (r - l)/2;
            if(v[mid].first==s1)
            {
                ind = v[mid].second;
                break;
            }
            if(v[mid].first>s1)
            {
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        if(ind!=-1 && ind!=v[i].second)
        {
            cout<<v[i].second+1<<" "<<ind+1;
            return;
        }
    }
    cout<<"IMPOSSIBLE";
    
    
 
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // int t;
    // cin >> t;
    // while(t--)
    // {
       solve();
    // }
    return 0;
}