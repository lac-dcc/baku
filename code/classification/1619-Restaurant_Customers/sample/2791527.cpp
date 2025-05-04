#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, a, b;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    int curr=0, ma=0;
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> end;
    for (auto x: v) {
        while (!end.empty() && end.top()<x.first) {
            curr--;
            end.pop();
        }
        curr++;
        end.push(x.second);
        ma = max(ma, curr);
    }
    cout << ma << endl;
}
