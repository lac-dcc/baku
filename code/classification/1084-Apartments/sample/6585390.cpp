#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ld long double
typedef long long ll;
typedef double d;
#define vi vector<int>
#define vll vector<ll>
#define FF first
#define SS second
 
const int MAXN = 1e5 + 5;
const ll INF = 1e9;
const ll nINF = -1*INF;
const ll MOD = INF + 7;
const ld EPS = 1e-9;
const d pi = acos(-1);
double n, c;
 
ll pwr(ll num, ll p){
    ll ans = 1;
    for (ll i = 0; i<p; i++) ans*= num;
    return ans;
}
 
void print_map(map<ll, int> const &m){
    for (auto const &pair: m)
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
}
 
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
 
ll lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}
 
 
void solve(){
    ll n, m, k; cin >> n >> m >> k;
    int homes[n];
    int people[m];
    for(int i = 0; i<n; i++) cin >> homes[i];
    for(int i = 0; i<m; i++) cin >> people[i];
    sort(homes, homes + n);
    sort(people, people + m);
    
    int i = 0, j = 0, ans = 0;
    while(j < m){
        while (i < n && homes[i] < people[j] - k) i++;
 
        if (abs(homes[i] - people[j]) <= k){
            ans++;
            i++;
            j++;
        }
        else j++;
    }
    cout << ans << '\n';
    
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++) solve();
}
