#include <bits/extc++.h>
#define ll long long
#define rep(i,a,b) for (ll i = a; i < b; i++)
#define inf pow(2,31)-1
 
using namespace std;
 
using namespace __gnu_pbds;
typedef tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll n,m;
const ll maxn = 1e5+5;
vector<ll> adj[maxn];
vector<ll> state(maxn,0);
//Unvisited -> 0
//Explored -> 1
//Visited -> 2
vector<ll> parent(maxn,-1);
 
bool cycleCheck(ll u){
    state[u] = 1;
    for (auto x: adj[u]){
        if (state[x] == 0){
            parent[x] = u;
            if (cycleCheck(x)) return true; 
        }
        else if (state[x] == 1){
            if (x == parent[u]){
                continue;
            }else{
                ll ans = 0;
                vector<ll> anss;
                // anss.push_back(u+1);
                ll k = u;
                while (k!=x){
                    anss.push_back(k+1);
                    k = parent[k];
                    ans++;
                }
                anss.push_back(k+1);
                anss.push_back(u+1);
                cout<<ans+2<<"\n";
                for (auto z:anss){
                    cout<<z<<" ";
                }
                return true;
            }
        }
    }
    state[u] = 2;
    return false;
}
 
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        ll a,b; cin>>a>>b;a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rep(i,0,n){
        if (state[i] == 0){
            if (cycleCheck(i)) return;
        }
    }
    cout<<"IMPOSSIBLE";
    // cout<<"\n";
    // rep(i,0,n){
    //     cout<<i+1<<" "<<parent[i]+1<<" "<<state[i]<<"\n";
    // }
}
 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
