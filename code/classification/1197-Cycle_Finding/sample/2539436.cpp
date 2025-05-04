#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n,m;
vector<int> cycle;
bool isNegativeCycle(vector<array<int,3>> &graph,vector<lli> distance,vector<bool> &VISITED){
    vector<int> parent(n+1,-1);
    int end = -1;
    for(int i=1;i<=n;i++){
        for(auto e : graph){
            int a = e[0];
            int b = e[1];
            int w = e[2];
            if(distance[a]!=INT64_MAX && distance[a] + w < distance[b]){
                distance[b] = distance[a] + w;
                parent[b] = a;
                VISITED[b] = true;
                if(i == n){
                    end = b;
                    for(int j=0;j<n;j++)
                        end = parent[end];
                    for(int k=end;;k=parent[k]){
                        cycle.push_back(k);
                        if(k == end && cycle.size()>1)
                            return true;        
                    }
                    return true;
                }
                    
            }
        }
    }
    cycle.clear();
    return false;
 
}
 
int main(){
    cin>>n>>m;
    vector<array<int,3>> edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i][0];
        cin>>edges[i][1];
        cin>>edges[i][2];
    }
    vector<lli> distance(n+1,0);
    vector<bool> VISITED(n+1,false);
    int node = 1;
    //for(int node=1;node<n+1;node++){
        if(!VISITED[node]){
            distance[node] = 0;
            VISITED[node] = true;
            if(isNegativeCycle(edges,distance,VISITED)){
                cout<<"YES\n";
                reverse(cycle.begin(), cycle.end());
                for(int i : cycle)
                    cout<<i<<" ";
                return 0;
            }
      //      fill(distance.begin(),distance.end(),INT64_MAX);
        }
    //}
    
    cout<<"NO";
    return 0;
}
