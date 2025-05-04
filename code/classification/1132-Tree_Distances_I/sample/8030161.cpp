#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> a;
vector<int> dp,ans;
 
void dfs(int node,int parent){
    for(auto z:a[node]){
        if(z==parent)
            continue;
        dfs(z,node);
        dp[node] = max(dp[node],dp[z]+1);
    }
}
 
void cal(int node,int parent,int tot){
    int p = -1,q = -1;
    for(auto z:a[node]){
        if(z==parent)
            continue;
        if(dp[z]>q){
            p = q;
            q = dp[z];
        }else if(dp[z]>p){
            p = dp[z];
        }
    }
    ans[node] = max(dp[node],tot);
    //cout << node << " " << ans[node] << " " << tot << "\n";
    //cout << node << " " << p << " " << q << "\n";
    for(auto z:a[node]){
        if(z==parent)
            continue;
        int l = q;
        if(dp[z]==q)
            l = p;
        //cout << node << " " << z << " " << l << " " << tot << "\n";
        cal(z,node,max(tot+1,l+2));
    }
}
 
int main(){
    int i,x,y,n;
    cin >> n;
    a.resize(n);
    dp.resize(n,0);ans.resize(n,0);
    for(i=1;i<n;i++){
        cin >> x >> y;
        x--;y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(0,-1);cal(0,-1,0);
    for(auto z:ans)
        cout << z << " ";
}
