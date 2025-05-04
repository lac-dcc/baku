#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define float double
 
int n, m, Q;
vector<pair<ll, ll>>adj[510];
vector<ll>np[510];
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<510;i++)np[i].resize(510, 2e14);
    cin>>n>>m>>Q;
    for(int i=0;i<m;i++){
        ll a, b, c;cin>>a>>b>>c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        np[a][b] = np[b][a] = min(np[b][a], c);
    }
 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=j+1; k<=n;k++){
                if(np[j][k]>np[j][i]+np[i][k]){
                    np[j][k]=np[k][j]=np[j][i]+np[i][k];
                }
            }
        }
    }
 
    while(Q--){
        int a, b;cin>>a>>b;
        if(a==b)cout<<0<<endl;
        else if(np[a][b]==2e14)cout<<-1<<endl;
        else cout<<np[a][b]<<endl;
    }
 
    return 0;
}
