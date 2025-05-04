/// KoJa
#include <bits/stdc++.h>
using namespace std;
#define task "test"
#define pb push_back
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(a) (1LL << (a))
#define vec vector
#define fi first
#define se second
#define mp make_pair
#define MASK(x, i) (((x) >> (i))&1)
typedef long long ll;
typedef pair<int, int> ii;
 
template <class T>
inline bool maximize(T &a, const T &b) { return (a < b ? (a = b, 1) : 0); }
template <class T>
inline bool minimize(T &a, const T &b) { return (a > b ? (a = b, 1) : 0); }
void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    else if (fopen(task ".in", "r"))
    {
        freopen(task ".in", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
 
struct Points
{
    ll x, y;
    void read()
    {
        cin >> x >> y;
    }
    Points(ll _x = 0, ll _y = 0)
    {
        x = _x;
        y = _y;
    }
    bool operator<(const Points &b) const
    {
        return (make_pair(x, y) < make_pair(b.x, b.y));
    }
    Points operator-(const Points &b) const
    {
        return Points(x - b.x, y - b.y);
    }
    ll operator*(const Points &b) const
    {
        return x * b.y - y * b.x;
    }
    ll triangle(const Points &b, const Points &c) const
    {
        return (*this - b) * (*this - c);
    }
    bool operator == (const Points &b)
    {
        return (x == b.x && y == b.y);
    }
};
const int N = int(1e6) + 100;
const ll INF = 1e18;
ll n;
int k;
ll a[21];
void init()
{
    cin >> n >> k;
    for(int i = 0; i < k; i++) cin >> a[i];
}
void process(const int &tc)
{
    ll ans = 0;
    for(int mask = 1; mask < BIT(k); mask++)
    {
        ll tmp = 1;
        bool ok = 1;
        for(int i = 0; i < k; i++) if(MASK(mask, i))
        {
            if(tmp <= n/a[i] + 1) tmp = tmp * a[i];
            else 
            {
                ok = 0;
                break;
            }
        }
        if(ok) 
        {
            //if(mask == 1) cout << n/tmp << '\n';
            if(__builtin_popcount(mask) & 1) ans += n/tmp;
            else ans -= n/tmp;
        }
    }
    cout << ans;
}
int main()
{
    fastio();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        init();
        process(i);
    }
    return 0;
}