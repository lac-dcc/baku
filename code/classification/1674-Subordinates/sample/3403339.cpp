#include <bits/stdc++.h>
#include <limits.h>
#include <math.h>
#define mod 1000000007
#define pi 3.14159265
//  sin((deg*pi)/180.0);
 
using namespace std;
 
#define int long long int
 
 
// SOE
 
// const int x = 2000000;
// vector<int> soe(int n){
    
//     vector<int> prime(x,1);
//     prime[0] = 0;
//     prime[1] = 0;
//     for (int i=2; i<=n; i++){
//         for (int j=2*i; j<x; j+=i){
//             prime[j] = 0;
//         }
//     }
//     return prime;
// }
 
 
inline int ceil2(int a, int b) {
    return (a + b - 1) / b;
}
 
inline int hcf(int n1, int n2){
    //  gcd(a,b) = gcd(a,b-a)
    
    if (n2 != 0)
       return hcf(n2, n1 % n2);
    else 
       return n1;
}
 
int binpow(int a, int b){
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 
int binpow(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
int primefactor(int n){
    int cnt = 0;
    while(n%2==0){
        n/=2;
        cnt++;
    }
    for(int i=3;(i*i)<=n;i+=2){
        while(n%i==0){
            n/=i;
            cnt++;
        }
    }
    if(n>2){
        cnt++;
    }
 
    return cnt;
}
 
inline void init_code(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
 
int n;
vector<vector<int>> g;
vector<int> emp;
 
int dfs(int u){
    int val = 1;
    for(auto v : g[u]){
        if(emp[v]==(-1)){
            int x = dfs(v);
            val+=x;
        }
        else{
            val+=emp[v];
        }
    }
    emp[u] = val;
    return emp[u];
}
 
void solve(){
 
    int input;
    cin>>n;
    g.resize(n+1);
    emp.assign(n+1,-1);
 
    for(int i=2;i<=n;i++){
        cin>>input;
        g[input].push_back(i);
    }
 
    int ans = dfs(1);
 
    for(int i=1;i<(n+1);i++){
        cout<<(emp[i]-1)<<" ";
    }
    cout<<endl;
 
}
 
int32_t main(){
 
    init_code();
 
    solve();        
 
    return 0;
}
