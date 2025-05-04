#include <bits/stdc++.h>
using namespace std;
 
#define vi vector<int>
#define ll long long
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define For(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) __builtin_popcount(x)
 
int main()
{
 
    int n;
    ll sum;
    cin >> n >> sum;
    vector<vector<ll>> vec(n, vector<ll>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i][0];
        vec[i][1] = i;
    }
 
    sort(vec.begin(), vec.end());
    bool ans = false;
    for (int i = 0; i < n - 3; i++)
    {
        if (i >= 1)
        {
            if (vec[i - 1][0] == vec[i][0])
                continue;
        }
 
        for (int j = i + 1; j < n - 2; j++)
        {
            if(j > i +1){
                if(vec[j-1][0]==vec[j][0])
                 continue;
            }
            ll req = sum - vec[i][0] - vec[j][0];
            int l = j + 1;
            int r = n - 1;
 
            while (l < r)
            {
                ll curr_sum = (ll)vec[l][0] + (ll)vec[r][0];
 
                if (curr_sum == req)
                {
                    vector<ll> ans1 = {vec[i][1] + 1,vec[j][1]+1,vec[l][1] + 1, vec[r][1] + 1};
                    sort(ans1.begin(), ans1.end());
                    cout << ans1[0] << " " << ans1[1] << " " << ans1[2] << " " << ans1[3] << endl;
                    ans = true;
                    break;
                }
                else if (curr_sum < req)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            if (ans)
            {
                break;
            }
        }
        if (ans)
        {
            break;
        }
    }
    if (!ans)
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
