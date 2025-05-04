#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
vector<int> grafo[100005];
bool visitado[100005];
vector<int> comp;
 
void bfs(int origen){
    int act, ady, sz;
    queue<int> cola;
 
    cola.push(origen);
    visitado[origen] = true;
 
    while(!cola.empty()){
        act = cola.front();   cola.pop();
        sz = grafo[act].size();
 
        for(int i=0; i<sz; i++){
            ady = grafo[act][i];
            if(!visitado[ady]){
                cola.push(ady);
                visitado[ady] = true;
            }
        }
    }
}
 
int main(){
    //freopen("building.in", "r", stdin);
    //freopen("building.out", "w", stdout);
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int a, b, sz;
 
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        a--; b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        if(!visitado[i]){
            comp.push_back(i);
            bfs(i);
        }
    }
 
    sz = comp.size();
    cout << (sz-1) << "\n";
 
    for(int i=0; i<(sz-1); i++){
        a = comp[i];   b = comp[i+1];
        a++;   b++;
        cout << a << " " << b << "\n";
    }
 
    return 0;
}
