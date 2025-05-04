#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> g;
vector<bool> check;
void dfs(int cur){
    if (check[cur]) return ;
    check[cur] = 1;
    for(int nei:g[cur]){
        dfs(nei);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    g.resize(n);
    //  g[i] -> vector of all neigboghrs of i
    for(int i=0; i<m;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    check.resize(n,0);
    vector<int> vec;
    for(int i=0; i<n; i++){
        if (!check[i]){
            dfs(i);
            vec.push_back(i);
        }
    }
    cout<<vec.size()-1<<endl;
    for(int i=0; i<vec.size()-1; i++) {
        cout<<vec[i]+1<<" "<<vec[i+1]+1<<endl;
    }
    return 0;
}
/*
color a
cls
g++ g.cpp -o b & b
4 2
1 2
3 4
 
*/
