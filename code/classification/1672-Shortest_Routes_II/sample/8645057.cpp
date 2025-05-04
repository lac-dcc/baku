#include<bits/stdc++.h>
using namespace std;
 
#define bella cin.tie(0)->sync_with_stdio(0);
typedef long long ll;
const ll INF=1LL<<60;
ll dis[505][505];
int main(){
    bella
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)    dis[i][j]=INF;
        }
    }
    while(m--){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        dis[a][b]=dis[b][a]=min({dis[a][b],dis[b][a],c});
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)   dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dis[a][b]==INF)  cout<<"-1\n";
        else    cout<<dis[a][b]<<"\n";
    }
    return 0;
}
