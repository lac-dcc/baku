#include <bits/stdc++.h>
 
using namespace std;
 
int n,m;
int k;
int a[200001];
int b[200001];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0;
    int res = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= k)
        {
            i++;
            j++;
            res++;
        }
        else if (a[i] - b[j] > k) j++; else i++;
    };
    cout << res;
}
