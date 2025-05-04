/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
 
using namespace std;
 
vector<int> bipartite_graph(vector <vector<int> > G) {
    vector<int> groups(G.size());
    fill(groups.begin(), groups.end(), -1);
    
    unordered_set<int> visited;
    for (int src = 0; src < G.size(); src++) {
        if (visited.find(src) != visited.end()) {
            continue;
        }
        
        queue<int> q;
        q.push(src);
        groups[src] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int next_group = (groups[node] + 1) % 2;
            for (auto x: G[node]) {
                if (visited.find(x) == visited.end()) {
                    q.push(x);
                    groups[x] = next_group;
                    visited.insert(x);
                }
                else if (groups[node] == groups[x]) {
                    return vector<int>();
                }
            }
            
        }
    }
    return groups;
}
 
int main()
{
    int N, M, n1, n2;
    cin >> N >> M;
    vector< vector<int> > G(N);
    for (int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        G[n1 - 1].push_back(n2 - 1);
        G[n2 - 1].push_back(n1 - 1);
    }
    
    vector<int> groups = bipartite_graph(G);
    
    if (groups.empty()) {
        cout << "IMPOSSIBLE";
    }
    else {
        for (auto x: groups) {
            cout << x + 1<< " ";
        }
    }
 
    return 0;
}