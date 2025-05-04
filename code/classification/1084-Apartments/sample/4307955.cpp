#include <iostream>
#include <algorithm>
using namespace std;
// const int mxN = ;
const int MOD = 1e9 + 7;
typedef long long int ll;
ll i, j, k, t, n, m;
 
int main()
{
    cin >> n >> m >> k;
    int desiredAptSize[n];
    int givenAptSize[m];
    for (i = 0; i < n; ++i)
        cin >> desiredAptSize[i];
    for (i = 0; i < m; ++i)
        cin >> givenAptSize[i];
    int ans = 0;
    sort(desiredAptSize, desiredAptSize + n);
    sort(givenAptSize, givenAptSize + m);
    j = 0; // givenAPT
    i = 0;
    while (i < n)
    {
        while (j < m && desiredAptSize[i] - k > givenAptSize[j])
            j++;
        if (j < m && abs(desiredAptSize[i] - givenAptSize[j]) <= k)
        {
            ans++;
            j++;
            i++;
        }
        else
            i++;
    }
    cout << ans;
    return 0;
}