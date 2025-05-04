#include <bits/stdc++.h>
using namespace std;
 
class Graph
{
public:
    unordered_map<int, list<int>> l;
 
public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
 
     vector<int> bfs(int src, unordered_map<int, bool> &visited,unordered_map<int,int>&dist,int n)
    {
        unordered_map<int,int> parent;
        vector<int>ans;
        queue<int> q;
        q.push(src);
        for(auto x:dist){
            x.second=INT_MAX;
        }
        dist[src]=0;
        visited[src]=true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto nbr : l[node])
            {
              
                if (!visited[nbr])
                {   
 
                    if(nbr==n){
                        parent[nbr] = node;
                        dist[nbr] = dist[node] + 1;
                        int end=n;
                        while (1)
                        {
                            ans.push_back(end);
                            end=parent[end];
                            if(end==1){
                                break;
                            }
 
                            
                        }
                        ans.push_back(1);
 
                        return ans;
                    }
                    parent[nbr]=node;
                    dist[nbr]=dist[node]+1;
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
      
        return ans;
    }
};
int main()
{
    Graph g;
    unordered_map<int, bool> visited;
    unordered_map<int, int> dist;
 
    vector<int> arr;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
   
       
        vector<int> v=g.bfs(1, visited,dist,n);
        if(v.size()>0){
            cout << dist[n] + 1 << endl;
            reverse(v.begin(), v.end());
            for (auto x : v)
            {
                cout << x << " ";
            }
        }else{
            cout << "IMPOSSIBLE";
        }
    
   
    return 0;
}


