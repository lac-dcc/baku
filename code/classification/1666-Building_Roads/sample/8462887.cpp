#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
// Return a list of nodes, s.t every node partains to a different component,
// and every component in the graph has a node in this list.
vector<size_t> find_component_roots(const vector<vector<int>>& graph)
{
    const size_t n = graph.size();
    vector<bool> visited(n, false);
    vector<size_t> component_roots;
    
    for (size_t node = 0; node < n; ++node)
    {
        if (!visited[node])
        {
            component_roots.push_back(node);
            
            // Perform BFS to mark all the reachable nodes.
            visited[node] = true;
            queue<size_t> q{{node}};
            
            while (!q.empty())
            {
                const size_t current_node = q.front();
                q.pop();
                
                for (const size_t neighbor : graph[current_node])
                {
                    if (!visited[neighbor])
                    {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    
    return component_roots;
}
 
int main()
{
    // Number of nodes
    const size_t n = [] ()
    {
        size_t n;
        cin >> n;
        
        return n;
    }();
    
    // Build a 0-indexed graph
    const vector<vector<int>> graph = [n] ()
    {
        size_t m; // number of edges;
        cin >> m;
        
        vector<vector<int>> graph(n);
        
        for (size_t i = 0; i < m; ++i)
        {
            size_t a;
            size_t b;
            cin >> a >> b;
            
            // 0-index the input
            graph[a - 1].push_back(b - 1);
            graph[b - 1].push_back(a - 1);
        }
        
        return graph;
    }();
    
    const vector<size_t> component_roots = find_component_roots(graph);
    const size_t num_of_components = component_roots.size();
    
    // Print the output
    cout << num_of_components - 1 << "\n";
 
    for (size_t i = 1; i < num_of_components; ++i)
    {
        cout << component_roots[i - 1] + 1 << " " << component_roots[i] + 1 << "\n";
    }
 
    return EXIT_SUCCESS;
}
