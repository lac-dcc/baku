#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
 
typedef vector<long long> vi;
 
int expo(long long n){
    long long result=1,p=2;
    while(n>0){
        if(n%2==1) result = (result*p)%mod;
        p=(p*p)%mod;
        n/=2;
    }
    return result;
}
 
vector<int> adj[100005];
int vis[100005],c[100005];
 
bool bfs(int n){
    queue<int> q;
    c[n]=0;
    q.push(n);
    while(!q.empty()){
        n = q.front();
        q.pop();
        vis[n]=1;
        for(int i=0;i<adj[n].size();i++){
            if(c[adj[n][i]]==-1) c[adj[n][i]]=!c[n];
            else if(c[adj[n][i]]==c[n]) return false;
            if(vis[adj[n][i]]==0) q.push(adj[n][i]);
        }
    }
    return true;
 
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    //cin>>t;
    t=1;
    while(t--){
        int n,m,x,y;
        cin>>n>>m;
        for(int i=0;i<=n;i++) c[i]=-1;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0) {
                bool ans = bfs(i);
                if(!ans) {cout<<"IMPOSSIBLE"; return 0;}
            }
        }
        //cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            if(c[i]==0) cout<<2<<" ";
            else cout<<1<<" ";
        }
 
    }
}
