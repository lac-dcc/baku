#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
vector<bool> visited;
 
vector<ll> Dijkstra(int a, vector<vector<pair<int, int>>> ady){
    priority_queue<pair<ll, int>> pq;
    vector<ll> dist(ady.size(), 1LL<<60);
    vector<bool> visited(ady.size(), false);
    dist[a]=0;
    pq.push({0, a});
    while(pq.size()){
        int nodo=pq.top().second;
        pq.pop();
        if(visited[nodo]){
            continue;
        }
        visited[nodo]=true;
        for(auto par:ady[nodo]){
            int vecino=par.first;
            int costo=par.second;
            if(dist[vecino]>dist[nodo]+costo){
                dist[vecino]=dist[nodo]+costo;
                pq.push({-dist[vecino], vecino});
            }
        }
    }
    return dist;
}
 
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<pair<int, int>>> lista1(n+1), lista2(n+1);
    vector<vector<int>> aristas(m+1);
    for(int i=0; i<m; ++i){
        int a, b, c; cin>>a>>b>>c;
        lista1[a].push_back({b, c});
        lista2[b].push_back({a, c});
        aristas[i]={a, b, c};
    }
    auto d1=Dijkstra(1, lista1);
    auto d2=Dijkstra(n, lista2);
    ll MinViaje=1LL<<60;
    for(int i=0; i<m; ++i){
        MinViaje=min(MinViaje, d1[aristas[i][0]]+aristas[i][2]/2+d2[aristas[i][1]]);
    }
    cout<<MinViaje<<endl;
}
