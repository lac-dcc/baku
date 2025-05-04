#include<bits/stdc++.h>
#define X first
#define Y second
#define all(x) begin(x), end(x)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define FORD(i, b, a) for(int i = (b); i >= (a); i--)
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define mxx max_element
#define mnn min_element
#define SQR(x) (1LL * (x) * (x))
#define MASK(i) (1LL << (i))
#define Point Vector
#define left Left
#define right Right
#define div Div
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<db, db> pdb;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef pair<ll, int> pli;
typedef pair<ll, pii> plii;
 
template<class A, class B>
    bool maximize(A& x, B y) {
        if (x < y) return x = y, true; else return false;
    }
template<class A, class B>
    bool minimize(A& x, B y) {
        if (x > y) return x = y, true; else return false;
    }
 
/* END OF TEMPLATE */
 
const int N = 2e5 + 7;
 
int n, k;
 
pii a[N];
 
int main() {
//    freopen("test.INP", "r", stdin);
//    freopen("test.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    FOR(i, 1, n) cin>>a[i].X>>a[i].Y;
    sort(a + 1, a + 1 + n, [=](pii x, pii y){
         return x.Y < y.Y;
    });
//    FOR(i, 1, n) cout<<a[i].X<<" "<<a[i].Y<<"\n";
    multiset<pii> s;
//    FOR(i, 1, k) s.insert({a[i].Y, 1});
    FOR(i, 1, n) {
        if (s.empty()) s.insert({a[i].Y, 1}); else {
            multiset<pii>::iterator it = s.upper_bound({a[i].X, INT_MAX});
            if (it == s.begin()) {
                if ((int)s.size() == k) continue;
                s.insert({a[i].Y, 1});
            }
            else {
                it--;
                pii tmp = *it;
                s.erase(it);
                s.insert({a[i].Y, tmp.Y + 1});
            }
        }
    }
    int res = 0;
    vector<int> a;
    for (auto x : s) a.push_back(x.Y);
    sort(all(a), greater<int>());
    REP(i, 0, min((int)a.size(), k)) res+=a[i];
    cout<<res;
    return 0;
}