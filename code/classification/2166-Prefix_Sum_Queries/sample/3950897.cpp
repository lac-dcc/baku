#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#define sz(a) (int)a.size()
#define pb push_back
#define all(a) a.begin(), a.end()
#define for0(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define x first
#define y second
#define int long long
 
using namespace std;
using namespace __gnu_pbds;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
const int inf = 1e18;
struct info{
    int mx = 0;
    int add = 0;
};
 
const int LG = 19;
int k = (1 << LG);
vector<info> t(2 * k);
 
void upd_sum (int v, int tl, int tr, int l, int r, int x) {
 
    if(r < tl || tr < l){
        return;
    }
    if(l <= tl && tr <= r){
        t[v].add += x;
        return;
    }
 
    int m = (tl + tr) / 2;
    upd_sum(v * 2, tl, m, l, r, x);
    upd_sum(v * 2 + 1, m + 1, tr, l, r, x);
    t[v].mx = max(t[2 * v].mx + t[2 * v].add, t[2 * v + 1].mx + t[2 * v + 1].add);
}
 
void push(int v){
 
    t[2 * v].add += t[v].add;
    t[2 * v + 1].add += t[v].add;
    t[v].mx += t[v].add;
    t[v].add = 0;
}
 
int get_max (int v, int tl, int tr, int l, int r) {
 
    if(r < tl || tr < l){
        return -inf;
    }
    if(l <= tl && tr <= r){
        return t[v].mx + t[v].add;
    }
 
    int m = (tl + tr) / 2;
    push(v);
    int lmx = get_max(v * 2, tl, m, l, r);
    int rmx = get_max(v * 2 + 1, m + 1, tr, l, r);
 
    return max(lmx, rmx);
}
 
 
signed main(){
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
       ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
        int n, q;
        cin >> n >> q;
        vi v(n + 1);
        int psv = 0;
        upd_sum(1, 0, k - 1, 0, 0, psv);
        for1(i, n){
            cin >> v[i];
            psv += v[i];
            upd_sum(1, 0, k - 1, i, i, psv);
        }
 
 
    for0(i, q){
        int type;
        cin >> type;
        if(type == 1){
            int pos, x;
            cin >> pos >> x;
            int d = -v[pos] + x;
            upd_sum(1, 0, k - 1, pos, k - 1, d);
            v[pos] = x;
        }
        else{
            int l, r;
            cin >> l >> r;
 
            int l1 = get_max(1, 0, k - 1, l - 1, l - 1);
            int ans = get_max(1, 0, k - 1, l, r);
 
            //cout << l <<' '<< r << ": "<<ans <<' '<< l1 << endl;
 
            cout << max(0ll, ans - l1) << "\n";
        }
 
    }
 
 
 
}
