#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> adj[200010];
vector<int> weight[200010];
long long int dist[200010];
set<pair<long long int, int> > s;
int n, m;
 
void dj(int v){
    for(int i=0;i<=2*n;i++) dist[i] = 9223372036854775807;
    s.insert({0, v});
    dist[v] = 0;
    while(!s.empty()){
        int cur = (*s.begin()).second;
        s.erase(s.begin());
        for(int i=0;i<(int)adj[cur].size();i++){
            int viz = adj[cur][i];
            int w = weight[cur][i];
            if(dist[viz] > dist[cur] + w){
                s.erase({dist[viz], viz});
                dist[viz] = dist[cur] + w;
                s.insert({dist[viz], viz});
            }
        }
    }
}
 
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        adj[(2*a)-2].push_back((2*b)-2);
        weight[(2*a)-2].push_back(c);
        adj[(2*a)-2].push_back((2*b)-1);
        weight[(2*a)-2].push_back(c/2);
        adj[(2*a)-1].push_back((2*b)-1);
        weight[(2*a)-1].push_back(c);
    }
    dj(0);
    printf("%lld\n", dist[(2*n)-1]);
    
    return 0;
}
