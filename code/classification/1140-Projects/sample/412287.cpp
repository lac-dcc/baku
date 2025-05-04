#include <bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
using namespace std;
map<int,int> reindex;
vector<vector<pii>> project(400005);
int start[200005], ending[200005], p[200005];
ll dp[400005];
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> start[i] >> ending[i] >> p[i];
        ending[i]++;
        reindex[start[i]], reindex[ending[i]];
    }
 
    int idx = 0;
    for(auto &v : reindex)
    {
        v.second = idx++;
    }
 
    for(int i = 0;i < n;i++)
    {
        project[reindex[ending[i]]].push_back({reindex[start[i]], p[i]});
    }
 
    for(int i = 0;i < idx;i++)
    {
        if(i > 0) dp[i] = dp[i - 1];
        for(auto j : project[i])
        {
            dp[i] = max(dp[i], dp[j.first] + j.second);
        }
    }
 
    printf("%lld\n", dp[idx - 1]);
    return 0;
}