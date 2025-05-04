///Astalavista Code........~CodeSlayer007
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define Br cout<<endl
#define pb push_back
#define mp make_pair
#define fe first
#define se second
#define int long long
#define double long double
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define PT(x) cout << (x) << endl
#define PTT(x) cout << (#x) << " is " << (x) << endl
#define SPD_emergency ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int M = 1e9 + 7;
const int N = 2e5 + 10;
const int IM = 1e15 + 37;
const double PI = 3.1415926535897932384;
void PV(vi v) { for (int i = 0 ; i < v.size() ; i++) cout << v[i] << " "; cout << endl;}
void PVV(vii v) {for (int i = 0 ; i < v.size() ; i++) cout << v[i].fe << " " << v[i].se << endl;}
void PA(int v[], int n, int x = 0) { for (int i = x ; i < n + x; i++)cout << v[i] << ' ' ; cout << endl;}
void IN(int a[], int n, int x = 0) {for (int i = x; i < n + x; i++)cin >> a[i];}
inline void PP(int n) { cout << n << " ";}
inline void PP(int n, int m) { cout << n << " " << m << endl;}
inline void PP(int n, int m, int q) {  cout << n << " " << m << " " << q << endl;}
inline void PP(int n, int m, int q, int u) {  cout << n << " " << m << " " << q << " " << u << endl;}
inline void op() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// <-------------------------------------------------------------------------------------------------------------------------------------------------------------------------> Ignore This--> priority_queue setprecision memset substr pop_back  insert tuple first second push_back string continue make_pair break deque stack queue sort reverse accumulate  count lower_bound upper_bound next_permutation copy_n __builtin_popcount make_tuple
// <========================================================================================================================================================================
 
int n, m;
struct edge {
    int x;
    int y;
    int l;
};
vector<edge> v;
int dis[N], par[N];
 
signed  main() {
    SPD_emergency
    //op();
    int i, j, x, y, u, k, l;
    //int t; cin >> t; while (t--)
    {
        i = j = x = y = u = k = l = 0;
 
        cin >> n >> m;
        edge e;
        for (i = 0; i < m; i++) {
            cin >> e.x >> e.y >> e.l;
            v.push_back(e);
        }
        for (i = 1; i <= n; i++)
            dis[i] = IM;
        for ( i = 1; i <= n; i++) {
            u = 0;
            for (edge it : v) {
                if (dis[it.y] > dis[it.x] + it.l) {
                    dis[it.y] = dis[it.x] + it.l;
                    par[it.y] = it.x;
                    u = it.y;
                }
            }
        }
        if (!u)
            PT("NO");
        else {
            PT("YES");
            //PA(dis, n, 1);
            //PA(par, n, 1);
 
            for (i = 1; i <= n; i++)
                u = par[u];
            vi ans;
            for ( i = u ;; i = par[i]) {
                ans.push_back(i);
                if (i == u && ans.size() > 1)
                    break;
                if (ans.size() > n)
                    break;
            }
            reverse(all(ans));
            PV(ans);
        }
 
 
 
 
 
 
 
        /**/
    }
 
    return 0;
}
