#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 +10;
const long long int INF = 2e15+10;
 
long long int dist[N][N];
 
 
int main(){
 
   for(int i=0; i<N; i++){
      for(int j=0; j<N; j++){
         if(i==j){
            dist[i][j] = 0;
         }else{
            dist[i][j] = INF;
         }
      }
   }
 
   long long int n,m,q;
   cin>>n>>m>>q;
   for(long long int i=1; i<=m; i++){
      long long int x,y,wt;
      cin>>x>>y>>wt;
      if(dist[x][y]>= wt){
         dist[x][y] = wt;
      }
      if(dist[y][x]>= wt){
         dist[y][x] = wt;
      }
   }
   
 
   for(int k=1; k<=n; k++){
      for(int i=1; i<=n; i++){
         for(int j=1; j<=n; j++){
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
         }
      }
   }
   for(int i=1; i<=q; i++){
      int x,y;
      cin>>x>>y;
      if(dist[x][y] == INF){
         cout<<"-1\n";
      }else{
         cout<<dist[x][y]<<endl;
      }
   }
 
   return 0;
}
