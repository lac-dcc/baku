#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <string.h>
#include <list>
#include <bitset>
 
using namespace std;
 
typedef short int si;
typedef long long int li;
 
vector<int> primes;
void computePrimes(int n)
{
    vector<bool> prime(n+1, true);
    for (int p = 2; p * p <= n; p++) 
    {
        if (prime[p] == true) 
        {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
    for(int p = 2; p <= n; p++) if (prime[p]) primes.push_back(p);
}
 
void yn(bool b)
{
    if (b) cout << "YES" << endl;
    else cout << "NO" << endl;
}
 
template <typename T>
struct medianMultisets
{
    multiset<T> smaller, larger;
    void reset()
    {
        smaller.clear();
        larger.clear();
    }
    bool odd()
    {
        return (smaller.size()+larger.size()) % 2 == 1;
    }
    size_t size()
    {
        return smaller.size()+larger.size();
    }
    int median()
    {
        return *larger.begin();
    }
    void add(T v)
    {
        if(smaller.empty() && larger.empty())
        {
            larger.insert(v);
            return;
        }
        if(v < *larger.begin())
        {
            if(smaller.size() < larger.size()) smaller.insert(v);
            else 
            {
                smaller.insert(v);
                auto it = smaller.rbegin();
                larger.insert(*it);
                smaller.erase(smaller.find(*it)); 
            }
        }
        else
        {
            if(smaller.size() == larger.size()) larger.insert(v);
            else
            {
                larger.insert(v);
                auto it = larger.begin();
                smaller.insert(*it);
                larger.erase(it);
            }
        }
    }
    void remove(T v)
    {
        if(v < *larger.begin())
        {
            if(smaller.size() == larger.size()) smaller.erase(smaller.find(v));
            else 
            {
                smaller.erase(smaller.find(v));
                auto it = larger.begin();
                smaller.insert(*it);
                larger.erase(it);
            }
        }
        else
        {
            if(smaller.size() < larger.size()) larger.erase(larger.find(v));
            else
            {
                larger.erase(larger.find(v));
                auto it = smaller.rbegin();
                larger.insert(*it);
                smaller.erase(smaller.find(*it)); 
            }
        }
    }
};
 
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (int i = 0; i < v.size(); i++) is >> v[i];
    return is;
}
 
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for(auto i: v) os << i << ' ';
    return os;
}
 
template <typename T>
ostream &operator<<(ostream &os, set<T> &v)
{
    for(auto i: v) os << i << ' ';
    return os;
}
 
template<typename T>
T gcd(T a, T b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}
 
li mod = 1000000007;
 
li powMod(li a, li b)
{
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) return powMod(a * a % mod, b / 2) % mod;
    return a * powMod(a, b - 1) % mod;
}
 
li fractionMod(li a, li b)
{
    return (a % mod * powMod(b, mod - 2) % mod) % mod;
}
 
struct segtree
{
    vector<li> tr, lazy;
    segtree(vector<li> &p)
    {
        int n = p.size();
        tr.resize(4*n, -1e18);
        lazy.resize(4*n, 0);
        build(1, 0, n-1, p);
    }
    void push(int i, int l, int r)
    {
        if(lazy[i] == 0) return;
        tr[i] += lazy[i];
        if(l != r)
        {
            lazy[2*i] += lazy[i];
            lazy[2*i+1] += lazy[i];
        }
        lazy[i] = 0;
    }
    void build(int i, int l, int r, vector<li> &p)
    {
        if(l == r)
        {
            tr[i] = p[l];
            return;
        }
        int m = (l+r)/2;
        build(2*i, l, m, p);
        build(2*i+1, m+1, r, p);
        tr[i] = max(tr[2*i], tr[2*i+1]);
    }
    void update(int i, int l, int r, int lq, int rq, li val)
    {
        push(i, l, r);
        if(lq > r || rq < l) return;
        if(lq <= l && r <= rq)
        {
            lazy[i] += val;
            push(i, l, r);
            return;
        }
        int m = (l+r)/2;
        update(2*i, l, m, lq, rq, val);
        update(2*i+1, m+1, r, lq, rq, val);
        tr[i] = max(tr[2*i], tr[2*i+1]);
    }
    li query(int i, int l, int r, int lq, int rq)
    {
        push(i, l, r);
        if(lq > r || rq < l) return -1e18;
        if(lq <= l && r <= rq) 
        {
            return tr[i];
        }
        int m = (l+r)/2;
        li res = max(query(2*i, l, m, lq, rq), query(2*i+1, m+1, r, lq, rq));
        // tr[i] = max(tr[2*i], tr[2*i+1]);
        return res;
    }
};
 
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    vector<li> p(n+1, 0);
    for(int i = 0; i < n; i++) p[i+1] = p[i]+a[i];
    segtree st(p);
    while(q--)
    {
        int c, l, r;
        cin >> c >> l >> r;
        if(c == 1)
        {
            li valChange = r-a[l-1];
            a[l-1] = r;
            st.update(1, 0, n, l, n, valChange);
            // cout << st.lazy << '\n';
        }
        else
        {
            li prev = st.query(1, 0, n, l-1, l-1);
            li ans = st.query(1, 0, n, l, r);
            cout << max(0LL, ans-prev) << '\n';
        }
        // cout << st.tr << '\n';
        // cout << st.lazy << '\n';
        // cout << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    for(int tn = 1; tn<=t; tn++)
    {
        // cout << "Case #" << tn << ": ";
        solve();
    }
    return 0;
}
