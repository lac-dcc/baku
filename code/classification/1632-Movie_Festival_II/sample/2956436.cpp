#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define endl "\n"
#define pb push_back
#define mems(x,y) memset(x,y,sizeof(x))
#define all(x) (x).begin(),(x).end()
#define forn(i,s,e) for(int i = s; i < (e); ++i)
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define time__(d)                                                   \
for (                                                                   \
auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second;                                               \
debug("%s : %lld ms\n ", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false)
const int M = 1e9 + 7;
 
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <class T> T ABS(const T &x) {return x>0? x:-x;}
ll gcd(ll n1, ll n2) {return n2==0? ABS(n1) : gcd(n2,n1%n2);}
ll lcm(ll n1, ll n2) {return n1==0 && n2==0? 0 : ABS(n1*n2)/gcd(n1,n2);}
ll ceil2(ll a, ll b) {return (a + b - 1) / b;}
 
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T> vector<T> sorttrunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
// int dx[4] = {1,-1,0,0};
// int dy[4] = {0,0,1,-1};
 
int main()
{
FASTIO
    int n, k;
    cin >> n >> k;
    vpll coor(n);
    for(auto &el: coor) {
        cin >> el.second >> el.first;
    }
    sort(all(coor));
    multiset<int> endTime;
    forn(_,0,k)
        endTime.insert(0);
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        auto it = endTime.upper_bound(coor[i].second);
        if(it != endTime.begin()) {
            endTime.erase(prev(it));
            endTime.insert(coor[i].first);
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
