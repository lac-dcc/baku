#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
 
using namespace std;
long long int mod = 1e9 + 7;
 
void solve()
{
    int n, a, b;
    cin >> n;
    int ans = 0;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> min_heap;
 
    for(int i = 0; i < n; i++){
        while(!min_heap.empty() && min_heap.top() <= v[i].first){
            min_heap.pop();
        }
        min_heap.push(v[i].second);
        ans = max(ans, (int)min_heap.size());
    }
 
    cout << ans << endl;
 
}
 
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
