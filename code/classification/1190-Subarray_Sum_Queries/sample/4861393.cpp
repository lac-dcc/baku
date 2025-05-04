#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(x) x.begin(), x.end()
#define double long double
#define endl '\n'
#define ff first
#define ss second
#define v vector
using pii = pair<int, int>;
const bool multipleTestCases = 0;
 
struct node
{
    int maxPrefix = 0;
    int maxSuffix = 0;
    int maxSum = 0;
    int completeSum = 0;
};
 
template <typename T>
class SegmentTree
{
    v<v<T>> Tree;
    T neutralValue;
 
    T merge(T a, T b)
    {
        T ans;
        ans.maxPrefix = max({a.maxPrefix, a.completeSum + b.maxPrefix});
        ans.maxSuffix = max({b.maxSuffix, b.completeSum + a.maxSuffix});
        ans.completeSum = a.completeSum + b.completeSum;
        ans.maxSum = max({a.maxSum, b.maxSum, a.maxSuffix + b.maxPrefix, ans.completeSum, ans.maxPrefix, ans.maxSuffix});
        return ans;
    }
 
public:
    SegmentTree(v<T> &A, T neutralValue)
    {
 
        this->neutralValue = neutralValue;
 
        int n = A.size();
 
        Tree.push_back(v<T>(1, neutralValue));
 
        int prev = 1;
 
        while (prev < n)
        {
            Tree.push_back(v<T>(2 * prev, neutralValue));
            prev *= 2;
        }
 
        int levels = Tree.size();
 
        for (int i = 0; i < n; i++)
            Tree[levels - 1][i] = A[i];
 
        for (int i = levels - 2; i >= 0; i--)
            for (int j = 0; j < (1 << i); j++)
                Tree[i][j] = merge(Tree[i + 1][2 * j], Tree[i + 1][2 * j + 1]);
    }
 
    void update(int idx, T val)
    {
        int levels = Tree.size();
        Tree[levels - 1][idx] = val;
        idx /= 2;
 
        for (int i = levels - 2; i >= 0; i--, idx /= 2)
            Tree[i][idx] = merge(Tree[i + 1][2 * idx], Tree[i + 1][2 * idx + 1]);
    }
 
    T query(int level, int idx, int treeLeft, int treeRight, int l, int r)
    {
        if (treeLeft > treeRight or treeRight < l or treeLeft > r or r < treeLeft or l > treeRight or level == Tree.size())
            return neutralValue;
 
        if (l <= treeLeft and treeRight <= r)
            return Tree[level][idx];
 
        int m = (treeLeft + treeRight) / 2;
 
        return merge(query(level + 1, 2 * idx, treeLeft, m, l, r), query(level + 1, 2 * idx + 1, m + 1, treeRight, l, r));
    }
 
    T query(int l, int r)
    {
        int levels = Tree.size();
        return query(0, 0, 0, Tree[levels - 1].size() - 1, l, r);
    }
};
 
void solve()
{
    int n, q;
    cin >> n >> q;
    v<node> arr(n + 1);
 
    for (int i = 1; i <= n; ++i)
    {
        int val;
        cin >> val;
        arr[i] = node({val, val, val, val});
    }
 
    SegmentTree<node> st(arr, node());
 
    while (q--)
    {
        int idx, val;
        cin >> idx >> val;
        st.update(idx, node({val, val, val, val}));
        cout << st.query(1, n).maxSum << endl;
    }
}
 
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    multipleTestCases and cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
