#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
 
long long arr[1000];
array<long long, 3> sums[500500];
array<long long, 4> result;
 
bool cmp(array<long long, 3> a, array<long long, 3> b) {
    return a[0] < b[0];
}
 
int main() {
    int n, x, n_sum = 0;
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            sums[n_sum++] = {arr[i] + arr[j], i, j};
        }
    }
    sort(sums, sums + n_sum, cmp);
    for(int i = 0, j = n_sum - 1; i < j; i++) {
        while(i < j && sums[i][0] + sums[j][0] > x) {
            j--;
        }
        while(i < j && sums[i][0] + sums[j][0] == x) {
            if(sums[i][1] != sums[j][1] &&
                    sums[i][1] != sums[j][2] &&
                    sums[i][2] != sums[j][1] &&
                    sums[i][2] != sums[j][2]) {
                result = {sums[i][1], sums[i][2], sums[j][1], sums[j][2]};
                sort(result.begin(), result.end());
                for(int k = 0; k < 4; k++) {
                    cout << result[k] + 1 << ' ';
                }
                return 0;
            }
            j--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
