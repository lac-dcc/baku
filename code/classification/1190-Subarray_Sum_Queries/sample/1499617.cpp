#include <iostream>
#include <algorithm>
using namespace std;
 
int N, M, K, X;
int A[200010];
 
struct node {
    int s, e, m;
    long long maxPrefix, maxSuffix, sum, maxSum;
    node *l, *r;
    node(int _s, int _e): s(_s), e(_e), m((s + e) / 2) {
        if (s == e) {
            sum = A[s];
            maxPrefix = maxSuffix = maxSum = max(0, A[s]);
            return;
        }
        l = new node(s, m);
        r = new node(m + 1, e);
        combine();
    }
    void combine() {
        sum = l->sum + r->sum;
        maxPrefix = max(l->maxPrefix, l->sum + r->maxPrefix);
        maxSuffix = max(r->maxSuffix, r->sum + l->maxSuffix);
        maxSum = max(max(l->maxSum, r->maxSum), l->maxSuffix + r->maxPrefix);
    }
    void update(int p, int v) {
        if (s == e) {
            sum = v;
            maxPrefix = maxSuffix = maxSum = max(0, v);
            return;
        }
        if (p <= m) l->update(p, v);
        else r->update(p, v);
        combine();
    }
} *root;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int a = 1; a <= N; ++a) cin >> A[a];
    root = new node(1, N);
    for (int a = 0; a < M; ++a) {
        cin >> K >> X;
        root->update(K, X);
        cout << root->maxSum << '\n';
    }
    return 0;
}
