#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define MOD 1000000007
#define MxN 1000005
#define ceil(a,b) a/b +(a%b!=0)
#define GCD(x,y) __gcd(x,y)
#define LCM(x,y) x*y/__gcd(x,y)
#define ll long long
#define ff first
#define ss second
#define ii pair<int,int>
#define vll vector<ll> 
#define pb push_back
#define endl "\n"
#define bits(n) __builtin_popcount(n)
#define sz(x) (int)(x).size()
#define for0(i,a,b) for(int i=a;i<b;i++)
#define for1(i,a,b) for(int i=a;i<=b;i++)
 
template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &x){return x;}
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char ch) { string s="";return s + ch;}
template<typename Container>
string to_string(const Container& cont) {
    string res ="";
    for(auto const& x : cont) {
        res += to_string(x);
        res += " ";
    }
    res += "\n";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p){
    return "\n["+to_string(p.first)+ ","+to_string(p.second)+"]";
}
template<typename T>
string to_string(T v){
    string res="";
    for(auto x: v){
        cerr <<x <<" ";
        res += to_string(v);
    }
    res+="\n";
    return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << (H)  << " ";
    debug_out(T...);
}
template<typename Container>
void debug_out(const Container& cont) {
    string res ="";
    for(auto const& x : cont) {
        res += to_string(x);
        res += " ";
    }
    res +="\n";
    cerr<< res <<endl;
}
template<std::size_t N, std::size_t M>
void debug_out(int (&A)[N][M]) {
    cerr<<endl;
    for(std::size_t i(0); i < N; ++i) {
        for(std::size_t j(0); j < M; ++j){
            std::cerr << A[i][j] << " ";
        }cerr<<endl;
    }cerr<<endl;
}
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif
 
// 2 2 2 3
// 2 2 3 2 
// 2 3 2 2 
// 3 2 2 2    
// 2 2 5
// 2 5 2 
// 5 2 2 
// 3 3 3
 
int n;
vector<int> coins(100);
int table[MxN];
 
int waystochange(int target){
 
    if(table[target] != -1)
        return table[target];
 
    if(target <0 )
        return table[target] = 0;
    if(target == 0)
        return table[target] = 1;
    
    int ans=0;    
    for(int i=0;i<n;i++){
        if(coins[i] <= target){
            ans += waystochange(target- coins[i]);
            ans %= MOD;
        }
    }
    return table[target] = ans%MOD;
}
 
 
 
void presolve(){
}
 
void solve(){
    int target;
    cin>>n>>target;
 
    memset(table,-1,sizeof(table));
 
    for0(i,0,n) cin>>coins[i];
    cout<<waystochange(target)<<endl;
}
 
 
int32_t main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE 
    freopen("inputA.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif 
 
 
int tc=1;
// cin>>tc;
presolve();
for0(i,0,tc){
    solve();
}
return 0;
}
