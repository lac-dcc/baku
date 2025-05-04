#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
#define ull unsigned long long
#define lld long double
#define mp make_pair
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define vi vector<int>
#define vs vector<string>
#define usi unordered_set<int>
#define si set<int>
#define msi multiset<int>
#define mss multiset<string>
#define mii map<int,int>
#define mip map<int,pii>
#define umii unordered_map<int,int>
#define umip unordered_map<int,pii>
#define vpii vector<pii>
#define spii set<pii>
#define F first
#define I insert
#define S second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
#define eb emplace_back
#define bg(x) begin(x)
#define input(x) int x;cin>>x
#define ftl(x) bg(x), end(x)
#define setbits(x) __builtin_popcountll(x)
#define iforl(i, a, b) for (int i=a; i<(b); i++)
#define iforls(i, a) for (int i=0; i<(a); i++)
#define dforl(i, a, b) for (int i = (b); i >= a; i--)
#define dforls(i, a) for (int i = (a); i >= 0; i--)
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
const int md = 1000000007;
#define Shivam_Saurabh_18ss ios::sync_with_stdio(0);cin.tie(0)
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int lcm(int a, int b)
{
    return ((a * b) / gcd(a, b));
}
bool iseven(int n)
{
    if ((n & 1) == 1)
        return false;
    else
        return true;
}
bool ispowof2(int n)
{
    if (n == 0)
        return false;
    else
    {
        if (n & (n - 1))
            return false;
        else
            return true;
    }
}
bool checkkthsetbit(int n , int k)
{
    if (1 & (n >> k))
        return true;
    else
        return false;
}
void swap(int &x, int &y)
{
    x = x ^ y; y = x ^ y; x = x ^ y;
}
int32_t main() {
    Shivam_Saurabh_18ss;
#ifndef ONLINE_JUDGE
    freopen("debug.txt", "w", stderr);
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif
    int ttt = 1;
    //cin >> ttt;
    iforls(iii, ttt)
    {
        input(n); input(x1);
        vpii v;
        iforls(i, n)
        {
            input(y);
            //v.eb(y);
            v.eb(mp(y, i));
        }
        map<int, vpii> m;
        sort(ftl(v));
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                m[(v[i]).F + (v[j]).F].eb(mp((v[i]).S, (v[j]).S));
            }
        }
        debug(m);
        for (auto it : m)
        {
            int req = x1 - it.F;
            auto iti = m.find(req);
            if (iti != m.end())
            {
                for (auto itz : (*iti).S)
                {
                    for (auto io : it.S)
                    {
                        int a = itz.F; int b = itz.S; int c = io.F; int d = io.S;
                        if (a != c && a != d && b != c && b != d)
                        {
                            cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << endl;
                            return 0;
                        }
 
                    }
 
                }
            }
        }
        cout << "IMPOSSIBLE" << endl;
    }
}
