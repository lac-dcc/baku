#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a, answer = 0;
    cin >> a;
    vector<int> values(a);
    for (int i = 0; i < a; i++) {
        cin >> values[i];
    }
    sort(values.begin(), values.end());
    for (int i = 1; i < a; i++) {
        if (values[i] != values[i - 1]) {
            answer++;
        }
    }
    cout << answer + 1 << endl;
}