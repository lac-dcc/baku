#include<bits/stdc++.h>
using namespace std;
 
long long int n,m;
const long long int INF = 9e17;
vector<vector<pair<long long int,long long int>>>  g;
vector<long long int> cost;
vector<long long int> disc;
 
void dijkstra(){
    	priority_queue<pair<long long int, pair<long long int,long long int>> , vector< pair<long long int, pair<long long int,long long int>>> ,greater<pair<long long int,pair<long long int,long long int>>>> pq; 
    	
    	for(long long int i = 2 ; i<=n ; i++){
    	cost[i] = INF;
    	disc[i] = INF;
    }
    pq.push({0,{1,0}});
    
    while(!pq.empty()){
    	long long int d = pq.top().first;
    	long long int u = pq.top().second.first;
    	long long int f = pq.top().second.second;
    	pq.pop();
    
    	if(f==1){
    	if(disc[u] <d) continue;
    }
    if(f == 0){
    	if(cost[u] < d) continue;
    }
    
    for(auto e: g[u]){
    	long long int v = e.first ;
    long long int c = e.second;
    if(f==0){
    	if(cost[v] > c+d){
    	cost[v] = c+d;
    	pq.push({cost[v],{v,0}});
    }
    if(disc[v] > d + c/2){
    	disc[v] = d+c/2;
    	pq.push({disc[v] , {v,1}});
    }
    }
    if(f==1){
    	if(disc[v] > d+c){
    	disc[v] = d+c;
    	pq.push({disc[v],{v,1}});
    }
    } 
    }
    } 
    cout<<disc[n]<<endl;
}
 
int main(){
	cin>>n>>m;
	
	g.resize(n+1);
	cost.resize(n+1);
	disc.resize(n+1);
	
	long long int a,b; 
    long long int c;
	for(long long int i = 0 ; i<m ; i++){
    	cin>>a>>b>>c;
    	g[a].push_back({b,c});
    }
 
    dijkstra();
	return 0;
}
 
