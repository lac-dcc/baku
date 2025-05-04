#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k; cin>>n>>m>>k;
    int a[n], b[m];
    for (int i = 0; i < n; ++i)
    	cin>>a[i];
    for (int i = 0; i < m; ++i)
    	cin>>b[i];
    sort(a, a + n);
    sort(b, b + m);
    int cnt = 0, aptr = 0, bptr = 0;
    while (aptr < n)
    {
    	while (bptr < m && b[bptr] < a[aptr] - k)
    		bptr++;
    	if (bptr < m && a[aptr] - k <= b[bptr] && b[bptr] <= a[aptr] + k)
    	{
    		cnt++;
    		aptr++;
    		bptr++;
		}
		else
			aptr++;
	}
	cout<<cnt;
    return 0;
}
