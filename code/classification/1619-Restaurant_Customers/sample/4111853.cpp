#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    int arrive, depart;
    for (int i= 0;i < n;i++) {
        cin >> arrive >> depart;
        a[i] = {arrive, depart};
    }
    sort(a.begin(), a.end());
    priority_queue<int,vector<int>, greater<int>> pq;
    pq.push(a[0].second);
    int ans = 1;
    for (int i = 1;i < n;i++) {
        while(pq.size() && pq.top() < a[i].first) {
            pq.pop();
        }
        pq.push(a[i].second);
        ans = max(ans, (int)pq.size());
    }
    cout << ans << endl;
}
