#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
vector<pair<pair<int, int>, int>> projects(2 * 100001);
ll dp[2 * 100001];
ll N;
ll solve(int index)
{
 
    ll currDay = projects[index].first.second;
 
    if (index >= N)
        return 0;
    else if (dp[index] != -1)
        return dp[index];
    ll L = index, R = N, mid, ans = N;
    while (L <= R)
    {
        mid = L + ((R - L) / 2);
        if (projects[mid].first.first <= currDay)
            L = mid + 1;
        else
        {
            R = mid - 1;
            ans = mid;
        }
    }
    ll finalAns = 0;
    finalAns = max(solve(index + 1), solve(ans) + projects[index].second);
    dp[index] = finalAns;
    return finalAns;
}
 
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.first.first < b.first.first;
}
 
int main()
{
    cin >> N;
    for (int x = 0; x < N; x++)
    {
        dp[x] = -1;
        cin >> projects[x].first.first >> projects[x].first.second >> projects[x].second;
    }
    sort(projects.begin(), projects.begin() + N, cmp);
    cout << solve(0);
}
