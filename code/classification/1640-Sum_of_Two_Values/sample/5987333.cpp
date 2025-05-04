#include <bits/stdc++.h>
using namespace std;
 
const int maxN = 2*1e5;
 
int n, x;
int a[maxN];
bool found = false;
map<int, pair<int, int>> pos;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (pos[a[i]].first == 0)
            pos[a[i]].first = i+1;
        else if (pos[a[i]].second == 0)
            pos[a[i]].second = i+1;
    }
    for (int i = 0; i < n && !found; i++) if (pos.find(x-a[i]) != pos.end())
    {
        if (a[i]*2 == x && pos[a[i]].second == 0) continue;
        found = true;
        cout << i+1 << ' ' << max(pos[x-a[i]].first, pos[x-a[i]].second) << '\n';
    }
 
    if (!found)
        cout << "IMPOSSIBLE\n";
 
    return 0;
}