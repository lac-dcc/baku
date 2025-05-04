//
// If the path to what you want seems too easy, then you are at the wrong path.
 
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define fr(n) for(ll i = 0 ; i < n ; i++)
#define frj(n) for(ll j = 0 ; j < n ; j++)
#define ll long long
#define files    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define code_of_thrones ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
 
const ll mod = 1e9 + 7;
 
using namespace std;
 
 
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
 
ll mult(ll a, ll b){
    return (a%mod * b%mod)%mod;
}
 
ll add(ll a, ll b){
    return (a%mod + b%mod)%mod;
}
ll subtract(ll a, ll b){
return (a%mod - b%mod + 2*mod)%mod;
}
const unsigned ll N = 1e6 + 5;
 
int knightX[] = {-2, -2, 2, 2, 1, 1 , -1, -1};
int knighty[] = {-1, 1, -1, 1, -2, 2, -2, 2};
 
int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
int dy[] = {0, -1, 0, 1, -1, 1, -1, 1};
char di[] = {'D', 'L', 'U', 'R'};
 
ll n, m, k;
 
vector<int> adj[N];
int dist[N], parent[N];
 
void bfs(){
    queue<int> q;
    q.emplace(1);
    dist[1] = 1;
 
    int level = 1;
    while (!q.empty())
    {
        int sz = q.size();
 
        while (sz--)
        {
            int curr = q.front();
            q.pop();
 
            for(auto u : adj[curr]){
                if(dist[u] == 1e8)
                    q.emplace(u), dist[u] = level+1, parent[u] = curr;
            }
        }  
 
        level++;
    }
    
}
 
void solve(){
    cin >> n >> m;
 
    fr(n)
        dist[i+1] = 1e8, parent[i+1] = -1;
 
    fr(m){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    bfs();
 
    if(dist[n] == 1e8){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << dist[n] << endl;
        vector<int> ans;
        int curr = n;
        ans.push_back(curr);
        while (parent[curr] != -1)
            ans.push_back(curr = parent[curr]);
        
        reverse(all(ans));
        for(auto x : ans)
            cout << x << ' ';
        
        cout << endl;
    }
}
 
int main() {
    code_of_thrones
    #ifndef ONLINE_JUDGE
        files
    #endif
    // sieve();
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
