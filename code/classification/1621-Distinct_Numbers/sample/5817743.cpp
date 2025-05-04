#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, answer = 0;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    sort(values.begin(), values.end());
    for (int i = 1; i < n; i++) {
        if (values[i] != values[i - 1]) {
            answer++;
        }
    }
    cout << answer + 1 << endl;
}