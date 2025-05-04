#include <bits/stdc++.h>
#define endl '\n'
#define INF 987654321
#define p_q priority_queue
#define pbk push_back
#define rep(i, a, b) for (int i=a; i<=b; i++) 
#define all(v) (v).begin(), (v).end()
using namespace std;
using ll = long long;
#define int ll
using pii = pair<int, int>;
using ull = unsigned long long;
using vll = vector<int>;
using vvi = vector<vll>;
using vpii = vector<pii> ;
using mii = map<int, int>;
using si = set<int>;
using qi = queue<int>;
using qpii = queue<pii>;
using tiii = tuple<int, int, int> ; //get<0>(t);
using vtiii = vector<tiii>;
using spii = set<pii>;
using qtiii = queue<tiii>;
int A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
int dy[8] = {1,-1,0,0,1,1,-1,-1};
int dx[8] = {0,0,1,-1,1,-1,1,-1};
 
ll modular(ll num, ll mod) {
    num%=mod;
    return num < 0 ? num+mod : num;
}
void print(pii a) {
    cout << a.first << " " << a.second << endl;
}
 
template <typename T>
void print(const T& a) {
    cout << a << endl;
}
 
void print(const vector<pii>& v) {
    for(auto p : v) {
        print(p);
    }
    cout << endl;
}
template <typename T>
void print(const vector<T>& v) {
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}
bool inRange(int y, int x) {
    return 1<=y && y<=N && 1<=x && x<=M;
}
bool inRangeN(int y, int x) {
    return 1<=y && y<=N && 1<=x && x<=N;
}
 
void Solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vll a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(all(a));
    sort(all(b));
 
    int i = 0;
    int j = 0;
    int ans = 0;
    while (j < m && i < n) {
        if (a[i] > b[j]) {
            if (a[i] <= b[j] + k) {
                ans++;
                i++;
                j++;
            } else {
                j++;
            }
        } else if (a[i] < b[j]) {
            if (a[i] >= b[j] - k) {
                ans++;
                i++;
                j++;
            } else {
                i++;
            }
        } else {
            ans++;
            i++;
            j++;
        }
    }
 
    cout << ans << endl;
 
 }
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = 1;
    //cin >> T;
    while(T--) Solve();
}
