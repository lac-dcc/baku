#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
//#define int long long
//typedef long long ll;
#define forn(i,n) for (long long i = 0; i < n; i++)
#define formn(i, m, n) for (long long i = m; i < n; i++)
typedef long long ll;
#define SORT(v) sort(v.begin(), v.end())
#define REVERSE(v) reverse(v.begin(), v.end())
#define pb push_back
#define vll vector<ll>
typedef long double ld;
const int INF = 1e9;
const int N = 1e5 + 10;
 
// void build(vll &arr, vll &segtree, ll s, ll e, ll x)
// {
//     if (s == e)
//     {
//         segtree[x] = arr[s];
//         return;
//     }
 
//     ll mid = (s + e) / 2;
//     build(arr, segtree, s, mid, 2 * x);
//     build(arr, segtree, mid + 1, e, 2 * x + 1);
 
//     segtree[x] = max(segtree[2 * x], segtree[2 * x + 1]); //function change according to question
// }
 
// void update(vll &arr, vll &segtree, ll s, ll e, ll x, ll pos, ll val)
// {
//     if (s == e)
//     {
//         segtree[x] = val;
//         arr[pos] = val;
//         return;
//     }
 
//     ll mid = (s + e) / 2;
//     if (pos > mid)
//     {
//         update(arr, segtree, mid + 1, e, 2 * x + 1, pos, val);
//     }
//     else
//     {
//         update(arr, segtree, s, mid, 2 * x, pos, val);
//     }
 
//     segtree[x] = max(segtree[2 * x], segtree[2 * x + 1]); //function change according to question
// }
 
// ll query(vll &arr, vll &segtree, ll s, ll e, ll x, ll left, ll right)
// {
//     if (s > right or e < left)
//     {
//         return (ll)0;                                 //function change according to question
//     }
 
//     if (s >= left and e <= right)
//     {
//         return segtree[x];
//     }
 
//     ll mid = (s + e) / 2;
 
//     ll a1 = query(arr, segtree, s, mid, 2 * x, left, right);
//     ll a2 = query(arr, segtree, mid + 1, e, 2 * x + 1, left, right);
 
//     return max(a1, a2);
// }
 
// vll segtree(4*n,0);
// build(a,segtree,0,n-1,1);
// query(a,segtree,0,n-1,1,l,r);
// update(a,segtree,0,n-1,1,pos,val);
 
// void mai()
// {
//     ll n;
//     cin >> n;
 
//     vll a(n);
//     rep(i, 0, n)
//     cin >> a[i];
 
//     vll segtree(4 * n, 0);
 
//     build(a, segtree, 0, n - 1, 1);
 
//     ll q;
//     cin >> q;
//     while (q--)
//     {
//         ll type;
//         cin >> type;
 
//         if (type == 1)
//         {
//             ll l, r;
//             cin >> l >> r;
//             cout << query(a, segtree, 0, n - 1, 1, l, r);
//         }
//         else
//         {
//             ll pos, val;
//             cin >> pos >> val;
//             update(a, segtree, 0, n - 1, 1, pos, val);
//         }
//     }
 
// }
void abhishek() {
    int a = 12;
    int b = 23;
}
 
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> v;
    forn(i, n) {
        ll x;
        cin >> x;
        v.push_back({x, i + 1});
    }
    bool b = 0;
    SORT(v);
    int i = 0, j = n - 1;
    while (i < j) {
        if (v[i].first + v[j].first > x)j--;
        else if (v[i].first + v[j].first < x)i++;
        else {
            b = 1;
            cout << min(v[i].second, v[j].second) << " " << max(v[i].second, v[j].second) << endl;
            break;
        }
    }
    if (b == 0)
        cout << "IMPOSSIBLE" << endl;
}
 
 
int main() {
    //cout<<"Asdasda";
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);           //Used to reduce the time
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // t = 1;
    // cin >> t;
    // cout << 123 << endl;
    while (t--) {
        solve();
    }
}