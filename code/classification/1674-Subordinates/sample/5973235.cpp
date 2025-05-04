#include<bits/stdc++.h>
 
using namespace std;
 
map<int, vector<int>> tree;
vector<int> sub;
 
 
void dfs (int root) {
    if (tree[root].empty())
        return;
        
    sub[root] = 0;
    for (int children : tree[root]) {
        dfs(children);
        sub[root] += 1 + sub[children];
    }
    
}
 
int main()
{
    int n;
    cin >> n;
    
    sub.resize(n);   
    vector<int> par(n);
    par[0] = -1;
    for (int i = 1; i < n; i++) {
        cin >> par[i];
        par[i]--;
    }
    for (int i = 0; i < n; i++) {
        tree[par[i]].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
        cout << sub[i] << " ";
        
    return 0;
}
