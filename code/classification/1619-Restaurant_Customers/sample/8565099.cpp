/*
*   user: oci_gt1
*   nombre: Christian Alexis Sierra Cruz
*   Escuela: IPU Ramon Infante Garcia
*   provincia: Guantanamo
*   problema: 1A
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define en endl
#define pb push_back
#define F first
#define S second
#define mid ((l+r) >> 1)
#define dbg(x) cout << #x << ": " << x << " "
#define vi vector<int>
#define pii pair<int,int>
#define vvi vector<vi>
#define ll long long
#define all(x) x.begin(),x.end()
#define awa return
#define rashomcqueen ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int nmax = 1000000;
const int INF = 9000000000000000000;
const int mod = 1e9+7;
int vis[nmax];
 
struct ord{
    int x = 0 , y = 0;
};
 
void solve(){
    int n;
    cin >> n;
    map<int , ord>mp;
    for(int i = 0 ; i < n ; i++){
        int a , b;
        cin >> a >> b;
        mp[a].x++;
        mp[b].y++;
    }
    int ans  = 0 , tmp = 0;
    for(auto z : mp){
        ord u = z.S;
        tmp += u.x;
        tmp -= u.y;
        ans = max(ans , tmp);
    }
    cout << ans;
}
 
 
int32_t main(){
    int t;
    ///cin >> t;
    t = 1;
    while(t--){
        solve();
    }
 
    awa 0;
}
