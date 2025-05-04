#include <bits/stdc++.h>
using namespace std;
const int N = 40 + 2;
int n, x;
int t[N];
vector<int> A, B;
 
void TryX(int i, int sum) {
    if (sum > x) return;
 
    if (i > n / 2) A.push_back(sum);
    else {
        TryX(i + 1, sum);
        TryX(i + 1, sum + t[i]);
    }
}
void TryY(int i, int sum) {
    if (sum > x) return;
 
    if (i > n) B.push_back(sum);
    else {
        TryY(i + 1, sum);
        TryY(i + 1, sum + t[i]);
    }
}
 
int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> t[i];
 
    // Quay lui 2 tập X và Y
    TryX(1, 0);
    TryY(n / 2 + 1, 0);
 
    // Sắp xếp mảng B
    sort(B.begin(), B.end());
 
    // Lặp qua mảng A và tìm kiếm nhị phân:
    // - Đếm số lượng phần tử trong B có giá trị bằng x - A[i]
    long long cnt = 0;
    for (int sum : A) {
        cnt += upper_bound(B.begin(), B.end(), x - sum) - lower_bound(B.begin(), B.end(), x - sum);
    }
    cout << cnt << '\n';
}
