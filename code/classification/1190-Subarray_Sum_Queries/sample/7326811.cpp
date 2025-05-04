#include <iostream>
 
const int MAX_N = 2e5 + 1;
const long long INF = 1e18 + 1;
 
struct node {
    long long g_max, l_max, r_max, sum;
 
    node(long long a = 0, long long b = 0, long long c = 0, long long d = 0) {
        g_max = a;
        l_max = b;
        r_max = c;
        sum   = d;
    }
 
    node operator + (node& x) const {
        return node(
            std::max(std::max(g_max, x.g_max), r_max + x.l_max),
            std::max(l_max, sum + x.l_max),
            std::max(x.r_max, r_max + x.sum),
            sum + x.sum
        );
    }
};
 
struct SegmentTree {
    node val[4 * MAX_N];
 
    void Update(int id, int l, int r, int u, int v, long long c) {
        if (r <  u || v <  l) return;
        if (u <= l && r <= v) {
            val[id] = node(
                std::max(0LL, c),
                std::max(0LL, c),
                std::max(0LL, c),
                c  
            );
            return;
        }
    
        int mid = (l + r) >> 1;
        Update(2 * id    , l      , mid, u, v, c);
        Update(2 * id + 1, mid + 1, r  , u, v, c);
        val[id] = val[2 * id] + val[2 * id + 1];
    }
} ST;
 
int n, m;
int arr[MAX_N];
 
int main() {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    if (fopen("Input.txt", "r")) freopen("Input.txt", "r", stdin);
 
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) std::cin >> arr[i];
 
    for (int i = 1; i <= n; i++) ST.Update(1, 1, n, i, i, arr[i]);
 
    while (m--) {
        int a, b; std::cin >> a >> b;
 
        ST.Update(1, 1, n, a, a, b);
 
        std::cout << ST.val[1].g_max << '\n';
    }
 
    return 0;
}
