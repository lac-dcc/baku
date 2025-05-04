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
template <class T> using Tree = tree<T, null_type, less<T>,
            rb_tree_tag,tree_order_statistics_node_update>;
 
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
 
const ll N = 3e6+5, M = 5e3+5, mod = 1e9+7, INF = 1e17;
ll n,a[N],res,x,k,y,t,z,m,tmp,ans[N],q,sum;
//
 
struct Node{
    ll sum, pre;
} st[2*N];
 
void build(ll id, ll l, ll r){
    if(l == r){
        st[id].sum = st[id].pre = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id].sum = st[id << 1].sum + st[id << 1 | 1].sum;
    st[id].pre = max(st[id << 1].pre, st[id << 1].sum + st[id << 1 | 1].pre);
}
 
void upd(ll id, ll l, ll r, ll k, ll val){
    if(k < l || r < k || l > r) return;
    if(l == r){
        st[id].sum = st[id].pre = val;
        return;
    }
    ll mid = (l + r) >> 1;
    if(k <= mid) upd(id << 1, l, mid, k, val);
    else upd(id << 1 | 1, mid + 1, r, k, val);
    st[id].sum = st[id << 1].sum + st[id << 1 | 1].sum;
    st[id].pre = max(st[id << 1].pre, st[id << 1].sum + st[id << 1 | 1].pre);
}
 
Node get(ll id, ll l, ll r, ll u, ll v){
    if(l > r || r < u || v < l){
        Node tmp;
        tmp.sum = tmp.pre = 0;
        return tmp;
    }
    if(u <= l && r <= v){
        return st[id];
    }
    ll mid = (l + r) >> 1;
    Node x = get(id << 1, l, mid, u, v),
         y = get(id << 1 | 1, mid + 1, r, u, v);
    Node tmp;
    tmp.sum = x.sum + y.sum;
    tmp.pre = max(x.pre, x.sum + y.pre);
    return tmp;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
 
    if(fopen("cf.inp","r")){
        freopen("cf.inp","r",stdin);
        freopen("cf.out","w",stdout);
    }
 
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
 
    build(1, 1, n);
    while(q--){
        cin >> k >> x >> y;
        if(k == 1) upd(1, 1, n, x, y);
        else cout << max(0LL, get(1, 1, n, x, y).pre),EL;
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
                /   ||||| -:- |||||   \
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
