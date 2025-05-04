#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
#define INF 1000000000000000000
int main(){
 
ll n,m,q;
cin>>n>>m>>q;
ll graph[n+1][n+1];
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		if(i==j)
		graph[i][j]=0;
		else
		graph[i][j]=INF;
	}
}
for(int i=0;i<m;i++){
	ll a,b,c;
	cin>>a>>b>>c;
	if(graph[a][b]>c){
	
	graph[a][b]=c;
	graph[b][a]=c;
}	
	}
	
	ll mat[n+1][n+1];
	  for (int i = 1; i <= n; i++)
    for (int j = 1; j <=n; j++)
      mat[i][j] = graph[i][j];
 
  
  for (int k = 1; k <=n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <=n; j++) {
        if (mat[i][k] + mat[k][j] < mat[i][j])
          mat[i][j] = mat[i][k] + mat[k][j];
      }
    }
  }
	
	
	
	
	
	for(int i=0;i<q;i++){
		ll a,b;
		cin>>a>>b;
		if(mat[a][b]!=INF)
		cout<<mat[a][b]<<endl;
		else cout<<-1<<endl;
	}
 
 
 
return 0;}
 
