// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#define FASTER ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define edl '\n'
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define F(i,L,R) for (int i = L; i < R; i++)
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define pb push_back
#define mp make_pair
#define mem0(a) memset((a), 0, sizeof (a))
#define mem1(a) memset((a), -1, sizeof (a))
#define remax(a,b) (a)=max((a),(b));
#define remin(a,b) (a)=min((a),(b));
#define sz(s) (int)(s).size()
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vt vector
#define vi vt<int>
#define vl vt<ll>
#define vvi vt<vt<int>>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll nx2(ll n) {ll p = 1; if (n && !(n & (n - 1))) return n; while(p < n) p <<= 1; return p;}
namespace Debug {
    void dout() {cerr<<"\n";}
    template<typename Head,typename ...Tail> void dout(Head H,Tail... T) {cerr<<" "<<H;dout(T...);}
    template<typename T> void douta(const T *a,int n) {cerr<<"\n[";for (int i=0;i<n;i++) {cerr<<" "<<a[i];}cerr<<" ]\n";}
    template<typename T> void doutaa(T **b,int r,int c) {for (int i=0;i<r;i++) {cerr<<"[";for (int j=0;j<c;j++) {cerr<<" "<<b[i][j];}cerr<<" ]\n";}}
    template<typename T> void dout(const vector<T> v) {cerr<<"\n[";for (T i : v) {cerr<<" "<<i;}cerr<<" ]\n";}
    template<typename T> void dout(const vector<vector<T>> v) {cerr<<"\n";for (vector<T> u : v) {cerr<<"[";for (T i : u) {cerr<<" "<<i;}cerr<<" ]\n";}}
    template<typename F,typename S> void dout(const vector<pair<F,S>> u) {cerr<<"\n";for (pair<F,S> v : u) {cerr<<"[ "<<v.first<<" "<<v.second<<" ]\n";}}
} using namespace Debug;
// #define unsigned int long long
 
signed main()
{
    FASTER;
    int n;
    cin >> n;
    vt<pair<pi, int>> p(n);
    F(i,0,n) {
        int a, b, price;
        cin >> a >> b >> price;
        p[i] = {{a, b}, price};
    }
    sort(ALL(p), [](const pair<pi, int>& a, const pair<pi, int>& b) {
        if(a.first.second == b.first.second) {
            if(a.second == b.second) {
                a.first.first < b.first.first;
            }
            return a.second < b.second;
        }
        return a.first.second < b.first.second;
    });
    vl dp(n), mx(n);
    ll res = 0;
    F(i,0,n) {
        // dout(p[i].first.first, p[i].first.second, p[i].second);
        dp[i] = (ll)p[i].second;
        int l = 0, r = n - 1, m;
        while(l < r) {
            m = l + (r - l + 1) / 2;
            if(p[m].first.second < p[i].first.first) {
                l = m;
            }
            else {
                r = m - 1;
            }
        }
        if(p[l].first.second < p[i].first.first) {
            dp[i] += mx[l];
        }
        remax(res, dp[i]);
        mx[i] = res;
    }
    cout << res << edl;
}