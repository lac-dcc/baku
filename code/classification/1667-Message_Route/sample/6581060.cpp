#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF (int)1e9
int n;
vector <int> from(100001);
int bfs(int x,vector <int> &visited,vector <vector <int>> &v,vector <int> &distance ){
    queue <int> q;
    q.push(x);
    visited[x]=1;
    while(!(q.empty())){
        x=q.front();q.pop();
        if(x==n) return 1;
        for(auto u:v[x]){
            if(visited[u]) continue;
            visited[u]=true;
            distance[u]=distance[x]+1;
            from[u]=x;
            q.push(u);
        }
    }
    return 0;
}
 
void solve() {
    int m,x,y,i;
    cin>>n>>m;
    vector <vector <int>> v(n+1);
    vector <int> visited(n+1,0),distance(n+1,0),route;
    distance[1]=1;
    while(m--){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(bfs(1,visited,v,distance))
    {   
        x=n;
        route.push_back(n);
        while(x!=1){
            route.push_back(from[x]);
            x=from[x];
        }
        reverse(route.begin(),route.end());
        cout<<distance[n]<<endl;
        for(auto i:route) cout<<i<<" ";
    }
    else cout<<"IMPOSSIBLE"<<endl;
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}