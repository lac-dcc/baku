#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for(auto &i : v) cin >> i.first;
    for(int i = 0; i < n; i++) v[i].second = i;
    sort(v.begin(), v.end());
    map<int, pair<int, int>> mp;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            mp[v[i].first + v[j].first] = {i, j};
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            int targ = x - v[i].first - v[j].first;
            if(mp.count(targ) && mp[targ].first > j)
            {
                cout << v[i].second + 1 << ' ' << v[j].second + 1 << ' ' << v[mp[targ].first].second + 1
                << ' ' << v[mp[targ].second].second + 1 << '\n';
                return 0;  
            }
        }
    }
    cout << "IMPOSSIBLE";
}    
