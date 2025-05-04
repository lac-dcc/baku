#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
/*typedef __int128 vll;
typedef unsigned __int128 uvll;*/
ll _i=0;
#define ffn(x) _i=x
#define llll pair<ll , ll>
#define stitr set<ll>::iterator
#define fora(y,x) for(ll y=_i;x>y;y++)
#define pb push_back
#define pf push_front
#define debu cout << "hello\n"
#define fi first
#define sec second
#define all(a) a.begin() , a.end()
const ll limit = 1e9+5; 
const ll ous=1e5+5;
const ll dx[4] = {0 , -1 , 1 , 0} , dy[4] = {1,0,0,-1};
vector<ll> adj[ous];
ll grd[ous] , arn =0 , kd = 0;
vector<ll> ans;
void dfs(ll  crt , ll prv , ll lrt){
    if(kd == -1){
        return;
    }
    grd[crt]=lrt;
    //cout << crt << " " << prv << " " << lrt << " " << kd <<  "\n";
    if(kd == 0)
        for(auto j:adj[crt]){
            /*if(crt == 5){
                cout << grd[1] << " " << grd[5] << "\n";
            }*/
            if(kd == 1 || kd==-1){
                break;
            }
            if(abs(grd[j] - grd[crt]) > 1 && grd[j] != 0){
                //cout << j << " " << crt << "\n";
                ans.pb(j);
                kd = 1;
                arn = j;
                break;
            }
            if(kd == -1){
                return;
            }
            if(j != prv && grd[j] == 0){
                dfs(j , crt , lrt+1);
            }
        }
    if(kd == -1){
        return;
    }
    if(kd == 1){
        ans.pb(crt);
    }
    if(arn == crt){
        kd = -1;
    }
}
void solve(){
    ll n , m;cin >> n >> m;
    for(ll i = 0;m>i;i++){
        ll x , y;cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    fora(i,n){
        if(grd[i+1] == 0){
            dfs(i+1 , 0 , 1);
        }
        if(ans.size() != 0){
            break;
        }
    }
    if(ans.size() == 0){
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << ans.size() << "\n";
    fora(i,ans.size()){
        cout << ans[i] << " ";
    }
    return;/**/
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0; 
}
