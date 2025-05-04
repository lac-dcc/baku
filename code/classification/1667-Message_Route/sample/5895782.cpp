#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long n;
    long long m;
    cin >> n >> m;
    vector <vector <long long>> grafo(n);
 
    for(long long i = 0; i < m; i++){
        long long a,b;
 
        cin >> a >> b;
 
        grafo[a-1].push_back(b-1);
        grafo[b-1].push_back(a-1);
    }
 
    vector<long long> dist(n,-1);
    vector<long long> parent(n,-1);
 
    queue <long long> q;
    dist[0] = 0;
    q.push(0);
    while(!q.empty()){
        long long u = q.front();
        q.pop();
 
        for( long long v : grafo[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
 
    if( dist[n-1] == -1){
        cout << "IMPOSSIBLE";
        return 0;
    }
 
 
    cout << dist[n-1]+1 << '\n';
 
    stack <long long> s;
    long long nodo = n-1;
    while(nodo != 0){
        s.push(nodo);
        nodo = parent[nodo];
    }
 
    cout << 1 << ' ';
    while(!s.empty()){
        cout << s.top() +1 << ' ';
        s.pop();
    }
    cout << '\n';
 
    return 0;
}
