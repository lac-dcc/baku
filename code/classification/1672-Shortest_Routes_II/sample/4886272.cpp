#include<bits/stdc++.h>
using namespace std;
long long mx=1e14;
#define ll long long int
int main()
{
    long long n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> graph(m,vector<long long> (3));
    for(int i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        graph[i][0]=a;
        graph[i][1]=b;
        
        graph[i][2]=c;
    }
    vector<vector<long long>> query(q,vector<long long> (2));
    for(int i=0;i<q;i++){
        long long a,b;
        cin>>a>>b;
        query[i][0]=a;
        query[i][1]=b;
    }
    vector<vector<ll>>dist(n+1,vector<ll>(n+1,LLONG_MAX));
    for(int i=0;i<m;i++){
        dist[graph[i][0]][graph[i][1]]=min(dist[graph[i][0]][graph[i][1]],graph[i][2]);
        dist[graph[i][1]][graph[i][0]]=dist[graph[i][0]][graph[i][1]];
    }
    for(int i=1;i<=n;i++) dist[i][i]=0;
    for(long long i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dist[i][j]!=LLONG_MAX && dist[i][k]!=LLONG_MAX){
                    dist[j][k]=min(dist[j][k],dist[i][j]+dist[i][k]);
                    dist[k][j]=dist[j][k];
                }
            }
        }
    }
    for(long long i=0;i<q;i++){
        long long u=query[i][0],v=query[i][1];
        if(dist[u][v]==LLONG_MAX) dist[u][v]=-1;
        cout<<dist[u][v]<<endl;
    }
    return 0;
}
