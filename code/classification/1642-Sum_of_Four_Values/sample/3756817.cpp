#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    long long n, t;
    cin >> n >> t;
    std::vector<long long> v(n);
    for(long long i=0; i<n; i++)
        cin >> v[i];
    map<long long,vector<pair<long long,long long>>> mp;
    for(long long i=0;i<n;i++)
        for(long long j=i+1;j<n;j++)
            mp[v[i]+v[j]].push_back({i,j});
 
    for(auto m:mp)
        if(mp.find(t-m.first)!=mp.end())
        {
            vector<pair<long long,long long>> first = m.second;
            vector<pair<long long,long long>> second = mp[t-m.first];
            for(auto f:first)
                for(auto s:second)
                {
                    set<long long> st{f.first,f.second,s.first,s.second};
                    if(st.size()==4)
                    {
                        cout << f.first+1 <<" "<<f.second+1 <<" "<<s.first+1 << " "<< s.second+1;
                        return;
                    }
                }
                
        }
    cout << "IMPOSSIBLE";
}
 
int main()
{
    //freopen("t","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    long long test = 1;
    //cin>>test;
    while(test--)
        solve();
    return 0;
}