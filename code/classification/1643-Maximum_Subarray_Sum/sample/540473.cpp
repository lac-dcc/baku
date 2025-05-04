#include <bits/stdc++.h>
 
using namespace std;
const int N = 200000;
long long n, v[N];
 
int main()
{
    cin >> n;
    long long sol = -1e10, current = 0;
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        current += v[i];
        sol = max(sol, current);
        if(current < 0)
            current = 0;
    }
    cout << sol;
    return 0;
}