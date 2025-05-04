/*
 
Input:
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2
 
Output:
YES
1 2 4 1
 
*/
 
 
 
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e7;
long long int visited[N],d[N],parent[N],INF = 1e18; 
vector<pair<int,int>>adjList[N];
 
int main(){
 
    int n,m,a,b,c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        d[i] = INF;
    }
    
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adjList[a].push_back({b,c}); 
    }
    bool negativeCycle = false;
    int lastUpdatedNode = -3; 
    for (int i = 1; i <= n; i++){
        for(int node = 1; node <= n; node++){
            for(auto child: adjList[node]){ 
                int a = node;
                int b = child.first;
                int c = child.second;
                if(d[a]+c < d[b]){
                    d[b] = d[a]+c;
                    parent[b] = a;
                    if(i == n){
                        negativeCycle = true;
                        lastUpdatedNode = b;
                    }
                }  
            }
        }
    }
 
    if(negativeCycle){
        cout << "YES\n";
        int selectedNode = lastUpdatedNode;
        for (int i = 1; i < n; i++){
            selectedNode = parent[selectedNode];
        }
        int firstNode = selectedNode;
        vector<int> cycle;
        cycle.push_back(selectedNode);
        while (true){
            selectedNode = parent[selectedNode];
            cycle.push_back(selectedNode);
            if(selectedNode == firstNode) break;
        }
        reverse(cycle.begin(), cycle.end());
        for (auto node : cycle){ 
            cout << node << " ";
        }
        
    } 
    else{ 
        cout << "NO\n";
    }
    
 
    
 
 
}
