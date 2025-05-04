/*  _______________________________________________________________
   ) Dinh Duc Hieu - I2124 - VNU-HCM High School for the Gifted   (
   | Warning: This code was produced by quadangvaica ...          |
   )                          /\/\                                (
   |                         ( ._.)                               |
   )                         / >0 \>1                             (
   |               _______________________________                |
   )              /   (Sleep)   /    (Train)     /                (
   |             /==============================/                 |
   )             ---------(choose one)----------                  (
   | Goal: Expert                                                 |
   )______________________________________________________________(
*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef tree<int,null_type,less<int>,
        rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
#define fi  first
#define se  second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(a) (int) a.size()
#define FOR(x,a,b) for (ll x=a;x<=b;x++)
#define FOD(x,a,b) for (ll x=a;x>=b;x--)
#define REP(x,a,b) for (ll x=a;x<b;x++)
#define RED(x,a,b) for (ll x=a;x>b;x--)
#define EL cout << "\n"
#define ii pair<int,int>
#define iii tuple<int,int,int>
#pragma GCC optimize("Ofast")
//
ll bpow(ll n, ll m, ll mod)
    {ll res=1; while(m){if(m&1) res=res*n%mod; n=n*n%mod; m>>=1;} return res;}
ll getbit(ll val, ll num)
    {return ((val>>(num-1)) & 1LL);}
ll lcm(ll a, ll b)
    {return a*b/__gcd(a,b);}
string bit(ll n, ll m)
    {string s=""; while(n){if(n&1) s+="1"; else s+="0"; n>>=1;} reverse(s.begin(),s.end()); while(sz(s)<m) s="0"+s; return s;}
 
//////////////// The main code start from here :b ////////////////
 
const ll N=3e6+5, M = 5e3+5, mod = 1e9+7, INF = 1e18;
ll n,a[N],res,x,k,y,t,z,m,tmp,d[M][M],vis[N],ans,q;
//
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    if(fopen("cf.inp","r")){
        freopen("cf.inp","r",stdin);
        freopen("cf.out","w",stdout);
    }
 
    cin >> n >> m >> q;
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!d[i][j]){
                d[i][j] = INF;
            }
        }
    }
 
    for(int i = 1; i <= n; i++) d[i][i] = 0;
 
    for(int i = 1; i <= m; i++){
        ll u, v, b;
        cin >> u >> v >> b;
        d[u][v] = min(d[u][v], b);
        d[v][u] = min(d[v][u], b);
    }
 
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if((d[i][j] > d[i][k] + d[k][j]) && (d[i][k] != INF) && (d[k][j] != INF)){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
 
    while(q--){
        cin >> x >> y;
        if(d[x][y] != INF){
            cout << d[x][y];EL;
        } else {
            cout << -1;EL;
        }
    }
}
/*
                           _
                         ooOoo
                       o8888888o
                       88" . "88
                       (| . .  |)
                       O\  =  /O
                     ___/`---'\___
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  ||||| -:- |||||    \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___. .'  /--.--\  . .'___
           ."" '<  `.___\_</>_/___.' _> \"".
          | | :  - \. ;`. _/; .'/ /  .' ;  |
          \  \ -.   \_\_. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'.'.-'================
 
          █▄ █ █▀█   █▄▄ █ █ █▀▀   █▀█ █   █▀
          █ ▀█ █▄█   █▄█ █▄█ █▄█   █▀▀ █▄▄ ▄█
*/
