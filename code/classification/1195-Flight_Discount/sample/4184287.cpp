/*
ID: Yassine BenYounes
TASK: herding
LANG: C++                 
*/
#include<bits/stdc++.h>
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;} // greatest common divisor (PGCD)
ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);} // least common multiple (PPCM)
ll modd(ll x, ll n){while(x < 0){x += n;}return (x % n);} // modulo for negative numbers
#define endl "\n"
#define ss second
#define ff first
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vl vector<ll>
#define vll vector<pair<ll,ll>>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd  pair<double,double>
#define vdd  vector<pdd>
#define speed ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
 
void init(){
    #ifndef ONLINE_JUDGE
 
freopen("input.txt", "r", stdin);
 
freopen("output.txt", "w", stdout);
 
#endif // ONLINE_JUDGE
}
 
const int mx = 1e5+9;
const ll mod = 1e9+7;
const ll inf = 1e16;
 
vii graph[mx];
vii rgraph[mx];
ll distances[mx];
ll distances1[mx];
bool vis[mx];
int main(){
    //ofstream fout ("herding.out");
    //ifstream fin ("herding.in");
    init();
    speed;
    int n, m;cin >> n >> m;
    while(m--){
        int x,y, w;cin >> x >> y >> w;
        graph[x].pb({y, w});
        rgraph[y].pb({x, w});
    }
    for(int i = 1; i <= n;i++){
        distances[i] = inf;
        distances1[i] = inf;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> pq;
    pq.push({0, 1});
    distances[1] = 0;
    while(!pq.empty()){
        int node = pq.top().ss;
        ll dis = pq.top().ff;
        pq.pop();
        if(vis[node])continue;
        vis[node] = 1;
        for(pii adj: graph[node]){
            if(dis + adj.ss < distances[adj.ff]){
                distances[adj.ff] = dis + adj.ss;
            }
            pq.push({distances[adj.ff], adj.ff});
        }
    }
    memset(vis, 0, sizeof vis);
    pq.push({0, n});
    distances1[n] = 0;
    while(!pq.empty()){
        int node = pq.top().ss;
        ll dis = pq.top().ff;
        pq.pop();
        if(vis[node])continue;
        vis[node] = 1;
        for(pii adj: rgraph[node]){
            if(dis + adj.ss < distances1[adj.ff]){
                distances1[adj.ff] = dis + adj.ss;
            }
            pq.push({distances1[adj.ff], adj.ff});
        }
    }
    ll ans = inf;
    for(int u = 1; u <= n;u++){
        for(pii v : graph[u]){
            ans = min(ans, distances[u] + distances1[v.ff] + v.ss/2);
        }
    }
    cout << ans << endl;
}
 
/*
    NEVER GIVE UP!
    DOING SMTHNG IS BETTER THAN DOING NTHNG!!!
*/
