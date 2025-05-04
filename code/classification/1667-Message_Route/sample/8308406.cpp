# include <bits/stdc++.h>
using namespace std;
# define so 100010
vector <bool> dd(so,1);
vector <int> ke[so], tr(so,0);
int n, m;
void BFS(int u1){
    queue <int> q;
    q.push(u1);
    while (!q.empty()){
        int u=q.front(); q.pop();
        dd[u]=0;
        if (u==n) break;
        for (auto it:ke[u])
            if (dd[it]){
                tr[it]=u;
                dd[it]=0;
                q.push(it);
            }
    }
}
int main(){
    //ifstream cin ("a.inp");
    cin >> n >> m;
    for (int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    BFS(1);
    if (tr[n]==0)
        cout << "IMPOSSIBLE";
    else{
        vector <int> a;
        int u=n;
        while (u!=1){
            //cout << u <<" ";
            a.push_back(u);
            u=tr[u];
        }
        a.push_back(1);
        cout << a.size() << endl;
        for (int i=a.size()-1; i>=0; i--)
            cout << a[i] <<" ";
    }
 
}
