#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
long long lcm(int a, int b)
{
    return (a / (__gcd(a, b))) * b;
}
#define gcd __gcd
#define yes "YES"
#define no "NO"
#define pb push_back
#define si size()
#define in " "
#define mone "-1"
#define zero "0"
#define one "1"
#define PI acos(-1)
#define endint "\n"
 
const int mxN = 2e5 + 1; // this line declared as max index
vector<pair<ll,ll>> v[mxN + 1];
ll cost[mxN + 1];
 
void dijstra(ll u, ll n) {
    ll a, m, mm, b;
    for (ll i = 2; i <= n; i++) {
        cost[i] = 1e18;
    }
    cost[u] = 0;
    priority_queue<pair<ll,ll>>q;
    q.push({-cost[u], u});
    while (!q.empty()) {
        a = q.top().second;
        b = -q.top().first;
        q.pop();
        //if(visit[a]==1)continue;
        //visit[a]=1;
        if (cost[a] < b) continue; // This line added
        for (auto i: v[a]) {
            m = i.first;
            mm = i.second;
            if (cost[m] > b + mm) {
                cost[m] = b + mm;
                q.push({-cost[m], m});
            }
        }
    }
}
int main() {
    ll n, m , a, b, c;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].pb({b, c});
        //v[b].pb({a , c}); // this line removed
    }
    dijstra(1, n);
    for (ll i = 1 ; i <= n; i++) {
        cout << cost[i] << in;
    }
    cout<<endl;
    return 0;
}
