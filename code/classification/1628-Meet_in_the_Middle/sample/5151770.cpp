#include <bits/stdc++.h>
using namespace std;
 
const int ms = 40;
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n, target, mask, res, shift;
    long long arr[ms];
    long long sum, count = 0;
    vector<long long> half1, half2;
 
    cin >> n >> target;
 
    //40
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
 
    shift = n / 2;
 
 
    for (int i = 0; i < (1 << shift); i++)
    {
        mask = i;
        sum = 0;
        for (int j = 0; j < shift; j++)
        {
            if ((mask >> j) & 1)
            {
                sum += arr[j];
            }
        }
        half1.push_back(sum);
    }
 
    if (n % 2 != 0)
    {
        shift = n / 2 + 1;
    }
 
    for (int i = 0; i < (1 << shift); i++)
    {
        mask = i;
        sum = 0;
 
        for (int j = 0; j < shift; j++)
        {
            if ((mask >> j) & 1)
            {
 
                sum += arr[j + n / 2];
            }
        }
        half2.push_back(sum);
    }
 
    sort(half2.begin(), half2.end());
 
    for (auto u : half1)
    {
        res = (upper_bound(half2.begin(), half2.end(), (target - u)) - lower_bound(half2.begin(), half2.end(), (target - u)));
        count += res;
    }
 
    cout << count << "\n";
}
