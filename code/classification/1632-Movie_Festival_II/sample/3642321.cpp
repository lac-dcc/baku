// #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define pf push_front
#define mp make_pair
#define y1 yyyyy
#define y0 yyyyyy
#define time time123
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
void fr(){
    freopen("bridges.in", "r", stdin);
    freopen("bridges.out", "w", stdout);
}
 
const int N = 5e4 + 5;
const int MAX = 1e6;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const double pi = 3.1415926536;
double eps = 1e-10;
 
// check long long, array bounds
// special cases (n = 1)
 
 
 
void solve(){
    int n, k;
    cin>>n>>k;
    vector<pii> v;
    for(int i = 1;i <= n;i++){
        int l, r;
        cin>>l>>r;
        v.pb({r, l});
    }
    sort(v.begin(), v.end());
    int cur = k, cnt = 0;
    multiset<int> s;
    for(int i = 0;i < n;i++){
        auto it = s.upper_bound(v[i].S);
        if(it != s.begin()){
            it--;
            cnt++;
            s.erase(it);
            s.insert(v[i].F);
        }
        else if(cur > 0){
            cnt++;
            cur--;
            s.insert(v[i].F);
        }
    }
    cout<<cnt;
    // check long long, array bounds
    // special cases (n = 1)
}
 
int T;
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // fr();
    T = 1;
    // cin>>T;
    for(int i = 1;i <= T;i++){
        solve();
    }
    return 0;
}
