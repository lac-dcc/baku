#include<bits/stdc++.h>
using namespace std;
#define int long long
int inf=1e15;
signed main(){
    int n,m,k;
    cin>>n>>m>>k;
    int dis[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)dis[i][j]==0;
            else dis[i][j]=inf;
        }
    }
    vector<pair<int,int>>graph[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
      dis[a][b]=min(dis[a][b],c);
      dis[b][a]=min(dis[b][a],c);
    }
     for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
             for(int l=1;l<=n;l++){
                 dis[j][l]=min(dis[j][l],dis[j][i]+dis[i][l]);
             }
         }
     }
   /*  for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
             if(dis[i][j]==inf)cout<<"I ";
             else
             cout<<dis[i][j]<<" ";
         }
         cout<<"\n";
     }*/
     while(k--){
         int a,b;
         cin>>a>>b;
         if(dis[a][b]==inf)cout<<-1<<"\n";
         else cout<<dis[a][b]<<"\n";
     }
}
