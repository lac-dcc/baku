#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define pb push_back
#define pi pair<ll, ll>
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
   int n;
	cin >> n;
	vector<pair<int, int>> times;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		times.push_back({start, 1});
		times.push_back({end, -1});
	}
 
	sort(times.begin(), times.end());
 
	int curr_ppl = 0;
	int max_ppl = 0;
	for (const pair<int, int> &t : times) {
		curr_ppl += t.second;
		max_ppl = max(max_ppl, curr_ppl);
	}
    cout<<max_ppl<<endl;
    return 0;
}
