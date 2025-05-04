#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        200001
 
 
const int INF = 1e18;
int graph[505][505];
 
void solve(int n,int q){
    int dist[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
 
            if(graph[i][j]!=-1)
                dist[i][j]=graph[i][j];
            else if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=INF;
        }
    }
 
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
 
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if( dist[i][k]+ dist[k][j] < dist[i][j] )
                    dist[i][j] = dist[i][k]+ dist[k][j];
            }
        }
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           if(dist[i][j] == INF){
                dist[i][j]=-1;
           }
           if(i==j){
                dist[i][j]=0;
           }
        }
    }
    int a,b;
    while(q--){
        cin>>a>>b;
        cout<<dist[a][b]<<endl;
    }
}
 
int32_t main()
{
 
    fast;
    memset(graph,-1,sizeof(graph));
    int n,m,q;
    cin>>n>>m>>q;
    int a,b,c;
    while(m--){
        cin>>a>>b>>c;
        if(graph[a][b] != -1){
            if(graph[a][b] < c)
                continue;
        }
        graph[a][b]=c;
        graph[b][a]=c;
    }
 
    solve(n,q);
    return 0;
}
