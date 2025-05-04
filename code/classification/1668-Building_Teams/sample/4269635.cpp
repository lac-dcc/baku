#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5 + 1 ;
vector<int> adj[N] , vis(N) , col(N);
 
bool dfs(int node , int c){
	 vis[node] = 1 ;
	 col[node] = c ;
	 for(auto  x: adj[node]){
	 	  if(!vis[x]){
	 	      if(dfs(x , c^1) == 0){
	 	      	   return  0;
			   }	  
		   }
		   else {
		   	   if(col[x] == c)
		   	   return  0;
		   }
	 }
	 return 1 ;
}
 
signed main(){
   int n , m ; 
   cin >> n >> m ;
   for(int i = 0 ; i < m ; i++){
   	    int a , b ;
   	    cin >> a >> b ;
   	    adj[a].push_back(b);
   	    adj[b].push_back(a);
   }
   for(int i =  1 ; i <=  n ; i++){
   	    if(!vis[i]){
   	       int ans = dfs(i , 0);
		   if(!ans){
		   	  cout << "IMPOSSIBLE" << endl;
		   	  return  0;
		   }	
		}
   }
   for(int i = 1 ; i <=  n ; i++){
   	    if(col[i] == 0){
   	        col[i] = 2 ;	
		}
   }
   for(int i = 1 ; i <=  n ; i++) cout << col[i] << " ";
   cout << endl;
}
