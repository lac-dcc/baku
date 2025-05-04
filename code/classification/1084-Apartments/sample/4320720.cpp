#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int des[n + 1], siz[m + 1];
    for (int i = 0; i < n; i++)
        cin >> des[i];
    for (int i = 0; i < m; i++)
        cin >> siz[i];
    sort(des, des + n);
    sort(siz, siz + m);
    int i = 0, j = 0;
    int cnt = 0;
    while (i < n && j < m)
    {
        if (abs(des[i] - siz[j]) <= k)
        {
            cnt++;
            i++, j++;
        }
        else if ((des[i] - siz[j]) > k)
            j++;
        else
            i++;
    }
    cout << cnt << endl;
}