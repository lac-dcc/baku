/**
 *      CSES Problem Set - Restaurant Customers
 *
 */
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
 
    pair<int, int> time[2*n];
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        time[2*i] = {start, 0};
        time[2*i+1] = {end, 1};
    }
    sort(time, time+2*n);
 
    int result = 0;
    int current = 0;
    for (int i = 0; i < 2*n; i++)
    {
        if (time[i].second == 0) {
            current++;
        }
        else {
            current--;
        }
        result = max(result, current);
    }
 
    cout << result << endl;
 
    return 0;
}
