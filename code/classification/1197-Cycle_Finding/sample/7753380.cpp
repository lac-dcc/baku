#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
 
const int mxn = 2500;
vector<pair<pair<int, int>, ll> > edges;
ll path[mxn+1];
int parent[mxn+1];
 
int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        ll a, b, x;
        cin >> a >> b >> x;
        edges.push_back(make_pair(make_pair(a, b), x));
    }
    path[1] = 0;
    int nodeAfterCycle=0;
    for(int k=1; k<=n+1; k++){
        for(int i=0; i<m; i++){
            ll from = edges[i].first.first, to = edges[i].first.second;
            ll weight = edges[i].second;
            if(path[from] + weight < path[to]){
                path[to] = path[from] + weight;
                parent[to] = from;
                if(k==n) nodeAfterCycle = to;
            }
        }
    }
    if(!nodeAfterCycle){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<int> cycle;
    for(int i=1; i<=n; i++) nodeAfterCycle = parent[nodeAfterCycle];
    int node = nodeAfterCycle;
    while(1){
        cycle.push_back(node);
        if(node == nodeAfterCycle && cycle.size()>1) break;
        node = parent[node];
    }
    reverse(cycle.begin(), cycle.end());
    int l = cycle.size();
    for(int i=0; i<l; i++) cout << cycle[i] << " ";
}
