// https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(int i=a;i<=b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)
#define iter_all(el, cont) for(auto &el:cont)
 
void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}
 
void file_i_o() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
std::vector<ll> dp;
ll findCoins(ll amt, std::vector<ll> &coins){
    if(amt == 0){
        return dp[amt] = 0;
    }
 
    if(dp[amt] != -1) return dp[amt];
 
    ll ans = INT_MAX;
    for(auto &el:coins){
        if(amt-el<0) continue;
        ans = std::min(ans, 1+findCoins(amt-el, coins));
    }
 
    if(ans == INT_MAX) return dp[amt] = INT_MAX;
    return dp[amt] = ans;
}
 
int main(int argc, char const *argv[]) {
    file_i_o();
    clock_t begin = clock();
    // Write your code here....
 
    ll n, x;
    std::cin>>n>>x;
    std::vector<ll> coins(n);
    for(int i=0;i<n;i++) std::cin>>coins[i];
 
    dp.resize(x+1, -1);
 
    ll ans = findCoins(x, coins);
    if(ans == INT_MAX) ans = -1;
    std::cout<<ans;
 
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
