#include <bits/stdc++.h>
        
using namespace std;
    
#define ar array
#define ll long long
 
#ifndef ONLINE_JUDGE
#define debug(x) cout<<#x<<" ";_print(x); cout<<"\n";
#else
#define debug(x)
#endif
 
void _print(int a) {cout<<a;}
void _print(ll a) {cout<<a;}
void _print(char a) {cout<<a;}
void _print(string s) {cout<<s;}
void _print(bool s) {cout<<s;}
template <class T> void _print(vector<T> v) {cout<<"[ "; for(auto i: v) {_print(i); cout<<" ";} cout<<"]";}
template <class T> void _print(set<T> s) {cout<<"[ ";for(auto i: s) {_print(i);cout<<" ";}cout<<"]";}
 
template <class T>
void _print(vector<vector<T>> v) {
    for(ll i=0;i<v.size();i++) {
        for(ll j=0;j<v[i].size();j++) {
            _print(v[i][j]);
            cout<<" ";
        }
        cout<<"\n";
    }
}
 
const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
void output_vector(vector<ll>& v) {
    for(ll i=0;i<v.size()-1;i++) {
        cout<<v[i]<<" ";
    }
    cout<<v.back()<<"\n";
}
 
vector<ll> graph[MAX_N];
ll vis[MAX_N];
 
void dfs(ll v) {
    vis[v] = true;
    for(auto ver: graph[v]) {
        if(!vis[ver]) dfs(ver);
    }
}
 
void solve() {
 
    ll n, m;
    cin>>n>>m;
 
    ll u, v;
    for(ll i=0;i<m;i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
 
    ll cnt = 0;
    vector<ll> ans;
    for(ll i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i);
            ans.push_back(i);
            cnt++;
        }
    }
 
    debug(ans);
 
    cout<<(cnt-1)<<"\n";
    for(ll i=1;i<ans.size();i++) {
        cout<<ans[i-1]<<" "<<ans[i]<<"\n";
    }
    
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}
