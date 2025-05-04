#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 
vector<int> findTwoSum(vector<vector<int>> &v, int i, int j, int target)
{
    vector<int> ans;
    while (i < j)
    {
        int sum = v[i][0] + v[j][0];
        if (target == sum)
        {
            ans.push_back(v[i][1]);
            ans.push_back(v[j][1]);
            return ans;
        }
        else if (target > sum)
        {
            i++;
        }
        else
            j--;
    }
    return ans;
}
 
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v.push_back({val, i + 1});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        int val1 = v[i][0];
        for (int j = i + 1; j < n; j++)
        {
            int val2 = v[j][0];
            int target = x - val1 - val2;
            int k = j + 1, l = n - 1;
            vector<int> twoSum = findTwoSum(v, k, l, target);
            if (twoSum.size() > 0)
            {
                cout << v[i][1] << " " << v[j][1] << " " << twoSum[0] << " " << twoSum[1];
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
