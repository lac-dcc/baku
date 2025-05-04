#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, target;
    cin >> n >> target;
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n ; i++) {
        int x;
        cin >> x;
        arr[i] = {x,i};
    }
    sort(arr.begin(), arr.end());
    int p1 = 0, p2 = n-1;
    while (p1<p2) {
        int sum = arr[p1].first  + arr[p2].first;
        if (sum == target) {
            cout << arr[p1].second+1 << " " << arr[p2].second+1 << endl;
            return 0;
        }
        else if (sum > target) {
            p2--;
        }
        else {
            p1++;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}
