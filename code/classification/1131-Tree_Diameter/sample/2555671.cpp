#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define take(a, b, c)           \
    for (int i = a; i < b; i++) \
    {                           \
        cin >> c[i];            \
    }
#define SZ 200005
#define par pair<int, int>
int mod = 1e9 + 7;
int n;
vector<int> arr[SZ];
vector<int> clist[SZ];
vector<int> distanceR(SZ, 0);
void toL(int s, int e)
{
    for (auto u : arr[s])
    {
        if (u != e)
        {
            toL(u, s);
            clist[s].push_back(u);
            distanceR[s] = max(distanceR[s], distanceR[u] + 1);
        }
    }
}
 
 
int main()
{
    IOS;
    cin >> n;
 
    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        arr[y].push_back(x);
        arr[x].push_back(y);
    }
    toL(1, 0);
    int maxdia = -1;
    for (int i = 1; i <= n; i++)
    {
        multiset<int> ms1;
        int ans = 0;
        for (auto u : clist[i])
            ms1.insert(distanceR[u] + 1);
        int j = 0;
        for (auto it = ms1.rbegin(); j < 2 && it != ms1.rend(); j++, ++it)
            ans += *it;
        maxdia = max(maxdia, ans);
    }
    cout << maxdia;
 
    return 0;
}
