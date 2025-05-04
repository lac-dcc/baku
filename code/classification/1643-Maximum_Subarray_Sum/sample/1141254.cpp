#include <bits/stdc++.h>
#define FIXED_FLOAT(x)  std::fixed <<std::setprecision(7)<<(x)
#define all(v) (v).begin(), (v).end()
using namespace  std;
#define loop(i,a,b) for (int i=a; i<b; ++i)
using ll = long long;
const int mod = 1e9 + 7;
typedef pair<int , int> pairs;
typedef complex<ll> G;
 
const int N = 1e3 + 5;
 
int power(int a,int b){
    if(!b)
        return 1;
    int c=power(a,b/2);
    c=(1LL*c*c)%mod;
    if(b%2)
        c=(1LL*c*a)%mod;
    return c;
}
 
 
void done() {
 
 
}
 
/*string solve_palindrome(const string& s)
{
    string a = s;
    reverse(a.begin(), a.end());
    //a = s + "#" + a;
    int c = 0;
    for (int i = 1; i < (int)a.size(); i++)
    {
        while (c != 0 && a[c] != a[i])
            c = pref[c - 1];
        if (a[c] == a[i])
            c++;
        pref[i] = c;
    }
    return s.substr(0, c);
}
*/
 
/*3
3 7 7 9 11
4 6 6 7*/
int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
int mul(int x, int y) { return (1ll * x * y) % mod; }
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n);
    for(int i = 0;i < n;++i) {
 
        cin >> a[i];
    }
 
    ll best = a[0];
    ll best_s = a[0];
    for(int i = 1;i < n;++i) {
        best = max(a[i], best + a[i]);
        best_s = max(best_s, best);
    }
    cout << best_s << '\n';
 
}
 
 
void another() {
    int n;
    cin >> n;
    int f, x;
    vector<int>a(n);
    cin >> x >> f;
    for(int i = 0;i < n;++i) {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 0;i < n;++i) {
        if(a[i] > x) {
            ans += (a[i] - x)/(x + f) + (bool)((a[i] - x)%(x + f));
        }
    }
    cout << ans * f * 1ll ;
}
 
void test_case() {
    int t;
    cin >> t;
    while(t--)another();
}
int main() {
 
    ios::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
 
    solve();
}