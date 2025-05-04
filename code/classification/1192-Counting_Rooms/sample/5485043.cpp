#include <bits/stdc++.h>
using namespace std; 
 
int main(){
    cin.sync_with_stdio(0); 
    cin.tie(0); 
 
    int N, M; cin>>N>>M; 
    
    vector<vector <int>> graph(N+2, vector<int>(M+2, 1)); 
    vector<pair<int, int>> zero; 
 
    for(int a=1; a<=N; a++){
        for(int b=1; b<=M; b++){
            char x; cin>>x; 
            if(x=='.'){
                graph[a][b]=0;
                zero.push_back({a, b}); 
            }
        }
    }
 
    queue<pair<int, int>> dir; 
    pair<int, int> node; 
    int ans=0; 
    for(pair<int, int> a: zero){
        if(!graph[a.first][a.second]){
            dir.push(a); 
            
            while(dir.size()>0){
                node=dir.front(); dir.pop(); 
 
                if(!graph[node.first+1][node.second]){
                    dir.push({node.first+1, node.second}); 
                    graph[node.first+1][node.second]=1; 
                }
                if(!graph[node.first-1][node.second]){
                    dir.push({node.first-1, node.second}); 
                    graph[node.first-1][node.second]=1; 
                }
                if(!graph[node.first][node.second+1]){
                    dir.push({node.first, node.second+1}); 
                    graph[node.first][node.second+1]=1; 
                }
                if(!graph[node.first][node.second-1]){
                    dir.push({node.first, node.second-1}); 
                    graph[node.first][node.second-1]=1; 
                }
 
            }
            ans++; 
        }
    }
 
    cout<<ans<<endl; 
}
