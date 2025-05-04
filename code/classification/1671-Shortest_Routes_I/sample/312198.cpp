#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18;
typedef pair<long long, long long> ii;
vector <ii> a[200001];
long long n, m;
long long d[200001];
void dijkstra(){
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    long long i, u, v, du, uv;
    for (i=1; i<=n; i++) d[i] = oo;
    d[1] = 0;
    pq.push(ii(0, 1));
    while (pq.size()){
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;
        for (i=0; v=a[u][i].second; i++){
            uv=a[u][i].first;
            if (d[v]>du+uv) {
                d[v]=du+uv;
                pq.push(ii(d[v], v));
            }
        }
    }
 
}
int main(){
    long long p, q, i, m, w;
    cin>>n>>m;
    while (m--){
        cin>>p>>q>>w;
        a[p].push_back(ii(w, q));
    }
    for (i=1; i<=n; i++) a[i].push_back(ii(0,0));
    dijkstra();
    for (i=1; i<=n; i++) cout<<d[i]<<" ";
}
