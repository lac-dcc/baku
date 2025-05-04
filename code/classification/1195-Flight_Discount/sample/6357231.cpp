#include<bits/stdc++.h>
using namespace std;
 
long long int dijkstra(long long int n,long long int m,vector<pair<long long int, long long int>>adj[],long long int S){
    priority_queue<pair<long long int,pair<long long int,long long int>>,vector<pair<long long int,pair<long long int,long long int>>>,greater<pair<long long int,pair<long long int,long long int>>>> pq; 
    vector< long long int> discount(n);
    vector< long long int> disused(n);
    discount[S]=0;
    disused[S]=0;
    for( int i=0;i<n;i++){
        if(i!= S) {discount[i]=1e15;disused[i]=1e15;}
    }
    pq.push(make_pair(0,make_pair(S,0)));
    while(!pq.empty()){
        long long int dis=pq.top().first;
        long long int node=pq.top().second.first;
        long long int use=pq.top().second.second;
        pq.pop();
        if(use==1){ if(disused[node]<dis) continue;}
        if(use==0) {if(discount[node]<dis) continue;}
    for(auto i:adj[node]){
        
           if(use==0){
                if(discount[i.first]>dis+i.second){
                    discount[i.first]=dis+i.second;
                    pq.push(make_pair(discount[i.first],make_pair(i.first,0)));}
                if(disused[i.first]>dis+(i.second/2)) {  
                    disused[i.first]=dis+(i.second/2);
                    pq.push(make_pair(disused[i.first],make_pair(i.first,1)));}
            }
            if(use==1) {
                if(disused[i.first]>dis+(i.second)){
                    disused[i.first]=dis+i.second;
                    pq.push(make_pair(disused[i.first],make_pair(i.first,1)));
                        }        }
    }
    }
    return disused[n-1];
}
 
 int main(){
    long long int n,m ;
    cin>>n>>m;
    vector<pair<long long int, long long int>> adj[n];
    for(long long int i=0;i<m;i++){
        long long int a,b;
         long long int c;
        cin>>a>>b>>c;
        adj[a-1].push_back(make_pair(b-1,c));
    }
   cout<<dijkstra(n,m,adj,0);
}
