#include "bits/stdc++.h"
using namespace std;
 
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foor(i, N) for(ll i = 0; i < N; ++i)
 
ll mod = 1000000000 + 7;
 
#define MAXN 100001
ll spf[MAXN];   
 
void sieve(){
    spf[1] = 1;
    for(ll i=2; i< MAXN; i++) spf[i] = i;
    for(ll i=4; i< MAXN; i+=2) spf[i] = 2;
    for(ll i=3; i*i< MAXN; i++){
        if(spf[i] == i){
            for(ll j = i*i; j< MAXN; j +=i ) if(spf[j]==j) spf[j] = i;
        }
    }
}
 
ll gcd(ll a, ll b){return b == 0 ? a : gcd(b, a % b);}
 
ll lcm(ll a, ll b){return a * b / gcd(a, b);}
 
ll max(ll a, ll b){return a > b ? a : b;}
 
ll min(ll a, ll b){return a < b ? a :  b;}
 
bool isVowel(char x){if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return true; return false;}
 
ll visited[2 * 100000];
vector <ll> g[2 * 100000];
 
void dfs(ll i){
    visited[i] = 1;
    for(auto it: g[i]){
        if(!visited[it]) dfs(it);
    }
}
 
void _(){
    ll n, m; cin >> n >> m; 
    foor(i, m){
        ll a, b; cin >> a >> b; 
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
    }
    vector <ll> comps;
    foor(i, n) visited[i] = 0;
    foor(i, n){
        if(!visited[i]){
            dfs(i);
            comps.pb(i);
        }
    }
    cout << comps.size() - 1 << endl;
    foor(i, comps.size()-1){
        cout << comps[i] + 1 << " " << comps[i+1] + 1 << endl;
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    ll t = 1;
    // sieve();
    // cin >> t; 
    for(ll test = 1; test <= t; test++){
        // cout << "Case #" << test << ": ";
        _(); 
        cout << endl;
    } return 0;
}