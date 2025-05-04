#include <bits/stdc++.h>  
using namespace std;
 
// ---------------------------Macros & Typedefs---------------------------
 
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define endl "\n"
 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
 
// ---------------------------Read/Write Helper---------------------------
 
template <typename... T>
void read(T &...args) {
    ((cin >> args), ...);
}
 
template <typename... T>
void write(string delimiter, T...args) {
    ((cout << args << delimiter), ...);
}
 
 
template <typename T>
void readContainer(T &t) {
    for (auto &e : t) {
        read(e);
    }
}
 
template <typename T>
void writeContainer(string delimiter, T &t) {
    for (const auto &e : t) {
        write(delimiter, e);
    }
    cout<<"\n";
}
 
// ---------------------------Debugging Helpers---------------------------
 
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = " ";
    (..., (cout << delim << values, delim = ", "));
    cout<<"\n";
}
 
 
 
// ---------------------------My Code Goes Here---------------------------
 
int solve(int x, vector<int>&coins, vector<int>&dp, vector<int>&vis){
    if(x<0) return INT_MAX;
    if(x==0) return 0;
    if(vis[x]) return dp[x]; 
    int res = INT_MAX;
    for(auto coin: coins){
        res = min(res, solve(x-coin, coins, dp, vis));
    }
    vis[x] = 1;
    if(res == INT_MAX) return dp[x] = INT_MAX;
    return dp[x] = res+1;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    
    int n, x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
 
    vector<int>dp (x+1,INT_MAX);
    vector<int>vis (x+1,0);
    dp[0] = 0;
    vis[0]=1;
 
 
	solve(x, coins, dp, vis);
    cout<<(dp[x]==INT_MAX?-1:dp[x])<<endl;
 
    
    return 0;
}