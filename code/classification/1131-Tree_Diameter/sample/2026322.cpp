#include<bits/stdc++.h>
using namespace std;
 
const int maxi= 1e5*2+20;
vector<int > g[maxi];
int n;
bool mark[maxi];
int ans[maxi];
void dfs(int u , int h){
	ans[u] =h;
	mark[u] = 1; 
	for(int i : g[u]){
		if(!mark[i]){
		    
		    h++;
		    dfs(i,h);
		    h--;
		}
	}	
	
}
int main(){
 
	cin  >> n ;
	for(int i =1 ; i < n; i++){
		int u , v ; 
		cin >> u >> v ; u-- ; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0,0);
	int dfsnumber = 0 ; 
      int m = 0 ; 
      
      for(int i = 0 ; i  < n ; i++){
            if(ans[i]>m){
                  m = ans[i];
                  dfsnumber = i ;
            }
            ans[i] = 0 ; 
            mark[i] = 0 ; 
           // cout<<ans[i]<<endl;
      }
      dfs(dfsnumber,0);
      
     // cout<<dfsnumber<<endl;
      for(int i = 0 ; i  < n ; i++){
            if(ans[i]>m){
                  m = ans[i];
            }
         //   cout<<ans[i]<<endl;
      }
      cout<<m<<endl;
}
 
 
