// Apartments
 
#include <bits/stdc++.h>
using namespace std;
 
void fn()
{
    long long n, m, k, t;
    cin >> n >> m >> k;
    vector<long long> applicants, houses;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        applicants.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        houses.push_back(t);
    }
    sort(applicants.begin(), applicants.end());
    sort(houses.begin(), houses.end());
    int i = 0, j = 0;
    long long sol = 0;
    while (i < n && j < m)
    {
        if (abs(applicants[i] - houses[j]) <= k)
        {
            sol++;
            i++;
            j++;
        }
        else
        {
            if (applicants[i] > houses[j])
                j++;
            else
                i++;
        }
    }
    cout << sol << endl;
}
 
int main()
{
    fn();
    return 0;
}
