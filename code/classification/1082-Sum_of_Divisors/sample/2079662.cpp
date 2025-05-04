#include <bits/stdc++.h>
#define ll long long
ll md = 1000000007;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define pb push_back
#define g(v, i, j) get<i>(v[j])
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define fi(i, a, b) for (int i = a; i < b; i++)
#define fll(i, a, b) for (ll i = a; i < b; i++)
using namespace std;
//using namespace std::chrono;
template <typename T>
T pw(T a, T b)
{
    T c = 1, m = a;
    while (b)
    {
        if (b & 1)
            c = (c * m);
        m = (m * m), b /= 2;
    }
    return c;
}
template <typename T>
T ceel(T a, T b)
{
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}
template <typename T>
T my_log(T n, T b)
{
    T i = 1, ans = 0;
    while (1)
    {
        if (i > n)
        {
            ans--;
            break;
        }
        if (i == n)
            break;
        i *= b, ans++;
    }
    return ans;
}
template <typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
template <typename T>
T mysqt(T a)
{
    T ans = 1;
    while (ans * ans <= a)
        ans++;
    ans--;
    return ans;
}
ll pwmd(ll a, ll b)
{
    ll c = 1, m = a;
    while (b)
    {
        if (b & 1)
            c = (c * m) % md;
        m = (m * m) % md;
        b /= 2;
    }
    return c;
}
ll modinv(ll n)
{
    return pwmd(n, md - 2);
}
ll inverse(ll i)
{
    if (i == 1)
        return 1;
    return (md - ((md / i) * inverse(md % i)) % md + md) % md;
}
bool sortbysec(const pair<ll, ll> &a,
               const pair<ll, ll> &b)
{
    return (a.second < b.second);
}
/* auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken: "
         << duration.count()<< "ms" <<"\n";*/
vector<char> capl = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
vector<char> sml = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
template <typename T>
string conv(T a)
{
    string b;
    T e = 2;
    T c = my_log(a, e);
    c++, b = '1';
    for (T i = 0; i < c - 1; i++)
    {
        T k = a >> (c - 2 - i);
        if (k & 1)
            b += '1';
        else
            b += '0';
    }
    if (a == 0)
        return "0";
    return b;
}
int main()
{
    fast;
    ll n;
    cin >> n;
    ll ans = 0;
    ll l = sqrt(n);
    fll(i, 1, l + 1){
        ll q = (n / i) * i;
        q = q % md;
        ans = (ans + q) % md;
    }
    //cout << ans << "\n";
    for (ll i = sqrt(n); i >= 1; i--){
        ll r = n / i, s = 0;
        ll w = ((r % md) * ((r + 1) % md)) % md;
        w = (w * inverse(2LL)) % md;
        s = w;
        ll e = ((l % md) * ((l + 1) % md)) % md;
        e = (e * inverse(2LL)) % md;
        s = (s - e) % md;
        s = (s + 2LL * md) % md;
        l = r;
        s = (s * i) % md;
        ans = (ans + s) % md;
    }
    cout << ans;
}