#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    while ((n--) != 0)
    {
        int tick;
        cin >> tick;
        ms.insert(tick);
    }
    queue<int> q;
    while (m--)
    {
        int user;
        cin >> user;
        q.push(user);
    }
    while (!q.empty())
    {
        int x = q.front();
        auto it = ms.upper_bound(x);
        if (it == ms.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *(--it) << endl;
            ms.erase(it);
        }
        q.pop();
    }
    return 0;
}
