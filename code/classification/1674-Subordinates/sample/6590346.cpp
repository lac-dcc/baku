#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;
vector<vector<int>> sub(200007);
vector<int> ans(200007, 0);
int solve(int ind){
    for(int x:sub[ind]){
        solve(x);
        ans[ind]+=ans[x]+1;
    }return ans[ind];
}
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=2; i<=n; i++){
        int a;cin>>a;
        sub[a].push_back(i);
    }
    solve(1);
    for(int i=1; i<=n; i++) cout<<ans[i]<<' ';
}
