#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    int n ,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<vector<pair<int,int>>> tmp(n+1);
    int u,v,w;
    for(int i =0;i<m;i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        tmp[u].push_back({v,w/2});
    }
 
    vector<vector<long long>> dis(n+1,vector<long long>(2,1e15));
    set<pair<pair<long long,int>,int>> st;
    st.insert({{0,1},0});
    dis[1][0] = 0;
    dis[1][1] = 0;
    while(!st.empty()){
        auto nd = *(st.begin());
        st.erase(nd);
        if(nd.first.second==n && nd.second==1) {
            cout<<dis[n][1];
            return 0;
        }
 
        if(nd.second==0){
            for (auto i : tmp[nd.first.second]){
            
                if( i.second + nd.first.first < dis[i.first][1]){
 
                    if(dis[i.first][1]!=1e15){
                        if(st.find({{dis[i.first][1],i.first},1})!=st.end())
                        st.erase({{dis[i.first][1],i.first},1});
                    }
 
                    dis[i.first][1] = (long long)i.second + nd.first.first;
                    st.insert({{dis[i.first][1],i.first},1});
                }            
            }
            for (auto i : adj[nd.first.second]){
            
                if( i.second + nd.first.first < dis[i.first][0]){
 
                    if(dis[i.first][0]!=1e15){
                        if(st.find({{dis[i.first][0],i.first},nd.second})!=st.end())
                        st.erase({{dis[i.first][0],i.first},nd.second});
                    }
 
                    dis[i.first][0] = (long long)i.second + nd.first.first;
                    st.insert({{dis[i.first][0],i.first},nd.second});
                }            
        }
        } else {
            for (auto i : adj[nd.first.second]){
            
                if( i.second + nd.first.first < dis[i.first][1]){
 
                    if(dis[i.first][1]!=1e15){
                        if(st.find({{dis[i.first][1],i.first},nd.second})!=st.end())
                        st.erase({{dis[i.first][1],i.first},nd.second});
                    }
 
                    dis[i.first][1] = (long long)i.second + nd.first.first;
                    st.insert({{dis[i.first][1],i.first},nd.second});
                }            
        }
        }    
    };
}
