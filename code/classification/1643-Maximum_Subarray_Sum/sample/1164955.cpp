#include <bits/stdc++.h>
 
using namespace std;
const long long N=-1000000000000000;
long long n ,a[200007],sum=N,best=N;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(); cout.tie();
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        sum=max(a[i],sum+a[i]);
        best=max(sum,best);
    }
    cout << best;
    return 0;
}