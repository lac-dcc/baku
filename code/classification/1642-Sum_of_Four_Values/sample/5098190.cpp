#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define foru(i, a, b, k) for(int i = a; i <= b; i+=k)
#define umap unordered_map
#define pii pair<int, int>
#define ford(i, a, b, k) for(int i = a; i >= b; i-=k)
#define vint vector<int>
#define vll vector<long long>
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define ctn continue
#define ld long double
 
template<typename T> bool maximize(T &res, const T &val) { if (res < val){ res = val; return true; }; return false; }
template<typename T> bool minimize(T &res, const T &val) { if (res > val){ res = val; return true; }; return false; }
template<typename T> ll power(T a, const T b) { ll res = 1, x = a, y = b; while(y){if(y & 1)res *= x; x = x * x; y>>=1;}; return res; }
template<typename T> ll modpower(T a, T b, const T &m) { ll res = 1, x = a, y = b; x %= m; while(y){if(y & 1){res *= x; res %= m;}; x = x * x; x %= m; y >>= 1; } return res % m; }
template<typename T> T lcm(T &a, T &b) { return a / __gcd(a, b) * b; }
 
template <typename T> bool getbit(T val, int i) { return (val >> i) & 1; }
template <typename T> int cntbit(T val)        { return val == 0 ? 0 : cntbit(val >> 1) + (val & 1); }
template <typename T> T offbit(T val, int i) { return val & (~(T(1) << i)); }
template <typename T> T onbit(T val, int i) { return val | (T(1) << i); }
 
inline int readInt()       {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();int n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
inline ll readLong()       {char c;while(c=getchar(),c!='-'&&(c<'0'||c>'9'));bool sign=(c=='-');if(sign)c=getchar();ll  n=c-'0';while(c=getchar(),c>='0'&&c<='9')n=10*n+c-'0';return(!sign)?n:-n;}
inline string readString() {char c;while(c=getchar(),c==' '||c=='\n'||c=='\t');string s({c});while(c=getchar(),c!=EOF&&c!=' '&&c!='\n'&&c!='\t')s+=c;return s;}
 
const  ll  MOD = (ll)1e9 + 7;
const  ll  LIM = 2e5 + 10;
const int    N = 62;
const int  INF = 1e9 + 7;
const  ll LINF = 0x3f3f3f3f3f3f3f;
const int  LOG = 18;
const int base = 331;
 
umap < int, int > l, r;
int n, x;
int a[LIM];
 
void read()
{
    n = readInt();
    x = readInt();
 
    foru(i, 1, n, 1) a[i] = readInt();
}
 
void solve()
{
    int mid = - 1;
    int lval, rval;
 
    foru(i, 2, n, 1)
    {
        foru(j, i + 1, n, 1) ++r[a[i] + a[j]];
    }
 
    foru(i, 2, n, 1)
    {
        foru(j, i + 1, n, 1) --r[a[i] + a[j]];
        ford(j, i - 1, 1, 1)
        {
            ++l[a[i] + a[j]];
            if(r[x - a[i] - a[j]] > 0)
            {
                mid = i;
                lval = a[i] + a[j];
                rval = x - lval;
                break;
            }
        }
        if(mid != - 1) break;
    }
 
    if(mid == - 1) return cout << "IMPOSSIBLE", void();
 
    bool ok = false;
    foru(i, 1, mid, 1)
    {
        foru(j, i + 1, mid, 1)
        {
            if(a[i] + a[j] == lval)
            {
                cout << i << " " << j << " ";
                ok = true;
                break;
            }
        }
        if(ok) break;
    }
 
    foru(i, mid + 1, n, 1)
    {
        foru(j, i + 1, n, 1)
        {
            if(a[i] + a[j] == rval) return cout << i << " " << j, void();
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    if(fopen("test01.inp", "r"))
    {
        freopen("test01.INP", "r", stdin);
        freopen("test01.OUT", "w", stdout);
    }
 
    read();
    solve();
    return 0;
}