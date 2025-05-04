#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
#define pb push_back
 
const int nm = 1e5 + 10;
int n, m, ans, rep[nm];
vi ab[nm];
bool visited[nm];
 
void dfs (int node){
    visited[node] = true;
    for(int i : ab[node]){
        if (!visited[i])
        dfs(i);
    }
} 
 
int count_components(){
    int count = 0; 
    for (int i =1; i <= n; i++){
        if(!visited[i]){
            rep[count++]=i;
            dfs(i);
        } 
    }
    return count;
}
 
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; i ++){
        int a, b; cin >> a >> b;
        ab[a].pb(b); ab[b].pb(a);
    }
    ans = count_components();
    cout << ans-1 << endl;
    for (int i = 1; i <= ans; i++){
        cout << rep[i-1] << " "<< rep[i] << endl;
    }
}
