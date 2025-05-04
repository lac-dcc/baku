#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define vii vector<ii>
#define vstr vector<str>
#define F first
#define S second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ln cout << '\n'
#define range(i, x, y) for (int i = x; i <= y; i++)
#define ranges(i, x, y) for (int i = x; i >= y; i--)
#define each(i,x) for (auto &(i) : (x))
#define sws ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define filein freopen("/home/shelter/Code/Input.txt", "r", stdin)
#define fileout freopen("/home/shelter/Code/Output.txt", "w", stdout)
#define Time cerr << "Time: " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
const int MAX = 1e9 + 7;
const int MAXn = 1e6 + 1;
 
ll MOD(ll a, ll b, ll p){
    return (1LL * ((a % p + p) % p) * ((b % p + p) % p) % p + p) % p;
}
 
bool cmp(pll a, pll b){
    if(a.S == b.S) return a.F > b.F ? false : true;
    return a.S > b.S ? false : true;
}
 
int main(){
    sws
    // filein;
    // fileout;
    ll n, k;
    cin >> n >> k;
    pll a[n + 1];
    range(i, 1, n) cin >> a[i].F >> a[i].S;
    sort(a + 1, a + n + 1, cmp);
    multiset<ll> mp;
    ll dem = 0;
    range(i, 1, k) mp.insert(0);
    range(i, 1, n){
        auto t = mp.upper_bound(a[i].F);
        if(t == mp.begin()) continue;
        mp.erase(--t);
        mp.insert(a[i].S);
        ++dem;
        // cout << i; ln;
    }
    cout << dem;
}
