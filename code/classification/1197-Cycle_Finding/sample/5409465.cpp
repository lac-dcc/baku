#include<bits/stdc++.h>
using namespace std;
#define Pil pair<int,int>
const int N = 2500+5;
const long long INF = 1e18;
vector<Pil>adj_lst[N];
int parent[N];
long long dist[N];
int n,m;
 
 
 
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj_lst[u].push_back({v,w});
    }
 
    //bellman ford 
    bool negative_cycle=false;
    int last_updated_node=-1;
    for(int i=1;i<=n;i++){
        for(int u=1; u<=n;u++){
            for(Pil ele: adj_lst[u]){
                int v=ele.first;
                int w= ele.second;
                if(dist[u]+w < dist[v]){
                    dist[v]=  dist[u]+w;
                    parent[v]=u;
                    if(i==n){
                        last_updated_node=v;
                        negative_cycle=true;
                    }
                }
            }
        }
    }
 
    if(!negative_cycle){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int selected_node=last_updated_node;
    for(int i=1;i<=n-1;i++){
        selected_node=parent[selected_node];
    }
    int destination_node=selected_node;
    vector<int>path;
    path.push_back(selected_node);
    while(true){
        selected_node = parent[selected_node];
        path.push_back(selected_node);
        if(selected_node==destination_node)break;
    }
    //path printing
    reverse(path.begin(),path.end());
    for(int node: path){
        cout<<node<<" ";
    }
    cout<<endl;
 
    
 
 
}
