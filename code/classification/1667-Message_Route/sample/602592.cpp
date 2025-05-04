// C++ program to print DFS traversal for a given given graph 
#include<bits/stdc++.h> 
using namespace std; 
 
long long int pred[100000];
class Graph 
{ 
	long long int V; // No. of vertices 
	vector <long long int> *adj; // Pointer to an array containing adjacency lists 
	void DFSUtil(long long int v, bool visited[]); // A function used by DFS 
public: 
	Graph(long long int V); // Constructor 
	void addEdge(long long int v, long long int w); // function to add an edge to graph 
	long long int minEdgeBFS( long long int u, long long int v, long long int n);
}; 
 
Graph::Graph(long long int V) 
{ 
	this->V = V; 
	adj = new vector<long long int>[V]; 
} 
 
void Graph::addEdge(long long int v, long long int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
	adj[w].push_back(v);
} 
 
 
 
long long int Graph::minEdgeBFS( long long int u, long long int v, long long int n) 
{ 
    // visited[n] for keeping track of visited 
    // node in BFS 
    vector<bool> visited(n, 0); 
  
    // Initialize distances as 0 
    vector<long long int> distance(n, 0); 
    for (long long int i = 0; i < v; i++) { 
        pred[i] = -1; 
    }
    // queue to do BFS. 
    queue <long long int> Q; 
    distance[u] = 0; 
  
    Q.push(u); 
    visited[u] = true; 
    
    while (!Q.empty()) 
    { 
        long long int x = Q.front();
        Q.pop(); 
  
        for (long long int i=0; i<adj[x].size(); i++) 
        { 
            if (visited[adj[x][i]]) 
                continue; 
  
            // update distance for i 
            distance[adj[x][i]] = distance[x] + 1; 
            pred[adj[x][i]] = x;
            Q.push(adj[x][i]); 
            
            visited[adj[x][i]] = 1; 
        } 
    } 
    return distance[v]; 
} 
 
 
int main() 
{ 
	// Create a graph given in the above diagram 
	long long int n,c,u,v;
    cin>>n>>c;
	Graph g(n); 
	for(long long int i=0;i<c;i++){
	    cin>>u>>v;
	    g.addEdge(u-1,v-1);
	}
	long long int value = g.minEdgeBFS(0,n-1,n);
	if(value){
	    cout<<value+1<<endl;
	    vector<int> path; 
        long long int crawl = n-1; 
        path.push_back(crawl); 
        while (pred[crawl] != -1) { 
         path.push_back(pred[crawl]); 
         crawl = pred[crawl]; 
        } 
        for (long long int i = path.size() - 1; i >= 0; i--){
         cout << path[i]+1 << " "; 
         }
	}
	else{
	    cout<<"IMPOSSIBLE";
	}
	
 
	return 0; 
} 
