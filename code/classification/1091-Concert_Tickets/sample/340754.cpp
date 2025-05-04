#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        h.insert(-tmp);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        auto it = h.lower_bound(-x);
        if (it == h.end())
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << -*it << '\n';
            h.erase(it);
        }
    }
}
