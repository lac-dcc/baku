#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp(int x, vector<int>& cache, vector<int>& denominations){
    if(cache[x] != -1) return cache[x];
    if(x == 0) return 0;
    int running_min = 1000000000;
    for(int i = denominations.size()-1; i>=0; --i){
        if(x - denominations[i] < 0) continue;
        running_min = min(running_min, 1 + dp(x - denominations[i], cache,denominations));
    }
    return cache[x] = running_min;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> coins(n, 0);
    for(int i=0; i<n; ++i){
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end());
    vector<int> c(x+1, -1);
    int answer = dp(x, c, coins);
    cout<<(answer == 1000000000?-1:answer)<<'\n';
}