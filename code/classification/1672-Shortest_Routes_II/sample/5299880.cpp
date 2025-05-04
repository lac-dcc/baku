#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define int long long
#define vii vector<int>
#define pii pair<int,int>
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N = 501;
int dist[N][N];
int n,m,q;
 
int32_t main()
{
    FAST;
    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            if(i!=j)dist[i][j] = LLONG_MAX;
            else dist[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        int l,r,w;
        cin>>l>>r>>w;
        dist[l][r] = min(dist[l][r],w);
        dist[r][l] = min(dist[r][l],w);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]<LLONG_MAX && dist[k][j]<LLONG_MAX)
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i=0;i<q;i++){
        int u,v;cin>>u>>v;
        if(dist[u][v]==LLONG_MAX)cout<<-1<<endl;
        else cout<<dist[u][v]<<endl;
    }
    return 0;
}
