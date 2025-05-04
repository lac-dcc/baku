#include <bits/stdc++.h>
using namespace std;
 
typedef long long                                    ll;
typedef vector<int>                                  vi;
typedef vector<long long>                            vll;
typedef vector<int, int>                             vii;
typedef vector<long long, long long>                 vllll;
typedef pair<int, int>                               pii;
typedef pair<long long, long long>                   pllll;
#define rep(i,a,b)                                   for(int i = a; i <= b; i++)
#define rrep(i,a,b)                                  for(int i = a; i >= b; i--)
#define trav(it,v)                                   for(auto it = v.begin(); it!= v.end(); it++)
#define pb                                           push_back
#define popb                                         pop_back  
#define sz(x)                                        x.size()
#define fr                                           first
#define sc                                           second
#define mk                                           make_pair
 
// DEBUG FUNCTIONS 
#ifndef ONLINE_JUDGE
 
template<typename T>
void __p(T a) {
    cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
    cout<<"{";
    __p(a.first);
    cout<<",";
    __p(a.second);
    cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it<a.end(); it++)
        __p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it!=a.end();){
        __p(*it); 
        cout<<",}"[++it==a.end()];
    }
 
}
template<typename T>
void __p(std::multiset<T> a) {
    cout<<"{";
    for(auto it=a.begin(); it!=a.end();){
        __p(*it); 
        cout<<",}"[++it==a.end()];
    }
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
    cout<<"{\n";
    for(auto it=a.begin(); it!=a.end();++it)
    {
        __p(it->first);
        cout << ": ";
        __p(it->second);
        cout<<"\n";
    }
    cout << "}\n";
}
 
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
    __p(a1);
    __p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
    cout<<name<<" : ";
    __p(arg1);
    cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    int bracket=0,i=0;
    for(;; i++)
        if(names[i]==','&&bracket==0)
            break;
        else if(names[i]=='(')
            bracket++;
        else if(names[i]==')')
            bracket--;
    const char *comma=names+i;
    cout.write(names,comma-names)<<" : ";
    __p(arg1);
    cout<<" | ";
    __f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#define error(...)
#endif
 
// DEBUG FUNCTIONS END 
 
//ll a[100006];
// ll mod = 998244353;
 
// const int N = 2e5+5;
// ll fact[N] ,inv_fact[N];
 
// long long powm(long long a, long long b) {
//     long long res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a %mod;
//         a = a * a %mod;
//         b >>= 1;
//     }
//     return res;
// }
 
// void pre_calculate(){
//     fact[0] = 1;
//     for(int i = 1;i<N;i++){
//         fact[i] = fact[i-1]*i % mod;
//     }
 
//     inv_fact[N-1] = powm(fact[N-1],mod-2);
 
//     for(int i = N-2;i>=0;i--){
//         inv_fact[i] = inv_fact[i+1]*(i+1) % mod;
//         //cout << inv_fact[i]<<"\n";
//     }
// }
ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
// vector<ll>c;
vector<vector<ll>>adj;
vector<ll> vis;
vector<ll>par;
vector<ll>d;
// ll m;
// //vector<ll> prev;
void dfs(ll v){
    vis[v-1] = 1; 
    for(ll u : adj[v-1]){
        if(vis[u-1] != 1){
            dfs(u);
        }
    }
 
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
 
    #ifdef LOCALFLAG 
        freopen("Input.txt", "r", stdin);
        freopen("Output2.txt", "w", stdout);
    #endif
    ll n,m; cin >> n >> m; vis.resize(n,0); adj.resize(n); d.resize(n,-1); par.resize(n,-1);
    for(ll i = 0;i<m;i++){
        ll a,b; cin >> a >> b;
        adj[a-1].pb(b); adj[b-1].pb(a);
    }
    queue<ll>q;
    q.push(1);  d[0] = 0; vis[0] = 1;
    while(!q.empty()){
        ll v = q.front(); q.pop();
        for(ll u : adj[v-1]){
            if(vis[u-1] != 1){
                d[u-1] = d[v-1]+1;
                q.push(u);
                par[u-1] = v;
                vis[u-1] = 1;
            }
        } 
    }
    if(d[n-1] == -1){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << d[n-1]+1 << "\n";
        vector<ll>vec;
        ll x = n;
        while(x>0){
            vec.pb(x);
            x = par[x-1];
        }
        for(ll i = 0;i<=d[n-1];i++){
            cout << vec[d[n-1]-i] << " ";
        }
    }
}