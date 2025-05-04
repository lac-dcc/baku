#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
 
using namespace std;
 
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    vector<pair<ll, int>> events;
    for (int i = 0; i < n; i++) {
        ll in, out;
        cin >> in >> out;
        events.push_back({in, 1});
        events.push_back({out, -1});
    }
 
    sort(events.begin(), events.end());
 
    int ans = 0;
    int i = 0;
    for (const auto& event : events) {
        i += event.second;
        ans = max(ans, i);
    }
 
    cout << ans << endl;
 
    return 0;
}
