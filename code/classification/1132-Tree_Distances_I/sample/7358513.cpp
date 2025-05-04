#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> g;
vector<int> in,out;
 
void dfs(int u,int par) {
    
    in[u] = 0;
    for(auto &cur:g[u]) {
         
         if(cur != par) {
            dfs(cur,u);
            in[u] = max(in[u],in[cur]+1);
         }
    }
}
 
void dfs1(int u,int par) {
     
     int mx1 = -1 , mx2 = -1;
 
     for(auto cur:g[u]) {
         if(cur!=par) {
            if(in[cur] >= mx1) {
                mx2 = mx1;
                mx1 = in[cur];
            }
            else if(in[cur] > mx2) {
                mx2 = in[cur];
            }
         }
     }
 
     for(auto cur : g[u]) {
		if( cur == par) continue;
		int longs = mx1;
 
		if(mx1  == in[cur]) {
			longs = mx2;
		}
 
		out[cur] = 1 + max(out[u], 1 + longs);
		dfs1(cur, u);
	}
}
 
int main() {
   
   int n;
   cin>>n;
   
   g.resize(n+1);
   in.resize(n+1);
   out.resize(n+1);
 
   for(int i=0;i<n-1;i++) {
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
   }
   
   dfs(1,0);
   dfs1(1,0);
 
   for(int i=1;i<=n;i++) {
    cout<<max(in[i],out[i])<<" ";
   }
   cout<<"\n";
 
 
}
