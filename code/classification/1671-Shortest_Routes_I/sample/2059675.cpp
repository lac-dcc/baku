#include <bits/stdc++.h>
#define int long long
using namespace std;
 
struct Graph {
    int n, m;
    vector<vector<int> > adj_list, cost;
    Graph(int v, int e) {
        n = v, m = e;
        adj_list = vector<vector<int> > (n);
        cost = vector<vector<int> > (n);
    }
 
    void add_edges(int u, int v, int c) {
        adj_list[u].push_back(v);
        cost[u].push_back(c);
    }
    void print_graph(){
        bool f=false;
        for(int i=0;i<adj_list.size();i++)
        {
            if(adj_list[i].size()==0) continue;
            cout<<"Vertex "<<i<<" --> ";
            for(int j=0;j<adj_list[i].size();j++)
            {
                cout<<adj_list[i][j]<<" cost "<<cost[i][j]<<" , ";
            }
            cout<<endl;
        }
    }
 
    //Optimised function with time complexity O(V+ E*log(V))
    void dijkstra(int root){
        int parent[n],value[n];
        bool visited[n];
 
        set<pair<int,int> > pqueue;
 
        for(int i=0;i<n;i++){
            parent[i] = -1;
            value[i] = LLONG_MAX;
            if(i!=root) pqueue.insert(make_pair(LLONG_MAX,i));
            else pqueue.insert(make_pair(0,i));
            visited[i] = false;
        }
 
        value[root] = 0;
        parent[root] = root;
        while(!pqueue.empty())
        {
            set<pair<int,int> > :: iterator it1 = pqueue.begin();
 
            int ele = (*it1).second;
            visited[ele] = true;
 
            for(int i=0; i<adj_list[ele].size(); i++)
            {
                if(visited[adj_list[ele][i]] == false && (value[ele] + cost[ele][i] < value[adj_list[ele][i]])){
 
                    pair<int,int> p = make_pair(value[adj_list[ele][i]],adj_list[ele][i]);
                    set<pair<int,int> > :: iterator it = pqueue.find(p);
                    pqueue.erase(it);
                    value[adj_list[ele][i]] = value[ele] + cost[ele][i];
                    pqueue.insert(make_pair(value[adj_list[ele][i]],adj_list[ele][i]));
                    parent[adj_list[ele][i]] = ele;
                }
            }
            pqueue.erase(it1);
        }
 
 
        // cout<<"\nFor root = "<<root<<" GRAPH\n\n";
        // for(int i=0; i<n; i++){
        //     if(i!=root) cout<<parent[i]<<" --> "<< i <<endl;
        // }
 
        //cout<<"\nFrom root = "<<root<<" to \n\n";
        for(int i=0; i<n; i++){
            cout<<value[i]<<" ";
        }
 
        // cout<<"\nFor root = "<<root<<endl<<endl;
        // for(int i=0;i<n;i++){
        //     if(i!=root){
        //         stack<int> st;
        //         st.push(i);
        //         int k=i;
        //         while(parent[k]!=root){
        //             st.push(parent[k]);
        //             k = parent[k];
        //         }
        //         cout<<"Shortest Path to node "<< i<<" from " <<root<<" : ";
        //         while(!st.empty()){
        //             cout<<"-->"<<st.top();
        //             st.pop();
        //         }
        //         cout<<endl;
        //     }
        // }
        // cout<<"------------------------------------------------------"<<endl;
    }
 
};
 
signed main(){
 
	///*
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr); 
    #endif
    //*/
 
    int n, m;  cin >> n >> m;
    Graph g(n, m);
    for (int i = 0; i < m; i++) {
       int u, v, c;   cin >> u >> v >> c;
       u--; v--;
       g.add_edges(u, v, c);
    }
    //g.print_graph();
    int source=0;
    g.dijkstra(source);
    //for(int i=0;i<n;i++) g.dijkstra(i);
 
}
 
/*
6 10
0 1 1
0 2 4
1 2 4
1 3 2
1 4 7
2 3 3
2 4 5
3 4 4
3 5 6
4 5 7
0
*/
