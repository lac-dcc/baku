#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    long long int n;
    cin >> n;
 
    vector<pair<int, int>> events;
 
    for (int t = 0; t < n; t++) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1}); // 1 represents arrival
        events.push_back({b, -1}); // -1 represents leaving
    }
 
    sort(events.begin(), events.end());
 
    int max_customers = 0;
    int current_customers = 0;
 
    for (auto event : events) {
        if (event.second == 1) {
            current_customers++;
            max_customers = max(max_customers, current_customers);
        } else {
            current_customers--;
        }
    }
 
    cout << max_customers << endl;
 
    return 0;
}
