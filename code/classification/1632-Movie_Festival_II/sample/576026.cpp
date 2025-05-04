#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;
#define getbit(n, i) (((n) & (1LL << (i))) != 0) 
#define setbit0(n, i) ((n) & (~(1LL << (i)))) 
#define setbit1(n, i) ((n) | (1LL << (i))) 
#define togglebit(n, i) ((n) ^ (1LL << (i))) 
#define lastone(n) ((n) & (-(n))) 
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first << gap << p.second << ')';
}
 
template <class T>
void read(T &x) {
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        ;
    for (x = 0; c <= '9' && c >= '0'; c = getchar()) x = x * 10 + (c & 15);
}
#define ll long long 
#define lll __int128_t
#define pb push_back
#define mp make_pair
typedef pair < int,int> ii;
typedef vector<ii> vii;
typedef vector<ll>vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;
#define INF 2e9+1
map<pair<ll,ll>,ll>mp1;
set<pair<ll, ll>> s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll i, j, k, l, n, m;
    cin >> n >> k;
    vector<pair<ll, ll>> data;
    for (i = 1; i <= n;i++){
        ll a, b;
        cin >> a >> b;
        data.pb({b, a});
    }
    sort(data.begin(), data.end());
    ll cnt = 0;
    multiset<ll> kola;
    for(auto x:data){
        if(kola.empty()){
            kola.insert(x.first);
            cnt++;
        }
        else{
            auto it = kola.upper_bound(x.second);
            if(it==kola.begin()){
                if(kola.size()<k){
                    kola.insert(x.first);
                    cnt++;
                }
            }
            else{
                it--;
                kola.erase(it);
                kola.insert(x.first);
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}