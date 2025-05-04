#include<bits/stdc++.h>
using namespace std;
#define sz(x) (int)((x).size())
#define popb  pop_back
#define ld  long double
#define rep(i,a,n) for(ll i=a;i<n;i++)
#define rrep(i,a,n) for(ll i=a;i>n;i--)
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define mem0(x) memset(x, 0, sizeof(x))
#define mem1(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define logarr(arr,a,b) for(ll z = a; z<b; z++) cout<<(arr[z])<<" ";
#define pq_max  priority_queue<ll>
#define pq_min  priority_queue<ll, vi, greater<ll>>
typedef pair<int,int>  pii;
typedef pair<ll,ll>    pl;
typedef vector<int>    vi;
typedef vector<ll>     vl;
typedef vector<pii>    vpii;
typedef vector<pl>     vpl;
typedef vector<vi>     vvi;
typedef vector<vl>     vvl;
const int mod = 1e9 + 7;
const int N = 3e5, M = N;
vi g[N];
int a[N];
void solve() {
    ll n, m, ans = 0;
    cin >> n >> m;
    if(n <= m) {
        if(m%2) ans = m*m - n + 1;
        else ans = (m-1)*(m-1) + n;
    } else {
        if(n%2) ans = (n-1)*(n-1) + m;
        else ans = n*n - m + 1;
    }
 
    cout << ans << endl;
 
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while(t--) {
       solve();
    }
    return 0;
}