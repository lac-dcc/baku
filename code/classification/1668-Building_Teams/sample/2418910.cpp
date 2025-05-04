#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define endl '\n';
const double PI = 2 * asin(1);
 
void IO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 
const int N = 1e5 + 1;
int n, m;
vector<int> adj[N];
bool vis[N], c[N];
bool inValid = false;
void dfs(int node, int color) {
    vis[node] = true;
    c[node] = color;
    for (int child : adj[node]) {
        if (vis[child]) {
            if (c[node] == c[child]) inValid = true;
        }else dfs(child, !color);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    for(int i = 1; !inValid && i <= n; i++) {
        if(!vis[i]){
            dfs(i, 1);
        }
    }
    if(inValid){
        puts("IMPOSSIBLE");
        exit(0);
    }
    for (int j = 1; j <= n; j++) {
        if (c[j] == 0) fputs("2 ", stdout);
        else if (c[j] == 1) fputs("1 ", stdout);
    }
}
 
/*
     Do not make STUPID MISTAKES!
     NEVER to assume something not mentioned!
     Thinking Concretely, Symbolically, Pictorically..
     Think in the smallest boundaries (e.g. n = 0, 1, 2 - R*C = {1*1, 1*2, 2*1, 2, 2} - str = "", str = "a", ...)
     Think in the largest boundaries (e.g. n = MAX, array is fully, string has max characters, ...)
     Think in especial cases (array filled with zeros, 1 1 1 1, .....)
     Make sure that you know exactly what is output and its "format"
*/
