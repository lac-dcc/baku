#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
 
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end(), greater<int>());
 
    int c = 0;
    for (int i : a) {
        while (!b.empty()) {
            if (abs(i - b.back()) <= k) {
                c += 1;
                b.pop_back();
                break;
            } else if (b.back() - i > k) {
                break;
            }
 
            b.pop_back();
        }
    }
 
    cout << c << endl;
}