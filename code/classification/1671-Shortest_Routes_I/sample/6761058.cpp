#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
 
#define int long long
 
int32_t main() {
    // freopen ("filename.in", "r", stdin); freopen("filename.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> cons(n);
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        cons[a - 1].push_back({b - 1, c});
    }
    vector<int> vals(n, 9223372036854775807);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorQueue;
    
    int start = 0;
    vals[start] = 0;
    priorQueue.push({0, start});
 
    while(!priorQueue.empty()) {
        int cdist = priorQueue.top().first;
        int node = priorQueue.top().second;
        priorQueue.pop();
        if(cdist != vals[node]) continue;
        for(pair<int, int> &val : cons[node]) {
            if(cdist + val.second < vals[val.first]) {
                priorQueue.push({vals[val.first] = cdist + val.second, val.first});
            }
        }
    }
    for(int i = 0; i < n; i++) cout << vals[i] << " ";
    cout << endl;
}