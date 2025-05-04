#include<bits/stdc++.h>
 
using namespace std;
 
int A[1000001];
bool B[1000001];
int C[100];
int n, x;
 
int solve(int c) {
    if (c < 0) return -1;
    if (A[c] != INT_MAX) return A[c];
    int res = INT_MAX, t;
    for (int i = 0; i < n; i++) {
        t = solve(c - C[i]);
        if (t != -1) {
            res = min(t, res);
        }
    }
 
    if (res == INT_MAX) A[c] = -1;
    else A[c] = res + 1;
    return A[c];
}
 
int main() {
    cin >> n >> x;
    fill(A, A+x+1, INT_MAX);
    A[0] = 0;
 
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }
 
    cout << solve(x);
}