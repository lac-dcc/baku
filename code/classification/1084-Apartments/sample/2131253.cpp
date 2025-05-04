#include <bits/stdc++.h>
using namespace std;
 
bool search(vector<pair<long, bool>> &v, long target1, long target2)
{
    long low = 0, high = v.size() - 1, index = -1;
    while (low <= high)
    {
        long mid = (high - (high - low) / 2);
        if (v[mid].first >= target1 and v[mid].first <= target2 and v[mid].second == false)
        {
            high = mid - 1;
            index = mid;
        }
        if (v[mid].second == true)
        {
            low = mid + 1;
        }
        if (v[mid].first > target2)
        {
            high = mid - 1;
        }
        if (v[mid].first < target1)
        {
            low = mid + 1;
        }
    }
    if (index != -1)
    {
        v[index].second = true;
        return true;
    }
    return false;
}
 
int main()
{
    int n, m, k;
    scanf("%ld %ld %ld", &n, &m, &k);
    long *desired = new long[n];
    vector<pair<long, bool>> size;
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &desired[i]);
    }
    for (int i = 0; i < m; i++)
    {
        long num;
        scanf("%ld", &num);
        size.push_back(make_pair(num, false));
    }
    sort(size.begin(), size.end());
    sort(desired, desired + n);
 
    long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (search(size, desired[i] - k, desired[i] + k))
        {
            ans++;
        }
    }
    printf("%ld", ans);
    return 0;
}
