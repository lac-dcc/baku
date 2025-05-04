#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (currSum + a[i] < a[i])
        {
            currSum = a[i];
        }
        else
        {
            currSum = currSum + a[i];
        }
        maxSum = max(maxSum, currSum);
    }
    cout << maxSum << endl;
}
