#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n, k;
 
    cin >> n >> k;
 
    vector<vector<int>> arr(n);
 
    for (int i = 0; i < n; i++)
    {
	int x, y;
	cin >> x >> y;
	arr[i] = {y, x};
    }
 
    sort(arr.begin(), arr.end());
 
    int moviesM = 0;
    multiset<int> ends;
 
    for (int i = 0; i < k; i++) ends.insert(0);
 
    for (int i = 0; i < n; i++)
    {
	auto it = ends.upper_bound(arr[i][1]);
	if (it == ends.begin()) continue;
	ends.erase(--it);
	ends.insert(arr[i][0]);
	++moviesM;
    }
 
    cout << moviesM << "\n";
 
 
    return 0;
}
