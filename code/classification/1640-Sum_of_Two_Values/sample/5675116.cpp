#include <bits/stdc++.h>
 
using namespace std;
 
int n, x;
 
int main()
{
    cin >> n >> x;
    bool done = 0;
    map<int, bool> m;
    map<int, int> po;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (m[x - a])
        {
            cout << po[x - a] << " " << i << "\n";
            done = 1;
            break;
        }
        m[a] = 1;
        po[a] = i;
    }
    if (!done)
    {
        cout << "IMPOSSIBLE\n";
    }
}