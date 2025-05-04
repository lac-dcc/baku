// ************************
// Author : coding_priest7
// ************************
#include <bits/stdc++.h>
using namespace std;
using std ::cin;
using std ::cout;
 
// clang-format off
#ifdef coding_priest7
#include "bug.hpp"
#else
#define debug(...)
#endif
#define                 int int64_t
#define                 INF 1e18
#define                 nline "\n"
#define                 pb push_back
#define                 ppb pop_back
#define                 mp make_pair
#define                 ff first
#define                 ss second
#define                 set_bits __builtin_popcountll 
#define                 sz(x) ((int)(x).size())
#define                 all(x) (x).begin(), (x).end() 
#define                 vii vector<int>
#define                 pii pair<int, int>
#define                 mii map<int, int>
#define                 sii set<int>
#define                 fo(i, a, b) for(int i = a; i < b; i++)
#define                 re(i, a, b) for(int i =b-1 ; i >=a; i--)
#define                 fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cerr.tie(NULL)
#define                 mem_1(v) memset(v,-1,sizeof(v))
#define                 mem_0(v) memset(v,0,sizeof(v))
 
typedef long long ll;
typedef long double lld;
const int32_t MOD =1e9+7, mod = 998244353;
 
template<typename T>istream& operator>>(istream& inp,vector<T>&x){for(auto &i:x){inp>>i;};return inp;}
template<typename T>ostream& operator<<(ostream& o,vector<T>&x){for(auto &i:x){o<<i<<" ";}return o;}
// clang-format on
 
//........................::^^^^^^^^^^^^^^^^^^::........................
//............................:: solution ::............................
vector<vii> adj;
 
void dfs(int nn, int pp, vii &disx)
{
    if (pp == -1)
        disx[nn] = 0;
    else
        disx[nn] = disx[pp] + 1;
    for (auto nbr : adj[nn])
    {
        if (nbr != pp)
            dfs(nbr, nn, disx);
    }
}
void solution()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    fo(i, 0, n - 1)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    vii disx(n + 1, 0), disy(n + 1, 0);
    dfs(1, -1, disx);
 
    int cor_x = 0, cor_y = 0;
    cor_x = max_element(all(disx)) - disx.begin();
 
    disx.assign(n + 1, 0);
    dfs(cor_x, -1, disx);
 
    cor_y = max_element(all(disx)) - disx.begin();
 
    dfs(cor_y, -1, disy);
 
    fo(i, 1, n + 1)
    {
        cout << std::max(disx[i], disy[i]) << " ";
    }
}
 
//........................::^^^^^^^^^^^^^^^^^^::........................
//............................:: test cases ::..........................
 
signed main()
{
    fastio();
    int t_case = 1;
    // cin >> t_case;
 
    for (int32_t t = 1; t <= t_case; t++)
    {
        solution();
    }
    return 0;
}
