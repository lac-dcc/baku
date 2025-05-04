#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
// #define int long long
//  const int mod = 1000000007;
 
// Move all 8 dir of matrix
int direction[16]{-1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1};
const int mod = 1e9 + 7;
const int N = 4e5 + 3;
#define pb push_back
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast,unroll-loops")
 
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
// long long hash_mod = 1011001110001111;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
template <class T>
using red_black_tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <class T1>
using red_black_tree_pair = tree<pair<T1, T1>, null_type, less<pair<T1, T1>>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define vi vector<int>
#define vll vector<ll>
#define all(a) a.begin(), a.end()
#define forr(a, k, n) for (long long a = k; a < n; a++)
#define llmin_queue priority_queue<ll, vector<ll>, greater<ll>>
#define min_queue priority_queue<int, vector<int>, greater<int>>
#define Yes cout << "Yes\n";
#define YES cout << "YES\n";
#define No cout << "No\n";
#define NO cout << "NO\n";
#define f first
#define s second
#define endl "\n"
#define debug(x) cout << #x << " is " << x << endl
#define pii pair<int, int>
#define pll pair<ll, ll>
 
// https://codeforces.com/blog/entry/60737
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash
{
    int operator()(int x) const { return x ^ RANDOM; }
};
 
// https://codeforces.com/blog/entry/75044#:~:text=As%20an%20extension%20the%20integer,an%20unsigned%20128-bit%20integer.
__int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }
 
struct custom_hash
{
    // unordered_map<int,int,custom_hash>x;
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
ll mod_inv(ll i)
{
    if (i == 1)
        return 1;
    return (mod - ((mod / i) * mod_inv(mod % i)) % mod) % mod;
}
 
ll mul(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}
 
ll add(ll a, ll b)
{
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}
inline int in()
{
    int x;
    // scanf("%d", &x);
    cin >> x;
    return x;
}
 
struct ordered_multiset
{
    int len = 0;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    unordered_map<int, int> mp; // hash = 96814
    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
 
    ordered_multiset()
    {
        len = 0;
        T.clear(), mp.clear();
    }
 
    inline void insert(int x)
    {
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c);
    }
 
    inline void erase(int x)
    {
        x += MAXVAL;
        int c = mp[x];
        if (c)
        {
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }
 
    inline int kth(int k)
    { // 1-based index,  returns the
        if (k < 1 || k > len)
            return -1;                  // K'th element in the treap,
        auto it = T.find_by_order(--k); // -1 if none exists
        return ((*it) / ADD) - MAXVAL;
    }
 
    inline int lower_bound(int x)
    { // Count of value <x in treap
        x += MAXVAL;
        int c = mp[x];
        return (T.order_of_key((x * ADD) + c));
    }
 
    inline int upper_bound(int x)
    { // Count of value <=x in treap
        x += MAXVAL;
        int c = mp[x];
        return (T.order_of_key((x * ADD) + c));
    }
 
    inline int size() { return len; } // Number of elements in treap
};
template <typename T>
void input(T *arr, int n)
{
    forr(i, 0, n) cin >> arr[i];
}
template <typename T>
void input(vector<T> &arr, int n)
{
    forr(i, 0, n) cin >> arr[i];
}
template <typename T>
void input(vector<T> &arr)
{
    for (auto &i : arr)
        cin >> i;
}
template <typename T>
void show(T *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
template <typename T>
void show(vector<T> const &arr)
{
    for (auto j : arr)
    {
        cout << j << " ";
    }
    cout << "\n";
}
 
int intsize(long long n)
{
    return floor(log10(n) + 1);
}
 
ll bin_pow(ll a, ll b)
{
 
    ll ans = 1;
    while (b)
    {
        if (1 & b)
        {
            ans = ans * a;
        }
        a = (a * a);
 
        b >>= 1;
    }
    return ans;
}
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
// product
uint64_t bin_sum(const uint64_t x, const uint64_t y, const uint64_t m)
{
    uint64_t ans = x + y;
    if (ans < x || ans >= m)
        ans -= m;
    return ans;
}
//<=64bit
uint64_t prod_binary(const uint64_t x, const uint64_t y, const uint64_t m)
{
    if (y <= 1)
        return y ? x : 0;
    uint64_t ans = prod_binary(x, y >> 1, m);
    ans = bin_sum(ans, ans, m);
    if (y & 1)
        ans = bin_sum(ans, x, m);
    return ans;
}
 
//<=63bit
uint64_t prod_long_double(const uint64_t x, const uint64_t y, const uint64_t m)
{
    uint64_t c = (long double)x * y / m;
    int64_t ans = int64_t(x * y - c * m) % int64_t(m);
    if (ans < 0)
        ans += m;
    return ans;
}
// advance
int64_t prod_uint128(const uint64_t x, const uint64_t y, const uint64_t m)
{
    return (unsigned __int128)x * y % m;
}
// Ordered
ll inv(vector<int> &arr)
{
    ll cnt = 0;
    red_black_tree<int> tree;
    for (auto &it : arr)
    {
        cnt += tree.size() - tree.order_of_key(it);
        tree.insert(it);
    }
    return cnt;
}
//....................................Trie zone
struct Trie
{
    Trie *next[26];
    int cnt;
    Trie()
    {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
        cnt = 0;
    }
};
void insert(string &s, Trie *root)
{
 
    for (auto &i : s)
    {
        int ind = i - 'a';
        if (root->next[ind] == NULL)
        {
            root->next[ind] = new Trie();
        }
        root->next[ind]->cnt++;
        root = root->next[ind];
    }
}
 
int query(string &s, Trie *root)
{
    int ans = 0;
    for (auto &i : s)
    {
        int ind = i - 'a';
        ans += root->next[ind]->cnt;
        root = root->next[ind];
    }
    return ans;
}
//.......................................................................//
 
unsigned long long power(unsigned long long x,
                         int y, int p)
{
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
 
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
double round_alt(double x)
{
    double ipart;
    // break into integer and fraction parts
    double fpart = modf(x, &ipart);
    if (fpart != 0.0)
    {
        if (x >= 0.5)
        {
            ipart += floor(fpart + 0.5);
        }
        else if (x <= -0.5)
        {
            ipart += ceil(fpart - 0.5);
        }
    }
    return ipart;
}
// //......NCR
 
// vector<unsigned ll> fact(1000001, 1);
// void factorials()
// {
//     fact[0] = 1;
//     for (int i = 1; i <= 1000000; i++)
//         fact[i] = (fact[i - 1] * i) % mod;
// }
 
// unsigned ll exp(unsigned ll a, unsigned ll b, int mod)
// {
 
//     int res = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//             res = (res * a) % mod;
//         a = (a * a) % mod;
//         b = b >> 1;
//     }
//     return res;
// }
 
// unsigned ll inv(int a, int mod)
// {
//     return exp(a, mod - 2, mod);
// }
// unsigned ll ncr(int n, int r)
// {
//     if (n < r || (n < 0) || (r < 0))
//         return 0;
//     return ((((fact[n] * inv(fact[r], mod)) % mod) * inv(fact[n - r], mod)) % mod);
// }
 
ll invertBits(int num)
{
    // Find number of bits in the given integer
    int numOfBits = (int)log2(num) + 1;
 
    // invert the number by taking
    // xor of n and (2 raised to numOfBits) - 1
    return 1ll * (((1 << numOfBits) - 1) ^ num);
}
bool two_power(int n)
{
    if (n == 0)
        return false;
 
    return (ceil(log2(n)) == floor(log2(n)));
}
bool perfectsquare(ll n)
{
 
    // If ceil and floor are equal
    // the number is a perfect
    // square
    if (ceil((double)sqrtl(n)) == floor((double)sqrtl(n)))
    {
        return true;
    }
    return false;
}
ll binary2d(string n)
{
    string num = n;
    ll dec_value = 0;
 
    ll base = 1;
 
    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value = add(dec_value, base);
        base = mul(2, base);
    }
 
    return dec_value % mod;
}
ll sumDigits(ll no)
{
    if (no == 0)
    {
        return 0;
    }
 
    return (no % 10) + sumDigits(no / 10);
}
// vector<ll> primes;
// void SieveOfEratosthenes()
// {
 
//     bool prime[N + 1];
//     memset(prime, true, sizeof(prime));
 
//     for (int p = 2; p * p <= N; p++)
//     {
 
//         if (prime[p] == true)
//         {
 
//             for (int i = p * p; i <= N; i += p)
//                 prime[i] = false;
//         }
//     }
 
//     // Print all prime numbers
//     for (int p = 2; p <= N; p++)
//         if (prime[p])
//             primes.emplace_back(p);
// }
 
vector<ll> divisors(ll n)
{
    ll c = 2;
    vector<ll> divs;
    while (n > 1)
    {
        if (n % c == 0)
        {
            divs.pb(c);
            n /= c;
        }
        else
            c++;
    }
    return divs;
}
// int root(int x)
// {
//     int y = sqrtl(x) + 2;
//     while (y * y > x)
//         --y;
//     return y;
// }
vector<ll> fact_wheel(long long n)
{
    vector<long long> factorization;
    for (int d : {2, 3, 5})
    {
        if (n % d == 0)
            factorization.push_back(d);
        while (n % d == 0)
        {
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++])
    {
        if (n % d == 0)
            factorization.push_back(d);
        while (n % d == 0)
        {
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
 
// void subset_mask()
// {
//     int fsz;
//     // fsz = set size;
//     for (ll l = 1; l < (1ll << fsz); ++l)
//     {
 
//         ll curr = 1;
//         for (ll j = 0; j < fsz; ++j)
//         {
//             if ((l >> j) & 1)
//             {
//                 // curr *= factor[j];
//                 // Generate
//             }
//         }
//     }
// }
int cycle_srt(vector<int> &arr)
{
    // Min swap sort 1 to N
    map<int, int> mp;
 
    int n = arr.size();
 
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }
 
    int ans = 0;
    sort(arr.begin(), arr.end());
    vector<bool> vis(n, 0);
 
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || mp[arr[i]] == i)
            continue;
 
        int j = i;
 
        int cycle_size = 0;
 
        while (!vis[j])
        {
            vis[j] = 1;
            cycle_size++;
            j = mp[arr[j]];
        }
        if (cycle_size > 0)
            ans += (cycle_size - 1);
    }
    return ans;
}
 
struct DSU
{
    // USACO
    vector<int> e;
    int total_comopnents;
    DSU(int N)
    {
        e = vector<int>(N + 1, -1);
        total_comopnents = N;
    }
 
    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
 
    bool same_set(int a, int b) { return get(a) == get(b); }
 
    int size(int x) { return -e[get(x)]; }
 
    void unite(int x, int y)
    { // union by size
        x = get(x), y = get(y);
        // if (x == y)
        //    return false;
        if (x != y)
        {
            if (e[x] > e[y])
                swap(x, y);
            e[x] += e[y];
            e[y] = x;
            total_comopnents--;
            // return true;
        }
    }
};
 
class Tree
{
public:
    Tree *left, *right;
    int val;
};
Tree *in(int a)
{
    Tree *n = new Tree();
    n->val = a;
    n->left = NULL, n->right = NULL;
    return n;
}
 
Tree *insert(int a, Tree *root)
{
    //  Tree *curr = new Tree(a);
    if (root == NULL)
    {
        return root = in(a);
        // return;
    }
    // Tree *temp = root;
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        Tree *f = q.front();
        q.pop();
        if (f->left)
        {
            q.push(f->left);
        }
        else
        {
            return f->left = in(a);
            // return;
        }
        if (f->right)
            q.push(f->right);
        else
        {
            return f->right = in(a);
            // return;
        }
    }
    return root;
}
int leftmost(int n)
{
    if ((n & (n + 1)) == 0)
        return 0;
    int cnt = 0;
    int i = 0;
    for (int t = n; t > 0; t >>= 1, cnt++)
    {
        if ((1 & t) == 0)
            i = cnt;
    }
    return i;
}
bool powerof2(int x)
{
    return x && (!(x & (x - 1)));
}
long long pow_mod(long long a, ll b, ll md)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % md;
        }
        b >>= 1;
        a = a * a % md;
    }
    return ans;
}
ll primeFactors_cnt(int n)
{
    int c = 2;
    int cnt = 0;
    while (n > 1)
    {
        if (n % c == 0)
        {
            cnt++;
            n /= c;
        }
        else
            c++;
    }
    return cnt;
}
vector<ll> primes;
void sieve_fn()
{
 
    vector<bool> sieve(N + 10, 1);
    sieve[0] = sieve[1] = 0;
    for (ll i = 2; i * i <= N; i++)
    {
        if (sieve[i])
        {
 
            for (ll j = i * i; j <= N; j += i)
            {
                sieve[j] = 0;
            }
        }
    }
 
    for (ll i = 2; i <= N; i++)
        if (sieve[i])
            primes.emplace_back(i);
}
 
void prime_fact(ll n, vi &ans)
{
    // vector<ll> ans;
    for (ll i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            // ans.pb(i);
 
            while (n % i == 0)
            {
                ans.pb(i);
                n /= i;
            }
        }
    }
    if (n > 1)
        ans.pb(n);
    // return ans;
}
 
struct FenwickTree
{
    // One based Tree
    // SUM Tree-> Modify as per use
    vector<ll> bit;
    int n;
 
    FenwickTree(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
 
    FenwickTree(vector<ll> a)
        : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
 
    ll sum(ll idx)
    {
        ll ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
 
    ll sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
    void add(int l, int r, ll delta)
    {
        add(l, delta);
        add(r + 1, -delta);
    }
    void add(int idx, ll delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
 
    // Use this together//////////////
    ll sum_here_till_end(int i)
    {
        ll sum = 0;
 
        while (i < n)
        {
            sum += bit[i];
            i += i & -i;
        }
 
        return sum;
    }
 
    void add_beg(int i)
    {
        while (i > 0)
        {
            bit[i] += 1;
            i -= i & -i;
        }
    }
    //////////////////////////////////////////
};
 
inline ll gcd_best(ll a, ll b)
{
    if (a && b)
        while ((a %= b) && (b %= a))
            ;
    return a ^ b;
}
 
// void common_factors(){
//     vi fac;
//     int i;
//     for (i = 1; i * i <= g; i++)
//         if (g % i == 0)
//         {
//             fac.push_back(i);
//             if (g / i > i)
//                 fac.push_back(g / i);
//         }
// }
 
bool isPalindrome(string &s)
{
 
    for (int i = 0; i < s.size() / 2; i++)
    {
 
        if (s[i] != s[s.size() - i - 1])
        {
 
            return false;
        }
    }
 
    return true;
}
 
bool is_prime(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
 
void prime_sieve()
{
    vector<int> sive; // Take it global before use
    if (sive.empty())
    {
        sive.resize(N);
        iota(sive.begin(), sive.end(), 0);
        for (int i = 2; i * i < N; i++)
        {
            if (sive[i] != i)
                continue;
            for (int j = i * i; j < N; j += i)
            {
                sive[j] = i;
            }
        }
    }
}
void prime_fact_best(int n, vector<int> &ans)
{
 
    // call prime_sieve()
    //  if (sive.empty())
    //  {
    //      sive.resize(N);
    //      iota(sive.begin(), sive.end(), 0);
    //      for (int i = 2; i * i < N; i++)
    //      {
    //          if (sive[i] != i)
    //              continue;
    //          for (int j = i * i; j < N; j += i)
    //          {
    //              sive[j] = i;
    //          }
    //      }
    //  }
    //  vector<int> ans;
    //  while (n != 1)
    //  {
    //      int x = sive[n];
    //      // ans.emplace_back(x);
    //      while (n % x == 0)
    //      {
    //          ans.emplace_back(x);
    //          n /= x;
    //      }
    //  }
    //  return ans;
}
 
class segTree
{
public:
    const static int M = 140000;
 
    int seg[2 * M], arr[M];
    int build(int node, int l, int r)
    {
        if (l == r)
        {
            seg[node] = arr[l];
            return 1;
        }
        int mid = (l + r) >> 1;
        int l1 = build(2 * node + 1, l, mid);
        int r1 = build(2 * node + 2, mid + 1, r);
 
        if (l1 || r1)
        {
            seg[node] = (seg[node * 2 + 1] | seg[node * 2 + 2]);
            return 0;
        }
        else
        {
            seg[node] = (seg[node * 2 + 1] ^ seg[node * 2 + 2]);
            return 1;
        }
    }
 
    int update(int node, int l, int r, int a, int b)
    {
        if (l == r)
        {
            seg[node] = b;
            return 1;
        }
        int mid = (l + r) >> 1;
        int up;
        if (a <= mid)
        {
            up = update(2 * node + 1, l, mid, a, b);
        }
        else
            up = update(2 * node + 2, mid + 1, r, a, b);
 
        if (up)
        {
            seg[node] = (seg[node * 2 + 1] | seg[node * 2 + 2]);
            return 0;
        }
        else
        {
            seg[node] = (seg[node * 2 + 1] ^ seg[node * 2 + 2]);
            return 1;
        }
    }
};
 
bool isPrime(int n)
{
 
    if (n <= 1)
        return false;
 
    if (n == 2 || n == 3)
        return true;
 
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 
    for (int i = 5; i <= sqrt(n); i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
// //Priority queue, set and iterator comparator
// class Compare
// {
//     //Comparotor work opposite in priority queue if you want to do asscending do descending order and vice versa
// public:
//     bool operator()(pair<int, int> &a, pii &b) const
//     {
//         int l1 = a.s - a.f + 1;
//         int l2 = b.s - b.f + 1;
//         if (l1 == l2)
//         {
//             return a.f > b.f;
//         }
//         return l1 < l2;
//     }
// };
 
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    // vector<int> graph[n];
    vector<vector<ll>> dis(n, vector<ll>(n, 1e18));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--, b--, w;
        // graph[a].pb({b});
        if (w < dis[a][b])
        {
            dis[a][b] = w;
            dis[b][a] = w;
        }
    }
 
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
 
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (a == b)
            dis[a][b] = 0;
        if (dis[a][b] == 1e18)
            cout << -1 << endl;
        else
            cout << dis[a][b] << endl;
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorials();
    //   sieve();
 
    int t = 1;
    //  cin >> t;
    //     int cnt = 0;
    //    prime_sieve();
    while (t--)
    {
        // cnt++;
        //   cout << "Case " << cnt << ": \n";
        solve();
    }
}
