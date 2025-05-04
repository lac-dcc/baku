#include<bits/stdc++.h>
 
#define F first
#define S second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<bool> vb;
 
const int MAXN = 1e5+5;
const ll INF = 1e18;
int n,m,a,b,c;
 
vector<pll> g[MAXN];
ll dist[MAXN];
bool v[MAXN];
 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
 
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        g[a].pb({b,c});
    }
 
    for(int i=0; i<=n; i++) dist[i] = INF;
    dist[1] = 0;
    set<pll> q;
    q.insert({0,1});
    while(!q.empty()){
        ll u = q.begin()->second;
        q.erase(q.begin());
        for(auto e:g[u]){
            ll to = e.F;
            ll w = e.S;
 
            if(dist[u] + w < dist[to]){
                q.erase({dist[to],to});
                dist[to] = dist[u] + w;
                q.insert({dist[to], to});
            }
        }
    }
 
    for(int i=1; i<=n; i++)
        cout << dist[i] << ' ';
    cout << '\n';
 
    return 0;
}
 
 
