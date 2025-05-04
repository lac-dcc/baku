#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("fma,bmi,bmi2")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAX = 200001;
const int S = 200;
 
int n, m;
ll x[MAX], p[MAX];
 
ll a[MAX], b[MAX]; 
ll A[MAX / S + 1], B[MAX / S + 1], C[MAX / S + 1], ans[MAX / S + 1];
// a[i] = min of subarray p[block(i) : i]
// b[i] = max of subarray p[block(i) : i]
//
// C[i] = amount that has been added to p[block(i) : block(i+1) - 1], but not reflected.
//
// ans[i] = maximum value of b[r] - a[l] for l <= r in [block(i) : block(i+1) - 1]
 
void build()
{
    for (int block = 0; block * S <= n; block++)
    {
        a[block * S] = b[block * S] = p[block * S]; 
        ans[block] = max(0LL, p[block * S]);
        for (int i = block * S + 1; i < (block + 1) * S && i <= n; i++)
        {
            a[i] = min(a[i - 1], p[i]); 
            b[i] = max(b[i - 1], p[i]);
            ans[block] = max(ans[block], p[i] - a[i]);
        }
        C[block] = 0LL;
        A[block] = a[min((block + 1) * S - 1, n)];
        B[block] = b[min((block + 1) * S - 1, n)];
    }
}
 
void update(int k, ll val)
{
    int block = k / S;
 
    for (int i = block * S; i < (block + 1) * S && i <= n; i++)
        p[i] += C[block];
    for (int i = k; i < (block + 1) * S && i <= n; i++)
        p[i] += val;
 
    a[block * S] = b[block * S] = p[block * S];
    ans[block] = max(0LL, p[block * S]);
    for (int i = block * S + 1; i < (block + 1) * S && i <= n; i++)
    {
        a[i] = min(a[i - 1], p[i]); 
        b[i] = max(b[i - 1], p[i]);
        ans[block] = max(ans[block], p[i] - a[i]);
    }
    C[block] = 0LL;
    A[block] = a[min((block + 1) * S - 1, n)];
    B[block] = b[min((block + 1) * S - 1, n)];
 
    // update values of C[i]
    for (int other_block = block + 1; other_block * S <= n; other_block++)
        C[other_block] += val;
}
 
ll query()
{
    ll res = ans[0], mn = A[0] + C[0];
    for (int block = 1; block * S <= n; block++)
    {
        res = max(res, B[block] + C[block] - mn);
        mn = min(mn, A[block] + C[block]);
    }
    return res;
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n >> m;
    p[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        p[i] = p[i - 1] + x[i];
    }
    build();
 
    int k; 
    ll new_val;
    while (m--)
    {
        cin >> k >> new_val;
 
        update(k, new_val - x[k]);
        x[k] = new_val;
 
        cout << query() << '\n';
    }
 
    return 0;
}
