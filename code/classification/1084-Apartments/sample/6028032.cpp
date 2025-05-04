#include <bits/stdc++.h>
 
 
using namespace std;
 
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> desiredSize, apartments;
 
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        desiredSize.push_back(a);
    }
 
    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        apartments.push_back(b);
    }
 
    sort(desiredSize.begin(), desiredSize.end());
    sort(apartments.begin(), apartments.end());
 
    int c = 0, i = 0, j = 0;
 
    while (true) {
        if (i >= m || j >= n) break;
        if (apartments[i] < desiredSize[j] - k) ++i;
        else if (apartments[i] > desiredSize[j] + k) ++j;
        else {
            ++c; ++i; ++j;
        }
    }
 
    cout << c << "\n";
 
 
}